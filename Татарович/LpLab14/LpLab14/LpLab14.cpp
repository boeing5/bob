#include "stdafx.h"
#include "Error.h"
#include "Parm.h" 
#include "In.h"
#include "Log.h"
#include "FST.h"
#include "LexAnalyze.h"
#include <ctime>

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int ts = clock();
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv); 
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест:"," Без ошибок","");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in, log.stream, Error::writeerrorin);
		LA::LexAn((char*)in.text, log);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (int id)
	{
		std::cout << Error::writeerror(id);
	};
	system("pause");
	return 0;
}