#include "stdafx.h"
#include "IT.h"

namespace IT
{
	IdTable Create(int size)
	{
		IdTable* New = new IdTable;
		New->maxsize = size;
		New->size = 0;
		New->table = new Entry[size];
		return *New;
	}

	void Add(IdTable& idtable, Entry entry)
	{
		idtable.table[idtable.size++] = entry;
	}

	Entry GetEntry(IdTable& idtable, int n)
	{
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, char id[ID_MAXSIZE])
	{
		bool rc = false;
		int i;
		for (i = 0; i<idtable.size; i++)
		{
			if (idtable.table[i].id == id)
			{
				rc = true;
				break;
			}
		}
		return rc ? i : TI_NULLIDX;
	}
}