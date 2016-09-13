#include "stdafx.h"
#include "FST.h"

namespace FST//массив лексем
{
	FST integerdata(
		"",
		8,
		NODE(1, RELATION('i', 1)),
		NODE(1, RELATION('n', 2)),
		NODE(1, RELATION('t', 3)),
		NODE(1, RELATION('e', 4)),
		NODE(1, RELATION('g', 5)),
		NODE(1, RELATION('e', 6)),
		NODE(1, RELATION('r', 7)),
		NODE()
		);

	FST stringdata(
		"",
		7,
		NODE(1, RELATION('s', 1)),
		NODE(1, RELATION('t', 2)),
		NODE(1, RELATION('r', 3)),
		NODE(1, RELATION('i', 4)),
		NODE(1, RELATION('n', 5)),
		NODE(1, RELATION('g', 6)),
		NODE()
		);

	FST id(
		"",
		2,
		NODE(52, RELATION('a', 0), RELATION('a', 1),
		RELATION('b', 0), RELATION('b', 1),
		RELATION('c', 0), RELATION('c', 1),
		RELATION('d', 0), RELATION('d', 1),
		RELATION('e', 0), RELATION('e', 1),
		RELATION('f', 0), RELATION('f', 1),
		RELATION('g', 0), RELATION('g', 1),
		RELATION('h', 0), RELATION('h', 1),
		RELATION('i', 0), RELATION('i', 1),
		RELATION('j', 0), RELATION('j', 1),
		RELATION('k', 0), RELATION('k', 1),
		RELATION('l', 0), RELATION('l', 1),
		RELATION('m', 0), RELATION('m', 1),
		RELATION('n', 0), RELATION('n', 1),
		RELATION('o', 0), RELATION('o', 1),
		RELATION('p', 0), RELATION('p', 1),
		RELATION('q', 0), RELATION('q', 1),
		RELATION('r', 0), RELATION('r', 1),
		RELATION('s', 0), RELATION('s', 1),
		RELATION('t', 0), RELATION('t', 1),
		RELATION('u', 0), RELATION('u', 1),
		RELATION('v', 0), RELATION('v', 1),
		RELATION('w', 0), RELATION('w', 1),
		RELATION('x', 0), RELATION('x', 1),
		RELATION('y', 0), RELATION('y', 1),
		RELATION('z', 0), RELATION('z', 1)),
		NODE()
		);

	FST function(
		"",
		9,
		NODE(1, RELATION('f', 1)),
		NODE(1, RELATION('u', 2)),
		NODE(1, RELATION('n', 3)),
		NODE(1, RELATION('c', 4)),
		NODE(1, RELATION('t', 5)),
		NODE(1, RELATION('i', 6)),
		NODE(1, RELATION('o', 7)),
		NODE(1, RELATION('n', 8)),
		NODE()
		);

	FST declare(
		"",
		8,
		NODE(1, RELATION('d', 1)),
		NODE(1, RELATION('e', 2)),
		NODE(1, RELATION('c', 3)),
		NODE(1, RELATION('l', 4)),
		NODE(1, RELATION('a', 5)),
		NODE(1, RELATION('r', 6)),
		NODE(1, RELATION('e', 7)),
		NODE()
		);

	FST main(
		"",
		5,
		NODE(1, RELATION('m', 1)),
		NODE(1, RELATION('a', 2)),
		NODE(1, RELATION('i', 3)),
		NODE(1, RELATION('n', 4)),
		NODE()
		);

	FST print(
		"",
		6,
		NODE(1, RELATION('p', 1)),
		NODE(1, RELATION('r', 2)),
		NODE(1, RELATION('i', 3)),
		NODE(1, RELATION('n', 4)),
		NODE(1, RELATION('t', 5)),
		NODE()
		);

	FST Return(
		"",
		7,
		NODE(1, RELATION('r', 1)),
		NODE(1, RELATION('e', 2)),
		NODE(1, RELATION('t', 3)),
		NODE(1, RELATION('u', 4)),
		NODE(1, RELATION('r', 5)),
		NODE(1, RELATION('n', 6)),
		NODE()
		);

	FST oper(
		"",
		2,
		NODE(4, RELATION('+', 1), RELATION('-', 1), RELATION('/', 1), RELATION('*', 1)),
		NODE()
		);
	FST stringlt(
		"",
		3,
		NODE(1, RELATION('"', 1)),
		NODE(71, RELATION(' ', 1),
		RELATION('а', 1),
		RELATION('б', 1),
		RELATION('в', 1),
		RELATION('г', 1),
		RELATION('д', 1),
		RELATION('е', 1),
		RELATION('ё', 1),
		RELATION('ж', 1),
		RELATION('з', 1),
		RELATION('и', 1),
		RELATION('к', 1),
		RELATION('л', 1),
		RELATION('м', 1),
		RELATION('н', 1),
		RELATION('о', 1),
		RELATION('п', 1),
		RELATION('р', 1),
		RELATION('й', 1),
		RELATION('с', 1),
		RELATION('т', 1),
		RELATION('у', 1),
		RELATION('ф', 1),
		RELATION('х', 1),
		RELATION('ц', 1),
		RELATION('ч', 1),
		RELATION('ш', 1),
		RELATION('щ', 1),
		RELATION('ъ', 1),
		RELATION('ы', 1),
		RELATION('ь', 1),
		RELATION('э', 1),
		RELATION('ю', 1),
		RELATION('я', 1),
		RELATION('a', 1),
		RELATION('b', 1),
		RELATION('c', 1),
		RELATION('d', 1),
		RELATION('e', 1),
		RELATION('f', 1),
		RELATION('g', 1),
		RELATION('h', 1),
		RELATION('i', 1),
		RELATION('j', 1),
		RELATION('k', 1),
		RELATION('l', 1),
		RELATION('m', 1),
		RELATION('n', 1),
		RELATION('o', 1),
		RELATION('p', 1),
		RELATION('q', 1),
		RELATION('r', 1),
		RELATION('s', 1),
		RELATION('t', 1),
		RELATION('u', 1),
		RELATION('v', 1),
		RELATION('w', 1),
		RELATION('x', 1),
		RELATION('y', 1),
		RELATION('z', 1), 
		RELATION('1', 1),
		RELATION('2', 1),
		RELATION('3', 1),
		RELATION('4', 1),
		RELATION('5', 1),
		RELATION('6', 1),
		RELATION('7', 1),
		RELATION('8', 1),
		RELATION('9', 1),
		RELATION('0', 1),
		RELATION('"', 2)),
		NODE()
		);

	FST integerlt(
		"",
		2,
		NODE(20, RELATION('1', 0), RELATION('1', 1),
		RELATION('2', 0), RELATION('2', 1),
		RELATION('3', 0), RELATION('3', 1),
		RELATION('4', 0), RELATION('4', 1),
		RELATION('5', 0), RELATION('5', 1),
		RELATION('6', 0), RELATION('6', 1),
		RELATION('7', 0), RELATION('7', 1),
		RELATION('8', 0), RELATION('8', 1),
		RELATION('9', 0), RELATION('9', 1),
		RELATION('0', 0), RELATION('0', 1)),
		NODE()
		);

	FST openblock("", 2, NODE(1, RELATION('{', 1)), NODE());
	FST closeblock("", 2, NODE(1, RELATION('}', 1)), NODE());
	FST rightbracket("", 2, NODE(1, RELATION('(', 1)), NODE());
	FST leftbracket("", 2, NODE(1, RELATION(')', 1)), NODE());
	FST semicolon("", 2, NODE(1, RELATION(';', 1)), NODE());
	FST zp("", 2, NODE(1, RELATION(',', 1)), NODE());
	FST ravno("", 2, NODE(1, RELATION('=', 1)), NODE());
}