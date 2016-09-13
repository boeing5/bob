#include "stdafx.h"
#include"IT.h"

namespace IT
{
	IdTable Create(int size)
	{
		IdTable* rc = new IdTable;
		rc->maxsize = size; rc->size = 0;
		rc->table = new Entry[size];
		return *rc;
	}
	void Add(IdTable& idtable, Entry entry)
	{
		idtable.table[idtable.size++] = entry;
	}
	Entry GetEntry(IdTable& idtable, int n)
	{
		Entry rc = {};
		return rc;
	}
	int IsId(IdTable& idtable, char id[ID_MAXSIZE])
	{
		int rc = TI_NULLIDX;
		for (int i=0; i< idtable.size; i++) 
		if (strcmp(idtable.table[i].id,id)==0) rc=i;
		return rc;
	}
	void Delete(IdTable& idtable)
	{}
}