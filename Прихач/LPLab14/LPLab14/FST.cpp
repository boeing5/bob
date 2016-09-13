#include "stdafx.h"

FST::RELATION::RELATION(char c, short ns)
{
	symbol = c;
	nnode = ns;
}

FST::NODE::NODE()
{
	n_relation = 0;
	RELATION *relations = NULL;
}

FST::NODE::NODE(short n, RELATION rel, ...)
{
	n_relation = n;
	RELATION *p = &rel;
	relations = new RELATION[n];
	for (short i = 0; i < n; i++)
	{
		relations[i] = *p;
		p++;
	}
}

FST::FST::FST(char *s, short ns, NODE n, ...)
{
	string = s;
	nstates = ns;
	nodes = new NODE[ns];
	NODE *p = &n;
	for (int k = 0; k < ns; k++)
	{
		nodes[k] = *p;
		p++;
	}
	rstates = new short[nstates];
	memset(rstates, 0xFF, sizeof(short)*nstates);
	rstates[0] = 0;
	position = -1;
}

bool FST::step(FST &fst, short *&rstates)
{
	bool rc = false;
	std::swap(rstates, fst.rstates);
	for (short i = 0; i < fst.nstates; i++)
	{
		if (rstates[i] == fst.position)
		{
			for (short j = 0; j < fst.nodes[i].n_relation; j++)
			{
				if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
				{
					fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
					rc = true;
				};
			};
		};
	};
	return rc;
}

bool FST::execute(FST &fst)
{
	short *rstates;
	rstates = new short[fst.nstates];
	memset(rstates, 0xFF, sizeof(short)*fst.nstates);
	int lstring = strlen(fst.string);
	bool rc = true;

	for (short i = 0; (i < lstring) && rc; i++)
	{
		fst.position++;
		rc = step(fst, rstates);
	}

	delete[] rstates;

	if (fst.rstates[fst.nstates - 1] == lstring)
	{
		rc = true;
	}
	else
	{
		rc = false;
	}

	return rc;
}

void FST::newFST(FST& f, char* newStr)
{
	f.position = -1;
	f.string = newStr;
	f.rstates[0] = 0;
}