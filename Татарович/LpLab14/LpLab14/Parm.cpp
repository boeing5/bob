#include "stdafx.h"
#include "Parm.h"
#include "wchar.h"
#define IN_CODE_ENDL "\n"

namespace Parm
{
	bool copy_parm(wchar_t* dest, int size, wchar_t* source[], wchar_t* parm)
	{
		bool rc = false;
		int i = 0;

		while (i < size && wcsstr(source[i], parm) == NULL) i++;
		if (i < size && parm == PARM_IN) { wcscpy_s(dest, wcslen(source[i]), source[i] + 4); rc = true; }
		else if (i < size) { wcscpy_s(dest, wcslen(source[i]) ,source[i]+5); rc = true; }
		return rc;
	}
	PARM getparm(int argc, _TCHAR* argv[]) // убираем поток делаем throw по id ++
	{
		PARM rc;
		if (argc < 2) throw 100;
		for (int i = 1; i < argc; i++) if (wcslen(argv[i]) > PARM_MAX_SIZE) throw 104;

		if (!copy_parm(rc.in, argc, argv, PARM_IN)) throw 100;
		if (!copy_parm(rc.out,argc,argv,PARM_OUT)) { wcscpy_s(rc.out, rc.in); wcsncat_s(rc.out, PARM_OUT_DEFAULT_EXT, sizeof(PARM_OUT_DEFAULT_EXT)+1); }
		if (!copy_parm(rc.log,argc,argv,PARM_LOG)) { wcscpy_s(rc.log, rc.in); wcsncat_s(rc.log, PARM_LOG_DEFAULT_EXT, sizeof(PARM_LOG_DEFAULT_EXT)+1); }

		return rc;
	}
}