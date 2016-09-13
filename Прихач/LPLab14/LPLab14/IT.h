#pragma once

#define ID_MAXSIZE		5
#define TI_MAX_SIZE		4096
#define TI_INT_DEFAULT  0x00000000
#define TI_STR_DEFAULT  0x00
#define TI_NULLIDX      0xffffffff
#define TI_STR_MAXSIZE  255

namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };

	struct Entry
	{
		int			idxfirstLE;
		char		id[ID_MAXSIZE];
		IDDATATYPE  iddatatype;
		IDTYPE		idtype;
		union
		{
			int vint = NULL;
			struct
			{
				int len;
				char str[TI_STR_MAXSIZE];
			} vstr;
		} value;
	};

	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};
	IdTable Create(
		int size
		);
	void Add(
		IdTable& idtable,
		Entry entry
		);
	int IsId(
		IdTable& idtable,
		char id[ID_MAXSIZE]
		);

	void Delete(IdTable& idtable);
};