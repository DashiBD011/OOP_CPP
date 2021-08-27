#include<Windows.h>
#include"resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

CONST CHAR* LIST_CONTENT[] =
{
	"This",
	"is",
	"my",
	"first",
	"ListBox"
};

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//MessageBox(NULL, "Это мое первое окно, созданное в WinAPI", "Info MessageBox", MB_ICONINFORMATION | MB_YESNOCANCEL); // MB - message box
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon);
		HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		for (int i = 0; i < sizeof(LIST_CONTENT) / sizeof(LIST_CONTENT[0]); i++)
		{
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)LIST_CONTENT[i]);
		}
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			HWND hList = GetDlgItem(hwnd, IDC_LIST1);
			int i = SendMessage(hList, LB_GETCURSEL, 0, 0);
			//MessageBox(NULL, LIST_CONTENT[i], "Вы выбрали ", MB_ICONINFORMATION | MB_OK);
			CHAR sz_buffer[256] = {};
			SendMessage(hList, LB_GETTEXT, 0, (LPARAM)sz_buffer);
			MessageBox(NULL, sz_buffer, "Вы выбрали ", MB_ICONINFORMATION | MB_OK);

			//MessageBox(NULL, "Была нажата кнопка ОК", "Info", MB_ICONINFORMATION | MB_OK); break;
		}
		case IDCANCEL: EndDialog(hwnd, 0); break;

		}
	}
	break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return false;
}