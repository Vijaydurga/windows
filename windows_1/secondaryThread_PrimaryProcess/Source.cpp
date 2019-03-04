#include<Windows.h>
#include<stdio.h>

DWORD WINAPI Thread_func(LPVOID lparam)
{
	printf("testing with threads\n");
	return 0;
}
int main()
{

	DWORD dwThreadId1;  //variable to strore thread id
	HANDLE hThread1;    //handle for thread
	DWORD dwExitCode = 0;					//creating thread 
	hThread1 = CreateThread(NULL, 0, Thread_func, NULL, 0, &dwThreadId1);
	//Checking whether thread is created or not
	if (hThread1 == NULL)
		printf("thread is not created");
	else
		printf("Thread created sucessfully\n");
	//waiting for the thread to close
	WaitForSingleObject(hThread1, 1000);
	BOOL ret = TerminateThread(hThread1, dwExitCode);
	printf("The exit code of the Thread is :%d",GetExitCodeThread(hThread1,&dwExitCode));
	
	//closing the thread of the process
	CloseHandle(hThread1);
	system("pause");
}