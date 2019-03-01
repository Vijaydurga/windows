#include<Windows.h>
#include<stdio.h>
#include<synchapi.h>
//thread function
DWORD WINAPI thread_func(LPVOID lparam)
{
	for (int i = 1; i <= 1000; i++)
		printf("%d  ", i);

	return 0;
}
int main()
{

	DWORD dwThreadId1;  //variable to strore thread id
	HANDLE hThread1;    //handle for thread
	//creating thread in suspended state
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, CREATE_SUSPENDED, &dwThreadId1);
	//thread is activated after 5sec
	Sleep(5000);  //sleep time in milliseconds
	ResumeThread(hThread1);  //resuming thread for execution
	if (hThread1 == NULL)
		printf("thread is not created");
	//waiting for the thread to close
	WaitForSingleObject(hThread1, 5000);
	//closing the thread of the process
	CloseHandle(hThread1);
	getchar();
}