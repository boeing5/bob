#include "stdafx.h"

using namespace std;
using namespace In;

namespace Log
{
	IN getin(wchar_t infile[], LOG log)
	{
		IN myIn;

		int tempCode[256] = IN_CODE_TABLE;

		for (int i = 0; i < 256; i++)
		{
			myIn.code[i] = tempCode[i];
		}

		int position = 0;

		myIn.size = 0;
		myIn.lines = 1;
		myIn.ignor = 0;
		myIn.kolError = 0;
		myIn.text = new char[IN_MAX_LEN_TEXT];

		ifstream inFile;
		inFile.open(infile);

		if (!inFile)
		{
			throw ERROR_THROW(110);
		}
		else
		{
			char tempChar;
			while ((tempChar = inFile.get()) && !inFile.eof())
			{
				if (tempChar == IN_CODE_ENDL)
				{
					myIn.text[myIn.size] = IN_CODE_ENDL;
					myIn.lines++;
					position = 0;
				}
				else if (myIn.code[tempChar] == myIn.F)
				{
					WriteError(log, Error::geterrorin(111, (myIn.lines - 1), position));
					myIn.kolError++;
				}
				else if (myIn.code[tempChar] == myIn.T)
				{
					myIn.text[myIn.size] = tempChar;
				}
				else if (myIn.code[tempChar] == myIn.I)
				{
					myIn.ignor++;
					continue;
				}
				else
				{
					myIn.text[myIn.size] = '!';
				}
				position++;
				myIn.size++;
			}

			myIn.text[myIn.size] = '\0';

			inFile.close();
		}

		if (myIn.size == 0)
		{
			myIn.lines = 0;
		}


		return myIn;
	}
}
