/*to create child processes and print their details*/
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
//parent process
void _tmain(int argc, LPTSTR argv[])
{
	STARTUPINFO si1;            //structures for processes
	PROCESS_INFORMATION pi1;
	STARTUPINFO si2;
	PROCESS_INFORMATION pi2;
	ZeroMemory(&si1, sizeof(si1));   //initializing structure pointer to 0
	ZeroMemory(&pi1, sizeof(pi1));
	ZeroMemory(&si2, sizeof(si2));
	ZeroMemory(&pi2, sizeof(pi2));
	BOOL ret = 0;
	//creating child process
	ret = CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1);
	//checking for process creation and printing process id and handle
	if (!ret)
		printf("CreateProcess failed (%d).\n", GetLastError());
	else {
		printf("first process id : %d\n", pi1.hProcess);
		printf("first process handle : %d\n", pi1.hThread);
	}
	//creating child process
	ret = CreateProcess(NULL, argv[2], NULL, NULL, TRUE, 0, NULL, NULL, &si2, &pi2);
	//checking for process creation and printing process id and handle
	if (!ret)
		printf("CreateProcess failed (%d).\n", GetLastError());
	else {
		printf("second process id : %d\n", pi2.hProcess);
		printf("second process handle : %d\n", pi2.hThread);
	}
	// Close  thread handles. 
	CloseHandle(pi1.hThread);
	CloseHandle(pi2.hThread);
	system("pause");
}