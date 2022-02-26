#include <Windows.h>
#include <tchar.h>
#include <string>
#include <ctime>
#include <sstream>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");

int WINAPI _tWinMain(HINSTANCE This,		 // ���������� �������� ���������� 
HINSTANCE Prev, 	// � ����������� �������� ������ 0 
LPTSTR cmd, 		// ��������� ������ 
int mode) 		// ����� ����������� ����
{ 
HWND hWnd;	// ���������� �������� ���� ��������� 
MSG msg; 		// ��������� ��� �������� ��������� 
WNDCLASS wc; 	// ����� ����
// ����������� ������ ���� 
wc.hInstance = This; 
wc.lpszClassName = WinName; 				// ��� ������ ���� 
wc.lpfnWndProc = WndProc; 					// ������� ���� 
wc.style = CS_HREDRAW | CS_VREDRAW; 			// ����� ���� 
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// ����������� ������ 
wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// ����������� ������ 
wc.lpszMenuName = NULL; 					// ��� ���� 
wc.cbClsExtra = 0; 						// ��� �������������� ������ ������ 
wc.cbWndExtra = 0; 						// ��� �������������� ������ ���� 
wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+1); 	// ���������� ���� ����� ������ 


// ����������� ������ ����
if (!RegisterClass(&wc)) return 0; 	

// �������� ���� 
hWnd = CreateWindow(WinName,			// ��� ������ ���� 
_T("���� ��������"), 		// ��������� ���� 
WS_OVERLAPPEDWINDOW, 		// ����� ���� 
CW_USEDEFAULT,				// x 
CW_USEDEFAULT, 				// y	 ������� ���� 
CW_USEDEFAULT, 				// width 
CW_USEDEFAULT, 				// Height 
HWND_DESKTOP, 				// ���������� ������������� ���� 
NULL, 						// ��� ���� 
This, 						// ���������� ���������� 
NULL); 					// �������������� ���������� ��� 

ShowWindow(hWnd, mode); 				// �������� ����


// ���� ��������� ��������� 
while(GetMessage(&msg, NULL, 0, 0)) 
{ 
TranslateMessage(&msg); 		// ������� ���������� ����� ������� ������� 
DispatchMessage(&msg); 		// �������� ��������� ������� WndProc() 
} 
return 0;
}

// ������� ������� ���������� ������������ ��������
// � �������� ��������� �� ������� ��� ������� ����������
int line (int a, HDC hdc)
{
	int x = 300;
	int y = 240;
	while (a>0)
	{
		Rectangle (hdc, x, y, x+20, y+10);
		x= x+ 50;
		a=a-1;
	}
	return 0;
}
int flag = 10;
static HWND hStat, hStat1;
static HWND hEdt1;
char ch[20];
int random;
LPCWSTR RandomWord;
int vict;
static HWND *latter = new HWND[random];
int Game (HWND hstat, LPCWSTR word, int word_count, char* ch, HWND *latter)
{
	int raz=0;
	int st = 0;
	for (int i=0; word_count > i; i++)
	{
		raz = int(word[i]) - int(ch[0]);
		if (raz == 1104) 
		{
			SetWindowTextA(latter[i],ch);
			st = 1;
			vict = vict - 1;
		}
			
	};
	if (st == 0) flag = flag - 1;
	return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{ 
	
	int sx, sy; // ��� �������� ��������� ����
	static HWND Bt1, Bt2, Bt3; //���������� �������
	 //���������� ���� �����
	
	//LPCWSTR word [10] = { L"��������",  L"��������",  L"�������������",  L"��������", 
	//	 L"��������",  L"���������",  L"��������������",  L"�����������", L"�������",  L"������" };
	LPCWSTR word [10] = { L"��������",  L"��������",  L"��������",  L"��������", 
		 L"��������",  L"��������",  L"��������",  L"��������", L"��������",  L"��������" };
	/*int word_count [10] = {8, 8, 13, 8, 8, 9, 14, 11, 7, 6};*/
	int word_count [10] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	
	std::wstring  text = L"�������� �������: ";
	
	HDC hdc;
	std::wstring popitka = L"10";
	
	
switch(message)		 // ���������� ���������
{ 
	case WM_CREATE:
		Bt1= CreateWindow(TEXT("button"), TEXT("������"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  300, 120,
  500, 100,
  hWnd,
  NULL,
  NULL, NULL);
		Bt2= CreateWindow(TEXT("button"), TEXT("����� �� ����"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  300, 240,
  500, 100,
  hWnd,
  NULL,
  NULL, NULL);
		break;
	case WM_COMMAND:
		hdc = GetDC(hWnd);
		if (lParam == (LPARAM)Bt2)    // ���� ������ �� ������
    {
		PostQuitMessage(0); 
	};
		if (lParam == (LPARAM)Bt1)    // ���� ������ �� ������
    {
		DestroyWindow (Bt1);
		DestroyWindow (Bt2);
			hStat = CreateWindow(TEXT("STATIC"),(text+popitka).c_str(),
    WS_VISIBLE | WS_CHILD | SS_CENTER | SS_CENTERIMAGE,
    10,10,
	300,50,hWnd,(HMENU)1,NULL,NULL);
    ShowWindow(hStat, SW_SHOWNORMAL);
			hEdt1 = CreateWindow(TEXT("edit"), NULL,
      WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_LOWERCASE, 300, 300, 200, 100,
      hWnd, NULL, NULL, NULL);
			Bt3= CreateWindow(TEXT("button"), TEXT("��������� �����"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  700, 300,
  200, 60,
  hWnd,
  NULL,
  NULL, NULL);
		srand( time( 0 ) );
		random = word_count[rand() % 9];
		RandomWord = word[random];
		vict = random;
		hdc = GetDC(hWnd);
		sx= 300;
		for(int i =0; random >i; i++)
		{
			latter[i]= CreateWindow(TEXT("STATIC"),NULL,
			WS_VISIBLE | WS_CHILD | SS_CENTER | SS_CENTERIMAGE,
			sx,220,
			30,20,hWnd,(HMENU)1,NULL,NULL);
			sx = sx+50;
		}

		line(random, hdc);
	
		//Game(hEdt1, hWnd, RandomWord, random);
	};
		if (lParam == (LPARAM)Bt3)
		{
			
			GetWindowTextA(hEdt1, ch, 10);
			Game(hStat1, RandomWord, random, ch, latter);
			hdc = GetDC(hWnd);
			if (flag == 0) 
			{
				DestroyWindow (Bt3);
			CreateWindow(TEXT("STATIC"),TEXT("�� ��������"),
			WS_VISIBLE | WS_CHILD | SS_CENTER | SS_CENTERIMAGE,
			700, 300,
			200, 60,
			hWnd,(HMENU)1,NULL,NULL);			
			}
			else
				if (vict == 0)
				{
					DestroyWindow (Bt3);
			CreateWindow(TEXT("STATIC"),TEXT("�� �������"),
			WS_VISIBLE | WS_CHILD | SS_CENTER | SS_CENTERIMAGE,
			700, 300,
			200, 60,
			hWnd,(HMENU)1,NULL,NULL);		
				}
			else
			{
				popitka = std::to_wstring(flag);
				SetWindowText(hStat, (text+popitka).c_str());
			}
	
			
			
		}
		break;
	case WM_DESTROY : 
PostQuitMessage(0); 
break; 			// ���������� ��������� 
default : 			// ��������� ��������� �� ��������� 
return DefWindowProc(hWnd, message, wParam, lParam); 
} 
return 0;
}