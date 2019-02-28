#include<stdio.h>
#include<windows.h>
int main()
{
	CHAR ansiarray[] = "ANSI";
	WCHAR widearray[] = L"WIDE";
	int ret, size;
	ret = IsTextUnicode(ansiarray, strlen(ansiarray), NULL);
	if (ret)
		printf("it is a wide char \n");
	else
		printf("it is not a wide char \n");
	ret = IsTextUnicode(widearray, wcslen(widearray), NULL);
	if (ret)
		printf("it is a wide char \n");
	else
		printf("it is not a wide char \n");
	printf("the error no is:%d \n", GetLastError());
	size = MultiByteToWideChar(CP_UTF8, 0, ansiarray, -1, NULL, 0);
	WCHAR *arr1 = new WCHAR[size];
	printf("the error no is:%d \n", GetLastError());
	MultiByteToWideChar(CP_UTF8, 0, ansiarray, -1, arr1, size);
	ret = IsTextUnicode(arr1, wcslen(arr1), NULL);
	if (ret)
		printf("it is a wide char \n");
	else
		printf("it is not a wide char \n");
	printf("the error no is:%d \n", GetLastError());
	size = WideCharToMultiByte(CP_UTF8, 0, widearray, -1, NULL, 0, NULL, NULL);
	CHAR *arr2 = new CHAR[size];
	WideCharToMultiByte(CP_UTF8, 0, widearray, -1, arr2, size,NULL,NULL);
	ret = IsTextUnicode(arr1, wcslen(arr1), NULL);
	if (ret)
		printf("it is a wide char \n");
	else
		printf("it is not a wide char \n");
	printf("the error no is:%d \n", GetLastError());

	getchar();
	return 0;
}