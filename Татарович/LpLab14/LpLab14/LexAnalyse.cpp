#include "stdafx.h"
#include "FSA.h"
#include "LexAnalyze.h"
#include "LT.h"
#include "IT.h"
#include "SplitArray.h"
#include "Log.h"

namespace LA
{
	bool CheckExpression(FST::FST fst, LT::LexTable& lextable, char* source, int line, char lexema)  // проверяет цепочку является ли она лексемой и если является заносит в таблицу лексем
	{
		bool rc = false;
		LT::Entry e;
		FST::SetFST(fst, source);
		if (FST::execute(fst))
		{
			e.lexema = lexema;	
			e.idxTI = LT_TI_NULLIDX;
			e.sn = line;
			LT::Add(lextable, e);
			rc = true;
		}
		return rc;
	}

	void LexAn(char* text, Log::LOG log)                  // лексический анализ
	{
		LT::LexTable lextable = LT::Create(LT_MAXSIZE);
		IT::IdTable it = IT::Create(TI_MAXSIZE);
		IT::Entry d;
		char** arr; bool rc = false; int line = 1;
		int i = 0;
		arr = new char*[LT_MAXSIZE];
		for (i = 0; i < LT_MAXSIZE; i++)
		arr[i] = NULL;
		arr = SA::splitArray(text);  // получить массив для построения таблиц идентификаторов и лексем
		i = 0;

		while (arr[i] != NULL)
		{
			if (strcmp(arr[i], "\n") == NULL) line++;
			else
			{
				rc = CheckExpression(FST::declare, lextable, arr[i], line, LEX_DECLARE);
				if (!rc) rc = CheckExpression(FST::main, lextable, arr[i], line, LEX_MAIN);
				if (!rc) rc = CheckExpression(FST::integerdata, lextable, arr[i], line, LEX_INTEGER);
				if (!rc) rc = CheckExpression(FST::stringdata, lextable, arr[i], line, LEX_STRING);
				if (!rc)
				{
					rc = CheckExpression(FST::stringlt, lextable, arr[i], line, LEX_LITERAL);
					if (rc)
					{
						char* cpy = new char[255]; int l = strlen(arr[i]); int pos; int numb = 0; char c[2];
						for (pos = 1; pos < l - 1; pos++)
							cpy[pos - 1] = arr[i][pos];
						cpy[pos - 1] = 0x00;
						memset(d.id, NULL, 5);
						for (pos = 0; pos < lextable.size; pos++)
						{
							if (lextable.table[pos].lexema == LEX_LITERAL) numb++;
						}
						d.iddatatype = IT::STR; d.idtype = IT::L; strcpy(d.value.vstr.str, cpy);
						d.value.vstr.len = l - 2; strcat(d.id, "L");  strcat(d.id, _itoa(numb, c, 10));
						IT::Add(it, d);
					}
				}
				if (!rc)
				{
					rc = CheckExpression(FST::integerlt, lextable, arr[i], line, LEX_LITERAL);
					if (rc)
					{
						int numb = 0; char c[2]; memset(d.id, NULL, 5);
						for (int pos = 0; pos < lextable.size; pos++)
						{ 
							if (lextable.table[pos].lexema == LEX_LITERAL) numb++;
						}
						d.idtype = IT::L; d.value.vint = atoi(arr[i]);
						strcat(d.id, "L"); strcat(d.id, _itoa(numb, c, 10));
						d.iddatatype = IT::INT;
						IT::Add(it, d);
					}
				}
				if (!rc) rc = CheckExpression(FST::function, lextable, arr[i], line, LEX_FUNCTION);
				if (!rc) rc = CheckExpression(FST::Return, lextable, arr[i], line, LEX_RETURN);
				if (!rc) rc = CheckExpression(FST::print, lextable, arr[i], line, LEX_PRINT);
				if (!rc) rc = CheckExpression(FST::semicolon, lextable, arr[i], line, LEX_SEMICOLON);
				if (!rc) rc = CheckExpression(FST::zp, lextable, arr[i], line, LEX_COMMA);
				if (!rc)
				{
					rc = CheckExpression(FST::id, lextable, arr[i], line, LEX_ID);
					if (rc)
					{
						lextable.table[lextable.size - 1].idxTI = it.size;
						FST::SetFST(FST::function, arr[i - 1]); FST::SetFST(FST::integerdata, arr[i - 2]); //integer function
						if (FST::execute(FST::function) && FST::execute(FST::integerdata))
						{
							d.iddatatype = IT::INT; d.idtype = IT::F; strcpy(d.id, arr[i]);
							d.value.vint = TI_NULLIDX; d.idxfirstLE = lextable.size - 1; IT::Add(it, d);
						}
						FST::SetFST(FST::integerdata, arr[i - 1]); FST::SetFST(FST::rightbracket, arr[i - 2]); FST::SetFST(FST::zp, arr[i - 2]);// integer parm
						if (FST::execute(FST::integerdata) && (FST::execute(FST::rightbracket) || FST::execute(FST::zp)))
						{
							char* cpy = new char[5]; int pos = it.size;
							memset(cpy, NULL, 5); memset(d.id, NULL, 5); // заполнение
							while (it.table[pos].idtype != IT::F)
								pos--;
							strcat(d.id, it.table[pos].id);
							d.iddatatype = IT::INT; d.idtype = IT::P; strcat(d.id, arr[i]);
							d.value.vint = 0; d.idxfirstLE = lextable.size - 1; IT::Add(it, d);
						}
						FST::SetFST(FST::integerdata, arr[i - 1]); FST::SetFST(FST::declare, arr[i - 2]); // integer declare
						if (FST::execute(FST::declare) && FST::execute(FST::integerdata))
						{
							char* cpy = new char[5]; int pos = it.size; bool rc = false;
							memset(cpy, NULL, 5); memset(d.id, NULL, 5);
							int lexl = lextable.size;
							while (lextable.table[lexl].lexema != LEX_MAIN && lexl > 0)
								lexl--;
							if (lexl > 0)
							{
								strcat(d.id, "main");
								d.iddatatype = IT::STR; d.idtype = IT::V; strcat(d.id, arr[i]);
								d.value.vstr.str[0] = TI_STR_DEFAULT; d.value.vstr.len = 0; d.idxfirstLE = lextable.size - 1; IT::Add(it, d);
							}
							else
							{
								while (it.table[pos].idtype != IT::F)
								{
									pos--;
									if (strcmp(it.table[pos].id, "substr") == NULL || strcmp(it.table[pos].id, "strlen") == NULL) pos--;
								}
								if (strcmp(it.table[pos].id, "substr") == NULL) rc = true;
								strcat(d.id, it.table[pos].id);
								d.iddatatype = IT::STR; d.idtype = IT::V; strcat(d.id, arr[i]);
								d.value.vstr.str[0] = TI_STR_DEFAULT; d.value.vstr.len = 0; d.idxfirstLE = lextable.size - 1; IT::Add(it, d);
							}
						}
							FST::SetFST(FST::function, arr[i - 1]); FST::SetFST(FST::stringdata, arr[i - 2]); //string function
							if (FST::execute(FST::function) && FST::execute(FST::stringdata))
							{
								d.iddatatype = IT::STR; d.idtype = IT::F; strcpy(d.id, arr[i]); d.value.vstr.str[0] = TI_STR_DEFAULT;
								d.value.vstr.len = -1; d.idxfirstLE = lextable.size - 1;  IT::Add(it, d);
							}
							FST::SetFST(FST::stringdata, arr[i - 1]); FST::SetFST(FST::rightbracket, arr[i - 2]); FST::SetFST(FST::zp, arr[i - 2]);// string parm
							if (FST::execute(FST::stringdata) && (FST::execute(FST::rightbracket) || FST::execute(FST::zp)))
							{
								char* cpy = new char[5]; int pos = it.size;
								memset(cpy, NULL, 5); memset(d.id, NULL, 5);
								while (it.table[pos].idtype != IT::F)
									pos--;
								strcat(d.id, it.table[pos].id);
								d.iddatatype = IT::STR; d.idtype = IT::P; strcat(d.id, arr[i]);
								d.value.vstr.str[0] = TI_STR_DEFAULT; d.value.vstr.len = 0; d.idxfirstLE = lextable.size - 1; IT::Add(it, d);
							}
							FST::SetFST(FST::stringdata, arr[i - 1]); FST::SetFST(FST::declare, arr[i - 2]);// string declare
							if (FST::execute(FST::declare) && FST::execute(FST::stringdata))
							{
								char* cpy = new char[5]; int pos = it.size; bool rc = false;
								memset(cpy, NULL, 5); memset(d.id, NULL, 5);
								int lexl = lextable.size;
								while (lextable.table[lexl].lexema != LEX_MAIN && lexl > 0)
									lexl--;
								if (lexl > 0)
								{
									strcat(d.id, "main");
									d.iddatatype = IT::STR; d.idtype = IT::V; strcat(d.id, arr[i]);
									d.value.vstr.str[0] = TI_STR_DEFAULT; d.value.vstr.len = 0; d.idxfirstLE = lextable.size - 1; IT::Add(it, d);
								}
								else
								{
									while (it.table[pos].idtype != IT::F)
									{
										pos--;
										if (strcmp(it.table[pos].id, "substr") == NULL || strcmp(it.table[pos].id, "strlen") == NULL) pos--;
									}
									if (strcmp(it.table[pos].id, "substr") == NULL) rc = true;
									strcat(d.id, it.table[pos].id);
									d.iddatatype = IT::STR; d.idtype = IT::V; strcat(d.id, arr[i]);
									d.value.vstr.str[0] = TI_STR_DEFAULT; d.value.vstr.len = 0; d.idxfirstLE = lextable.size - 1; IT::Add(it, d);
								}
							}
						}
					}
					if (!rc) rc = CheckExpression(FST::openblock, lextable, arr[i], line, LEX_LEFTBRACE);
					if (!rc) rc = CheckExpression(FST::closeblock, lextable, arr[i], line, LEX_BRACELET);
					if (!rc) rc = CheckExpression(FST::rightbracket, lextable, arr[i], line, LEX_LEFTTHESIS);
					if (!rc) rc = CheckExpression(FST::leftbracket, lextable, arr[i], line, LEX_RIGHTTHESIS);
					if (!rc) rc = CheckExpression(FST::oper, lextable, arr[i], line, LEX_PLUS);
					if (!rc) rc = CheckExpression(FST::oper, lextable, arr[i], line, LEX_MINUS);
					if (!rc) rc = CheckExpression(FST::oper, lextable, arr[i], line, LEX_STAR);
					if (!rc) rc = CheckExpression(FST::oper, lextable, arr[i], line, LEX_DIRSLASH);
					if (!rc) rc = CheckExpression(FST::ravno, lextable, arr[i], line, LEX_RAVNO);
				}
				i++;
			}


			for (int k = 0; k < lextable.size; k++)
			{
				if (lextable.table[k].sn != lextable.table[k - 1].sn) *log.stream << std::endl;
				*log.stream << lextable.table[k].lexema;
			}
			*log.stream << std::endl;
			*log.stream << std::endl;
			*log.stream << std::endl;

			for (int k = 0; k < it.size; k++)
			{
				*log.stream << "Тип: ";
				switch (it.table[k].iddatatype)
				{
				case IT::INT: *log.stream << "Integer "; break;
				case IT::STR: *log.stream << "String "; break;
				}

				switch (it.table[k].idtype)
				{
				case IT::V: *log.stream << "Переменная "; break;
				case IT::F: *log.stream << "Функция "; break;
				case IT::P: *log.stream << "Параметр "; break;
				case IT::L: *log.stream << "Литерал "; break;
				}

				*log.stream << "Значение: ";
				switch (it.table[k].iddatatype)
				{
				case IT::INT: *log.stream << it.table[k].id << " " << it.table[k].value.vint; break;
				case IT::STR: *log.stream << it.table[k].id << " " << it.table[k].value.vstr.str; break;
				}
				*log.stream << std::endl;
			}
		}
	}