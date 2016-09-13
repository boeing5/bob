#include "stdafx.h"
#include "In.h"
#define IN_CODE_ENDL "\n"

namespace In
{
	void copy_CODE(int n[256])
	{
		int m[256] = IN_CODE_TABLE;
		for (int i = 0; i < 256; i++) n[i] = m[i];
	}


	IN getin(wchar_t infile[], std::ofstream* stream, void (f)(int, int, int, std::ofstream*)) //добавляем поток как параметр в функцию
	{
		IN rc;
		copy_CODE(rc.code);
		std::fstream input(infile); 
		rc.size = -1; rc.lines = 1; rc.ignor = 0;
		rc.text = new unsigned char[IN_MAX_LEN_TEXT];
		int position = 0;
		unsigned char ch = input.get();
		while (!input.eof())
		{
			position++;
			switch (rc.code[ch])
			{
			case rc.F: f(111, rc.lines, position, stream); break;

			case rc.T: rc.text[++rc.size] = (char)ch; break;
			case rc.I: rc.ignor++; break;
			case rc.E: ++rc.lines; rc.text[++rc.size] = ch; position = 0; break;
			default: rc.text[++rc.size] = rc.code[ch]; break;
			}
			ch = input.get();
		} 
		rc.text[rc.size+1] = 0x00;
		input.close();
		return rc;
	}
}
