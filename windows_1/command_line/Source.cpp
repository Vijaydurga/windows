//to pass command line arguments to program
#include<stdio.h>
#include<windows.h>
#include<shellapi.h>
#include<tchar.h>
using namespace std;
int  main()
{
	LPWSTR *SZarglist;   //long pointer to store arguments
	int nargs, i;
	SZarglist = CommandLineToArgvW(GetCommandLineW(), &nargs);
	if (NULL == SZarglist)
	{
		wprintf(L"No CommandLineToArgv arguments");
		return 0;
	}
	else for (i = 0; i < nargs; i++)   //printing of arguments
	{
		_tprintf(_T("[%d]:%s"), i, SZarglist[i]);

	}
	system("pause");
}