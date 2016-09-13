#pragma once
#include "stdafx.h"

using namespace std;

LT::LexTable l = LT::Create(LT_MAXSIZE); // Создание таблицы лексем
LT::Entry e;                             // временная лексема
IT::IdTable iT = IT::Create(200);        // создание таблицы индефикаторов размером 200

FST::FST fstTypeInteger("", 8,
	FST::NODE(1, FST::RELATION('i', 1)),
	FST::NODE(1, FST::RELATION('n', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('e', 4)),
	FST::NODE(1, FST::RELATION('g', 5)),
	FST::NODE(1, FST::RELATION('e', 6)),
	FST::NODE(1, FST::RELATION('r', 7)),
	FST::NODE()
	);

FST::FST fstTypeString("", 7,
	FST::NODE(1, FST::RELATION('s', 1)),
	FST::NODE(1, FST::RELATION('t', 2)),
	FST::NODE(1, FST::RELATION('r', 3)),
	FST::NODE(1, FST::RELATION('i', 4)),
	FST::NODE(1, FST::RELATION('n', 5)),
	FST::NODE(1, FST::RELATION('g', 6)),
	FST::NODE()
	);

FST::FST fstV("", 2,
	FST::NODE(5, FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('/', 1), FST::RELATION('*', 1), FST::RELATION('=', 1)),
	FST::NODE()
	);

FST::FST fstIdentif("", 2,
	FST::NODE(52, FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
	FST::RELATION('c', 1), FST::RELATION('c', 0), FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0),
	FST::RELATION('f', 1), FST::RELATION('f', 0), FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
	FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
	FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
	FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
	FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
	FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
	FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
	FST::NODE()
	);

FST::FST fstKeyFunction("", 9,
	FST::NODE(1, FST::RELATION('f', 1)),
	FST::NODE(1, FST::RELATION('u', 2)),
	FST::NODE(1, FST::RELATION('n', 3)),
	FST::NODE(1, FST::RELATION('c', 4)),
	FST::NODE(1, FST::RELATION('t', 5)),
	FST::NODE(1, FST::RELATION('i', 6)),
	FST::NODE(1, FST::RELATION('o', 7)),
	FST::NODE(1, FST::RELATION('n', 8)),
	FST::NODE()
	);

FST::FST fstKeyDeclare("", 8,
	FST::NODE(1, FST::RELATION('d', 1)),
	FST::NODE(1, FST::RELATION('e', 2)),
	FST::NODE(1, FST::RELATION('c', 3)),
	FST::NODE(1, FST::RELATION('l', 4)),
	FST::NODE(1, FST::RELATION('a', 5)),
	FST::NODE(1, FST::RELATION('r', 6)),
	FST::NODE(1, FST::RELATION('e', 7)),
	FST::NODE()
	);

FST::FST fstKeyMain("", 5,
	FST::NODE(1, FST::RELATION('m', 1)),
	FST::NODE(1, FST::RELATION('a', 2)),
	FST::NODE(1, FST::RELATION('i', 3)),
	FST::NODE(1, FST::RELATION('n', 4)),
	FST::NODE()
	);

FST::FST fstKeyPrint("", 6,
	FST::NODE(1, FST::RELATION('p', 1)),
	FST::NODE(1, FST::RELATION('r', 2)),
	FST::NODE(1, FST::RELATION('i', 3)),
	FST::NODE(1, FST::RELATION('n', 4)),
	FST::NODE(1, FST::RELATION('t', 5)),
	FST::NODE()
	);

FST::FST fstKeyreturn("", 7,
	FST::NODE(1, FST::RELATION('r', 1)),
	FST::NODE(1, FST::RELATION('e', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('u', 4)),
	FST::NODE(1, FST::RELATION('r', 5)),
	FST::NODE(1, FST::RELATION('n', 6)),
	FST::NODE()
	);

FST::FST fstLeftThesis("", 2,
	FST::NODE(1, FST::RELATION('(', 1)),
	FST::NODE()
	);

FST::FST fstRightThesis("", 2,
	FST::NODE(1, FST::RELATION(')', 1)),
	FST::NODE()
	);

FST::FST fstSemiColon("", 2,
	FST::NODE(1, FST::RELATION(';', 1)),
	FST::NODE()
	);

FST::FST fstComma("", 2,
	FST::NODE(1, FST::RELATION(',', 1)),
	FST::NODE()
	);

FST::FST fstLeftBrace("", 2,
	FST::NODE(1, FST::RELATION('{', 1)),
	FST::NODE()
	);

FST::FST fstRightBrace("", 2,
	FST::NODE(1, FST::RELATION('}', 1)),
	FST::NODE()
	);

FST::FST fstIntegerLiteral("", 2,
	FST::NODE(20, FST::RELATION('0', 1), FST::RELATION('0', 0), FST::RELATION('1', 1), FST::RELATION('1', 0),
	FST::RELATION('2', 1), FST::RELATION('2', 0), FST::RELATION('3', 1), FST::RELATION('3', 0),
	FST::RELATION('5', 1), FST::RELATION('4', 0), FST::RELATION('5', 1), FST::RELATION('5', 0),
	FST::RELATION('6', 1), FST::RELATION('6', 0), FST::RELATION('7', 1), FST::RELATION('7', 0),
	FST::RELATION('8', 1), FST::RELATION('8', 0), FST::RELATION('9', 1), FST::RELATION('9', 0)),
	FST::NODE()
	);

bool newLexem(FST::FST &fst, char *newLexem, int lineCode, char lexem)
{
	bool rc = false;
	FST::newFST(fst, newLexem);//обуляет до первоначальных значений
	if (FST::execute(fst))
	{
		e.lexema = lexem;
		e.idxTI = l.size;//номер лексемы
		e.sn = lineCode;
		LT::Add(l, e);
		rc = true;
	}
	return rc;
}

void Log::LexAnaliz(In::IN in, LOG log)
{
	char *tempWords = new char[255]; // слова для подачи в автомат
	char *tempId = new char[5];       // имя переменной усекается до 4 символов
	char *tempInit = new char[255];   // знаечение переменной

	int tempWordsSize = 0;

	int lineCode = 0;

	bool typeID = false;//для определения переменной
	bool IdInil = false; // "="

	for (int i = 0; i < in.size; i++)
	{
		if (in.text[i] == IN_CODE_ENDL)
		{
			lineCode++;
			continue;
		}

		if (in.text[i] != ' ' && in.text[i] != LEX_SEMICOLON &&
			in.text[i] != LEX_LEFTTHESIS && in.text[i] != LEX_RIGHTTHESIS &&
			in.text[i] != LEX_LEFTBRACE && in.text[i] != LEX_BRACELET &&
			in.text[i] != LEX_COMMA && in.text[i] != '-' &&
			in.text[i] != '+' && in.text[i] != '/' &&
			in.text[i] != '=' && in.text[i] != '*')
		{
			tempWords[tempWordsSize] = in.text[i];
			tempWordsSize++;
		}
		else
		{
			bool rc = false;
			tempWords[tempWordsSize] = '\0';
			tempWordsSize = 0;

			if (!rc)
			{
				rc = newLexem(fstTypeInteger, tempWords, lineCode, LEX_INTEGER);
				if (rc)
				{
					iT.table[iT.size].idxfirstLE = lineCode;
					iT.table[iT.size].iddatatype = IT::INT;//перечисление(1)
					if (l.table[l.size - 2].lexema == LEX_DECLARE)
					{
						iT.table[iT.size].idtype = IT::V;
					}
					if (l.table[l.size - 2].lexema == LEX_COMMA || l.table[l.size - 2].lexema == LEX_LEFTTHESIS)
					{
						iT.table[iT.size].idtype = IT::P;
					}
					if (l.size == 1 || l.table[l.size - 2].lexema == LEX_SEMICOLON)
					{
						iT.table[iT.size].idtype = IT::F;
					}
					iT.size++;
					typeID = true;
				}
			}
			if (!rc)
			{
				rc = newLexem(fstTypeString, tempWords, lineCode, LEX_STRING);
				if (rc)
				{
					iT.table[iT.size].idxfirstLE = lineCode;
					iT.table[iT.size].iddatatype = IT::STR;
					if (l.table[l.size - 2].lexema == LEX_DECLARE)
					{
						iT.table[iT.size].idtype = IT::V;
						iT.table[iT.size].value.vstr.len = 0;
						iT.table[iT.size].value.vstr.str[0] = '\0';
					}
					if (l.table[l.size - 2].lexema == LEX_COMMA || l.table[l.size - 2].lexema == LEX_LEFTTHESIS)
					{
						iT.table[iT.size].idtype = IT::P;
					}
					if (l.size == 1 || l.table[l.size - 2].lexema == LEX_SEMICOLON)
					{
						iT.table[iT.size].idtype = IT::F;
					}
					iT.size++;
					typeID = true;
				}
			}
			if (!rc)
			{
				rc = newLexem(fstKeyFunction, tempWords, lineCode, LEX_FUNCTION);
			}
			if (!rc)
			{
				rc = newLexem(fstKeyDeclare, tempWords, lineCode, LEX_DECLARE);
			}
			if (!rc)
			{
				rc = newLexem(fstKeyMain, tempWords, lineCode, LEX_MAIN_FUNCTION);
			}
			if (!rc)
			{
				rc = newLexem(fstKeyPrint, tempWords, lineCode, LEX_PRINT);
			}
			if (!rc)
			{
				rc = newLexem(fstKeyreturn, tempWords, lineCode, LEX_RETURN);
			}
			if (!rc)
			{
				rc = newLexem(fstIdentif, tempWords, lineCode, LEX_ID);
				if (rc)
				{
					int scht;
					if (strlen(tempWords) > 3)
					{
						scht = 4;
					}
					else
					{
						scht = strlen(tempWords);
					}
					for (int i = 0; i < scht; i++)
					{
						tempId[i] = tempWords[i];
					}
				}
				if (rc && typeID)//если сначала считали тип, а потом имя переменной
				{
					memset(iT.table[iT.size - 1].id, NULL, 5);
					memset(tempId, NULL, 5);
					int scht;
					if (strlen(tempWords) > 3)
					{
						scht = 4;
					}
					else
					{
						scht = strlen(tempWords);
					}
					for (int i = 0; i < scht; i++)
					{
						iT.table[iT.size - 1].id[i] = tempWords[i];
						tempId[i] = tempWords[i];
					}
					typeID = false;
				}
			}
			if (!rc)
			{
				memset(tempInit, '\0', 255);
				for (int i = 0; i < strlen(tempWords); i++)
				{
					tempInit[i] = tempWords[i];
				}
				rc = newLexem(fstIntegerLiteral, tempWords, lineCode, LEX_LITERAL);

				if (IdInil && rc)
				{
					for (int i = 0; i < iT.size; i++)
					{
						if (strcmp(tempId, iT.table[i].id) == 0)//ищу такой идентфикатор в таблице
						{
							int value = atoi(tempInit);
							iT.table[i].value.vint = value;//название объединения, само знач, кторое я присваиваю интеджеру
						}
						IdInil = false;
					}
				}
			}
			memset(tempWords, 0, strlen(tempWords));
		}

		if (in.text[i] == LEX_SEMICOLON || in.text[i] == LEX_LEFTTHESIS ||
			in.text[i] == LEX_RIGHTTHESIS || in.text[i] == LEX_LEFTBRACE ||
			in.text[i] == LEX_BRACELET || in.text[i] == LEX_COMMA)
		{
			bool rc = false;

			tempWords[0] = in.text[i];
			tempWords[1] = '\0';

			if (!rc)
			{
				rc = newLexem(fstSemiColon, tempWords, lineCode, LEX_SEMICOLON);
			}
			if (!rc)
			{
				rc = newLexem(fstLeftBrace, tempWords, lineCode, LEX_LEFTBRACE);

			}
			if (!rc)
			{
				rc = newLexem(fstRightBrace, tempWords, lineCode, LEX_BRACELET);
			}
			if (!rc)
			{
				rc = newLexem(fstComma, tempWords, lineCode, LEX_COMMA);
			}
			if (!rc)
			{
				rc = newLexem(fstLeftThesis, tempWords, lineCode, LEX_LEFTTHESIS);
			}
			if (!rc)
			{
				rc = newLexem(fstRightThesis, tempWords, lineCode, LEX_RIGHTTHESIS);
			}
		}

		if (in.text[i] == '=')
		{
			IdInil = true;
		}

		if (in.text[i] == '-' || in.text[i] == '+' || in.text[i] == '/' ||
			in.text[i] == '=' || in.text[i] == '*')
		{
			bool rc = false;
			tempWords[0] = in.text[i];
			tempWords[1] = '\0';
			if (!rc)
			{
				rc = newLexem(fstV, tempWords, lineCode, 'v');
			}
		}

		if (in.text[i] == '\'')
		{
			i++;
			int j = 0;
			while (in.text[i] != '\'')
			{
				tempInit[j] = in.text[i];
				j++;
				i++;
			}
			tempInit[j] = '\0';

			if (IdInil && l.table[l.size - 1].lexema == 'v')
			{
				for (int i = 0; i < iT.size; i++)
				{
					if (strcmp(tempId, iT.table[i].id) == 0)//найти в аблице идентификаторов
					{
						for (int j = 0; j < strlen(tempInit); j++)
						{
							iT.table[i].value.vstr.str[j] = tempInit[j];//заношу литерал как знач идентификатора
						}
						iT.table[i].value.vstr.str[strlen(tempInit)] = '\0';
						iT.table[i].value.vstr.len = strlen(iT.table[i].value.vstr.str);//заношу в поле длины длину литерала
					}
				}
				IdInil = false;
			}
			else
			{
				iT.table[iT.size].idxfirstLE = lineCode;
				iT.table[iT.size].id[0] = 'L';
				iT.table[iT.size].id[1] = 'E';
				iT.table[iT.size].id[2] = '\0';
				iT.table[iT.size].iddatatype = IT::STR; // что это стринг
				iT.table[iT.size].idtype = IT::L; //именно пустой литерал
				for (int j = 0; j < strlen(tempInit); j++)
				{
					iT.table[iT.size].value.vstr.str[j] = tempInit[j];
				}
				iT.table[iT.size].value.vstr.str[strlen(tempInit)] = '\0';
				iT.table[iT.size].value.vstr.len = strlen(iT.table[iT.size].value.vstr.str);
				iT.size++;
			}
			e.lexema = LEX_LITERAL;
			e.idxTI = l.size;
			e.sn = lineCode;
			LT::Add(l, e);
		}
	}



	for (int i = 0; i < l.size; i++)
	{
		if (l.table[i].sn != l.table[i - 1].sn) // Чтобы при выводе выводило на новых строках
		{
			(*log.stream) << std::endl;
			(*log.stream) << l.table[i].sn + 1 << " ";
		}
		(*log.stream) << l.table[i].lexema;
	}

	std::cout << std::endl;

	for (int i = 0; i < iT.size; i++)
	{
		cout << "Индификатор: " << iT.table[i].id << endl;

		if (iT.table[i].iddatatype == IT::INT)
			cout << "Тип данных: integer" << endl;
		else
			cout << "Тип данных: string" << endl;

		if (iT.table[i].idtype == IT::V)
			cout << "Тип индификатора: переменная" << endl;
		else if (iT.table[i].idtype == IT::F)
			cout << "Тип индификатора: функция" << endl;
		else if (iT.table[i].idtype == IT::P)
			cout << "Тип индификатора: парамметр" << endl;
		else
			cout << "Тип индификатора: литерал" << endl;

		if (iT.table[i].iddatatype == IT::INT && iT.table[i].idtype == IT::V)
			cout << "Инициализированное значение: " << iT.table[i].value.vint << endl;
		else if ((iT.table[i].iddatatype == IT::STR && iT.table[i].idtype == IT::V)
			|| (iT.table[i].iddatatype == IT::STR && iT.table[i].idtype == IT::L))
		{
			if (iT.table[i].value.vstr.str[0] == NULL)
			{
				cout << "Инициализированное значение: NULL" << endl;
			}
			else
				cout << "Инициализированное значение: " << iT.table[i].value.vstr.str << endl;
			cout << "Длина строки: " << iT.table[i].value.vstr.len << endl;
		}

		cout << endl;
	}
}