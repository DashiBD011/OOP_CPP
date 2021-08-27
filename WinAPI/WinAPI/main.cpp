#include<Windows.h>
#include"resource.h"

CONST CHAR* cb_content[] =
{
	"This","is","my","first","Combo","Box"
};

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

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

		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
		for (int i = 0; i < sizeof(cb_content) / sizeof(cb_content[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)cb_content[i]);
		}
		
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{

			//MessageBox(NULL, "Была нажата кнопка ОК", "Info", MB_ICONINFORMATION | MB_OK); 
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			INT i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			CHAR sz_buffer[256]{};
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
			CHAR sz_msg[256]{};
			strcpy(sz_msg, "Вы выбрали какой-то пункт: ");
			strcat(sz_msg, sz_buffer);
			MessageBox(hwnd, sz_msg, "Info: ", MB_ICONINFORMATION | MB_OK);			
		}
		break;
		case IDCANCEL: EndDialog(hwnd, 0); break;

		}
	}
	break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return false;
}