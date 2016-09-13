#pragma once
#define LEXEMA_FIXSIZE 1
#define	LT_MAXSIZE 4096
#define LT_TI_NULLIDX 0xffffffff  // нет элемента таблицы идентификаторов
#define LEX_INTEGER 't' // лексема для integer
#define	LEX_STRING 't'
#define LEX_ID 'i'
#define LEX_LITERAL 'l'
#define LEX_FUNCTION 'f'
#define LEX_DECLARE 'd'
#define LEX_RETURN 'r'
#define LEX_PRINT 'p'
#define LEX_MAIN 'm'
#define LEX_SEMICOLON ';'
#define	LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define LEX_BRACELET '}'
#define LEX_LEFTTHESIS '('
#define	LEX_RIGHTTHESIS ')'
#define LEX_PLUS 'v'
#define LEX_MINUS 'v'
#define LEX_STAR 'v'
#define LEX_DIRSLASH 'v'
#define LEX_RAVNO '='


namespace LT // таблица лексем
{ 
	struct Entry  // строка таблицы лексем
	{
		char lexema; // лексема
		int sn; // номер строки в исходном файле
		int idxTI; // индекс в таблиц идентификаторов или LT_TI_NULLIDX
	}; 

	struct LexTable  // экземпляр таблицы лексем
	{
		int maxsize; // емкость таблицы лексем
		int size;    // текущий размер таблицы лексем
		Entry* table;  // массив строк таблицы лексем
	};

	LexTable Create(int size);  // создать таблицы
	void Add(LexTable& lextable, Entry entry); // добавить строку в таблицу лексем
	Entry GetEntry(LexTable& lextable, int n); // получить строку
	void Delete(LexTable& lextable); // удалить таблицу лексем (освободить память)

}