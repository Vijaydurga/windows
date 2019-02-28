#include<stdio.h>
#include<windows.h>
#include<shellapi.h>
#include<tchar.h>
using namespace std;
int  main()
{
	LPWSTR *SZarglist;
	int nargs, i;
	SZarglist = CommandLineToArgvW(GetCommandLineW(), &nargs);
	if (NULL == SZarglist)
	{
		wprintf(L"CommandLineToArgv");
		return 0;
	}
	else for (i = 0; i < nargs; i++)
	{
		_tprintf(_T("[%d]:%s"), i, SZarglist[i]);

	}
	system("pause");

}