#include<Windows.h>
#include<stdio.h>
CRITICAL_SECTION object1;
long int g_integer = 0;
DWORD WINAPI Thread_func1(LPVOID lparam)
{
	EnterCriticalSection(&object1);
	
	g_integer++;
	printf("entered critical section of Thread1\n");
	LeaveCriticalSection(&object1);
		return 0;
}
DWORD WINAPI Thread_func2(LPVOID lparam)
{
	EnterCriticalSection(&object1);
	
	g_integer++;
	printf("entered critical section of Thread2\n");
	LeaveCriticalSection(&object1);
	return 0;
}
int main()
{   
	InitializeCriticalSection(&object1);
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hThread1, hThread2;
	HANDLE arr[2];
	
	hThread1 = CreateThread(NULL, 0, Thread_func1, NULL, 0, &dwThreadId1);
	arr[0] = hThread1;
	hThread2 = CreateThread(NULL, 0, Thread_func2, NULL, 0, &dwThreadId2);
	arr[1] = hThread2;
	WaitForMultipleObjects(MAXIMUM_WAIT_OBJECTS,arr,TRUE, 2000);
	printf("value of shared object is %d\n", g_integer);
	DeleteCriticalSection(&object1);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	
	getchar();
}