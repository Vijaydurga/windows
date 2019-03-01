
//To open an existing file ,read its contents and print them to the console untill the end of the file


#include<Windows.h>
#include<tchar.h>
#include<stdio.h>

//
#define BUFFSIZE 100

int _tmain(int argc, LPTSTR argv[])
{
	HANDLE hFile;                    //creating handle to file
	TCHAR buffer[BUFFSIZE]=L"got it";
	
	if (argc != 2) {
		printf("pass file name to open\n");
		return FALSE;
	}

	//to create a new file
	hFile = CreateFile(argv[1],
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	//checking whether file is present or not 
	if (INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(_T("File doesn't exist.Error(%ld)\n"), GetLastError());
		getchar();
		return FALSE;
	}
	else
		_tprintf(_T("File (%s) opened sucessfully\n"), argv[1]);
	DWORD dwNbr;  //double word variable for storing the count of number of bytes read
				  // reading the contents of the file into the buffer
	//while (1)
	//{
		//memset(buffer, 0, BUFFSIZE);
		//ZeroMemory(buffer, BUFFSIZE);
		BOOL ret = WriteFile(hFile, buffer, sizeof(buffer), &dwNbr, NULL);
		if (ret == FALSE)
		{
			_tprintf(_T("cannot read file"));
			getchar();
			CloseHandle(hFile);
			return FALSE;
		}
		/*else if (ret == TRUE && dwNbr == 0)
		{
			_tprintf(_T("Reached End Of File"));
			CloseHandle(hFile);
			//break;
		}
		else
		{
			_tprintf(_T("%s\n"), buffer));
		}

	}// end while*/
	 //printing the contents of the file

	 //_tprintf(_T("Contents of file (%s):% \n"), argv[1], buffer);
		system("pause");
	return 0;
}