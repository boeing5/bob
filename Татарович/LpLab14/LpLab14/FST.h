#include "stdafx.h"

namespace FST
{
	struct RELATION //�����:������ -> ������� ����� ��������� ��������� ��������
	{
		char symbol; // ������ ��������
		short nnode;  // ����� ������� �������
		RELATION(char c = 0x00, short ns = NULL); // ������ �������� � ����� ���������
	};

	struct NODE  // ������� ����� ���������
	{
		short n_relation;  // ���������� ������������ �����
		RELATION* relations; // ����������� �����
		NODE();
		NODE(short n, RELATION rel, ...); // ���������� ����������� �����, ������ �����
	};

	struct FST  // ������������������� �������� �������
	{
		char* string; // �������
		short position; // ������� �������
		short nstates; // ���������� ���������
		short errors; // ������
		NODE* nodes; // ���� ��������� [0] ��������� ��������� [nstates-1] �������� ���������
		short* rstates; // ��������� ��������� 
		FST(char* s, short ns, NODE n, ...); // ������� , ���������� ���������, ������ ���������
	};

	bool execute(FST& fst); // ���������� ������ ��������
	void processing(char* text, std::ofstream* stream, void (f)(int, int, int, std::ofstream*));
	void SetFST(FST& fst, char* source);
}