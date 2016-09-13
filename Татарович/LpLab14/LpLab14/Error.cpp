#include "stdafx.h"
#include "Error.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0,"Недопустимый код ошибки"),
		ERROR_ENTRY(1,"Системный сбой"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"Параметр -in должен быть задан"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104,"Превышена длина входного параметра"),
		ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "Ошибка при открытии файла с исходным кодом (-in)"),
		ERROR_ENTRY(111, "Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(112, "Ошибка при создании файла протокола (-log)"),
		ERROR_ENTRY(113, "Недопустимое выражение: "), ERROR_ENTRY_NODEF(114), ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116), ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500), ERROR_ENTRY_NODEF100(600),
		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	char* writeerror(int id)
	{
		ERROR rc = geterror(id);
		char* str = rc.message;
		return str;
	}

	void writeerror(int id, std::ofstream* stream) 
	{
		ERROR rc = geterror(id);
		*stream<<rc.message<<IN_CODE_ENDL; 
	}

	void writeerrorin(int id, int line, int col, std::ofstream* stream)
	{
		ERROR rc = geterrorin(id, line, col);
		*stream << rc.message << " Строка: " << line << " Позиция: " << col << IN_CODE_ENDL;
	}

	ERROR geterror(int id)
	{
		ERROR rc;
		if (id<0 || id>ERROR_MAX_ENTRY) { rc.id = errors[0].id; ERROR_MESAGE_COPY(rc.message, errors[0].message); }
		else { rc.id = errors[id].id; ERROR_MESAGE_COPY(rc.message, errors[id].message); }
		return rc;
	}
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		ERROR rc;
		if (id<0 || id>ERROR_MAX_ENTRY) 
		{
			rc.id = errors[0].id; 
			ERROR_MESAGE_COPY(rc.message, errors[0].message);  
			rc.inext.line = line; rc.inext.col = col;
		}
		else 
		{ 
			rc.id = errors[id].id; 
			ERROR_MESAGE_COPY(rc.message, errors[id].message);
			rc.inext.line = line; rc.inext.col = col;
		}
		return rc;
	}
}