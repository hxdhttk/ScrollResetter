#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")

int desiredLines = 2;

int main(int argc, char** argv)
{
	if (argc >= 2)
	{
		desiredLines = atoi(argv[1]);
	}
	else
	{
		desiredLines = 2;
	}

	BOOL fResult;
	UINT uiScrollLines;

	fResult = SystemParametersInfo(SPI_GETWHEELSCROLLLINES,
		0,
		&uiScrollLines,
		0);

	if (fResult && (uiScrollLines != desiredLines))
	{
		if (!SystemParametersInfo(SPI_SETWHEELSCROLLLINES,
			desiredLines,
			NULL,
			SPIF_SENDCHANGE))
		{
			DWORD error = GetLastError();
			printf("Error code: %ld", error);
		}
	}
}