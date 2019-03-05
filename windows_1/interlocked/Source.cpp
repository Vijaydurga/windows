#include<Windows.h>
#include<stdio.h>
#include<intrin.h>
long int g_integer = 0;
//thread function
DWORD WINAPI thread_func1(LPVOID lparam)
{
	//printf("incrementing in thread function 1\n");
	InterlockedExchangeAdd(&g_integer, 1);
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lparam)
{
	//printf("incrementing in thread function 2\n");
	InterlockedExchangeAdd(&g_integer, 1);
	return 0;
}
int main()
{

	DWORD dwThreadId1, dwThreadId2;  //variable to strore thread id
	HANDLE hThread1, hThread2;    //handle for thread
	
	/*Checking whether thread is created or not
	if (hThread1 == NULL)
		printf("thread1 is not created\n");
	else
		printf("thread1 created \n");
	
	if (hThread2 == NULL)
		printf("thread2 is not created\n");
	else
		printf("thread2 created \n");*/
	while (1)
	{
		hThread1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dwThreadId1);
		hThread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &dwThreadId2);
		//waiting for the thread to close
		WaitForSingleObject(hThread1, 1000);
		WaitForSingleObject(hThread2, 1000);
		printf("value of shared integer is : %d\n", g_integer);
		if (g_integer == 1)
			break;
	}
	//closing the thread of the process
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	system("pause");
}