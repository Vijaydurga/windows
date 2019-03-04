/*to create child processes and print their details*/
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
//parent process
void _tmain(int argc, LPTSTR argv[])
{
	STARTUPINFO si1;            //structures for processes
	PROCESS_INFORMATION pi1;
	DWORD dwPriorityClass ;
	ZeroMemory(&si1, sizeof(si1));   //initializing structure pointer to 0
	ZeroMemory(&pi1, sizeof(pi1));
	BOOL ret = 0;
	//creating child process
	ret = CreateProcess(NULL, argv[1], NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1);
	//checking for process creation and printing process id and handle
	if (!ret)
		printf("CreateProcess failed (%d).\n", GetLastError());
	else 
		printf("created child process\n");
	ret=SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	// Close  thread handles.
	CloseHandle(pi1.hThread);
	system("pause");
}