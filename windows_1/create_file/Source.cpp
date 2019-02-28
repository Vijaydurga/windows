
//To open an existing file ,read its contents and print them to the console untill the end of the file


#include<Windows.h>
#include<tchar.h>
#include<stdio.h>

//
#define BUFFSIZE 10

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;                    //creating handle to file
	char buffer[BUFFSIZE] ;

	if (argc != 2) {
		printf("pass file name to open\n");
		return FALSE;
	}
	_tprintf(_T("filename %s\n"), argv[1]);

	//to open an existing file
	hFile =CreateFile(L"C://Users//cdac//Source//Repos//Vijaydurga//windows//windows_1//create_file//create_file.txt",
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	//checking whether file is present or not 
	if ( INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(_T("File doesn't exist.Error(%ld)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	else
	_tprintf(_T("File (%s) opened sucessfully\n"), argv[1]);
	DWORD dwNbr;  //double word variable for storing the count of number of bytes read
	// reading the contents of the file into the buffer
	while (1)
	{
		memset(buffer,0,BUFFSIZE);
		//ZeroMemory(buffer, BUFFSIZE);
		BOOL ret = ReadFile(hFile, buffer, BUFFSIZE, &dwNbr, NULL);
		if (ret == 0)
		{
			_tprintf(_T("cannot read file"));
			getchar();
			CloseHandle(hFile);
			return FALSE;
		}
		else if (ret == TRUE && dwNbr == 0)
		{
			_tprintf(_T("Reached End Of File"));
			CloseHandle(hFile);
				break;
		}
		else
		{
			/*for (int i = 0; i < dwNbr; i++)
			{
				printf("%c",buffer[i]);
			}*/
			printf("%s\n",buffer);
		}

	}// end while
	//printing the contents of the file
	
	//_tprintf(_T("Contents of file (%s):% \n"), argv[1], buffer);
	getchar();
	return 0;
}