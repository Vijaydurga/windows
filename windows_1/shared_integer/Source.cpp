#include<Windows.h>
#include<stdio.h>
#include<winbase.h>
long int g_integer;
//thread function
DWORD WINAPI thread_func1(LPVOID lparam)
{
	g_integer++;
	//printf("incremented value in thread function 1 %d\n", g_integer);
	return 0;
}
DWORD WINAPI thread_func2(LPVOID lparam)
{
	g_integer++;
	//printf("incremented value in thread function 2 %d \n", g_integer);
	
	return 0;
}
int main()
{

	DWORD dwThreadId1,dwThreadId2;  //variable to strore thread id
	HANDLE hThread1,hThread2;    //handle for thread
	
	/*Checking whether thread is created or not
	if (hThread1 == NULL)
		printf("thread1 is not created\n");
	else
		printf("thread1 created \n");
	
	if (hThread2 == NULL)
		printf("thread2 is not created\n");
	else
		printf("thread2 created \n");
	//waiting for the thread to close*/
	while (1)
	{//creating thread 
		g_integer = 0;
		hThread1 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dwThreadId1);
		hThread2 = CreateThread(NULL, 0, thread_func2, NULL, 0, &dwThreadId2);
		
		printf("value of shared integer is : %d\n", g_integer);
		WaitForSingleObject(hThread1, 1000);
		WaitForSingleObject(hThread2, 1000);
		if (g_integer == 1)
			break;
	}
	//closing the thread of the process
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	system("pause");
}