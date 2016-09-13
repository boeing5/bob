#pragma once
#define ID_MAXSIZE 5 // макс колво символов в идентификаторе
#define TI_MAXSIZE 4096
#define TI_INT_DEFAULT 0x00000000 // по умолчанию дл€ int
#define	TI_STR_DEFAULT 0x00       // по умолчанию дл€ string
#define TI_NULLIDX 0xffffffff     // нет элемента таблицы идентификаторов
#define	TI_STR_MAXSIZE 255        // максимальна€ длинна строки

namespace IT   // таблицы идентификаторов
{
	enum IDDATATYPE { INT = 1, STR = 2 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };

	struct Entry   // строка таблицы идентификаторов
	{
		int idxfirstLE; // индекс обь€влени€ идентификатора(индекс первой строки в таблице лексем) где он встречаетс€ первый раз
		char id[ID_MAXSIZE]; // идентификатор 
		IDDATATYPE iddatatype; // тип данных
		IDTYPE idtype; // тип идентификатора
		union 
		{
			int vint; 
			struct
			{
				char len; // количество символов в string
				char str[TI_STR_MAXSIZE - 1]; // символы string
			} vstr;
		} value;
	};

	struct IdTable // экземпл€р таблицы идентификаторов
	{
		int maxsize; // емкость таблицы идентификаторов
		int size; // текщий размер таблицы идентификаторов
		Entry* table; // массив строк таблицы идентификаторов
	};

	IdTable Create(int size);
	void Add(IdTable& idtable, Entry entry);
	Entry GetEntry(IdTable& idtable,int n);
	int IsId(IdTable& idtable,char id[ID_MAXSIZE]); // возврат: номер строки (если есть), TI_NULLIDX(если нет)
	void Delete(IdTable& idtable);

}