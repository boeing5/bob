#include "stdafx.h"

namespace FST
{
	struct RELATION //ребро:символ -> вершина графа переходов Конечного автомата
	{
		char symbol; // символ перехода
		short nnode;  // номер смежной вершины
		RELATION(char c = 0x00, short ns = NULL); // символ перехода и новое состояние
	};

	struct NODE  // вершина графа переходов
	{
		short n_relation;  // количество инциндентных ребер
		RELATION* relations; // инцидентные ребра
		NODE();
		NODE(short n, RELATION rel, ...); // количество инцидентных ребер, список ребер
	};

	struct FST  // недетерминированный конечный автомат
	{
		char* string; // цепочка
		short position; // текущая позиция
		short nstates; // количество состояний
		short errors; // ошибки
		NODE* nodes; // граф переходов [0] начальное состояние [nstates-1] конечное состояние
		short* rstates; // возможные состояние 
		FST(char* s, short ns, NODE n, ...); // цепочка , количество состояний, список состояний
	};

	bool execute(FST& fst); // моделирует работу автомата
	void processing(char* text, std::ofstream* stream, void (f)(int, int, int, std::ofstream*));
	void SetFST(FST& fst, char* source);
}