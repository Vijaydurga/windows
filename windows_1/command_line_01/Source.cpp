#include<Windows.h>
#include<stdio.h>
#include<tchar.h>
using namespace std;
void DumpEnvstrings(PTSTR pEnvBlock[])
{
	int current = 0;
	PTSTR *pelement = (PTSTR*)pEnvBlock;
	PTSTR pcurrent = NULL;
	while (pelement != NULL)
	{
		pcurrent = (PTSTR)(*pelement);
		if (pcurrent == NULL)
			pelement = NULL;
		else
		{
			_tprintf(_T("[%u]%s/r/n"), current, pcurrent);
			current++;
			pelement++;
		}

	}
}
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvstrings(env);
	TCHAR envvarstring0[] =TEXT("%windir%");
	TCHAR envvarstring1[] = TEXT("%systemroot%");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envvarstring0, buffer, MAX_PATH);
	if (!ret)
		printf("%d\n", GetLastError());
	else
		printf("%S\n", buffer);
	ret = ExpandEnvironmentStrings(envvarstring1, buffer, MAX_PATH);
	if (!ret)
		printf("%d\n", GetLastError());
	else
		printf("%S\n", buffer);
	getchar();
	return 0;
}
