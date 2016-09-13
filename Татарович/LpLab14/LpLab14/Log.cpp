#include "stdafx.h"
#include "Error.h"
#include "In.h"
#include "Log.h"
#include "Parm.h"
#include <ctime>
#define LINE_MAX_SIZE 1000

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG* rc = new LOG;
		wcscpy_s(rc->logfile, logfile);
		rc->stream = new std::ofstream (logfile);
		if (rc->stream==NULL) throw ERROR_THROW(112)
		return *rc;
	}
	void WriteLine(LOG log, char* c, ...)
	{
		char** rc = &c;
		char s[LINE_MAX_SIZE] = "";
		while (*rc!="") { strcat(s, *rc); rc++; }
		*log.stream << s << IN_CODE_ENDL;
	}
	void WriteLine(LOG log, wchar_t* c, ...)//
	{
		wchar_t** rc = &c;
		wchar_t s[LINE_MAX_SIZE] = L"";
		while (*rc != L""){ 
			wcscat_s(s,*rc); 
			rc++; }
		char current[LINE_MAX_SIZE]= "";
		wcstombs(current, s, wcslen(s));
		*log.stream << current << IN_CODE_ENDL;
	}
	void WriteLog(LOG log)
	{
		time_t sec_time;
		char buff[LINE_MAX_SIZE] = "";

		time(&sec_time);
		strftime(buff, 50, "%d.%m.%Y. %X", localtime(&sec_time)); 

		WriteLine(log, "------ �������� ------ ", "\n","����: ", buff, "");
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		WriteLine(log, L"------ ��������� ------ ", L"\n", L"-log: ", parm.log, L"\n", L"-out: ", parm.out, L"\n", L"-in: ", parm.in, L"");
	}
	void WriteIn(LOG log, In::IN in)
	{
		*log.stream << "------ �������� ������ ------" << IN_CODE_ENDL;
		*log.stream << "����� ��������: " << in.size << IN_CODE_ENDL;
		*log.stream << "����� �����: " << in.lines << IN_CODE_ENDL;
		*log.stream << "���������: " << in.ignor << IN_CODE_ENDL;
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		*log.stream << "������ " << error.id << ": " << error.message << IN_CODE_ENDL;
		*log.stream << "������: " << error.inext.line << " �������: " << error.inext.col << IN_CODE_ENDL;
	}
	void Close(LOG log)
	{
		log.stream->close();
	}
}
