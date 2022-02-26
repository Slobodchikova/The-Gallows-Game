#include <Windows.h>
#include <tchar.h>
#include <string>
#include <ctime>
#include <sstream>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");

int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
HINSTANCE Prev, 	// В современных системах всегда 0 
LPTSTR cmd, 		// Командная строка 
int mode) 		// Режим отображения окна
{ 
HWND hWnd;	// Дескриптор главного окна программы 
MSG msg; 		// Структура для хранения сообщения 
WNDCLASS wc; 	// Класс окна
// Определение класса окна 
wc.hInstance = This; 
wc.lpszClassName = WinName; 				// Имя класса окна 
wc.lpfnWndProc = WndProc; 					// Функция окна 
wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
wc.lpszMenuName = NULL; 					// Нет меню 
wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+1); 	// Заполнение окна белым цветом 


// Регистрация класса окна
if (!RegisterClass(&wc)) return 0; 	

// Создание окна 
hWnd = CreateWindow(WinName,			// Имя класса окна 
_T("Игра виселица"), 		// Заголовок окна 
WS_OVERLAPPEDWINDOW, 		// Стиль окна 
CW_USEDEFAULT,				// x 
CW_USEDEFAULT, 				// y	 Размеры окна 
CW_USEDEFAULT, 				// width 
CW_USEDEFAULT, 				// Height 
HWND_DESKTOP, 				// Дескриптор родительского окна 
NULL, 						// Нет меню 
This, 						// Дескриптор приложения 
NULL); 					// Дополнительной информации нет 

ShowWindow(hWnd, mode); 				// Показать окно


// Цикл обработки сообщений 
while(GetMessage(&msg, NULL, 0, 0)) 
{ 
TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
} 
return 0;
}

// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения
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
	
	int sx, sy; // для размеров исходного окна
	static HWND Bt1, Bt2, Bt3; //дискриптор кнопкок
	 //дискриптор поля ввода
	
	//LPCWSTR word [10] = { L"морковка",  L"садовник",  L"индустриализм",  L"лампочка", 
	//	 L"акционер",  L"индикатор",  L"экваториальный",  L"минимизация", L"семечки",  L"ананас" };
	LPCWSTR word [10] = { L"ворковка",  L"ворковка",  L"ворковка",  L"ворковка", 
		 L"ворковка",  L"ворковка",  L"ворковка",  L"ворковка", L"ворковка",  L"ворковка" };
	/*int word_count [10] = {8, 8, 13, 8, 8, 9, 14, 11, 7, 6};*/
	int word_count [10] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	
	std::wstring  text = L"Осталось попыток: ";
	
	HDC hdc;
	std::wstring popitka = L"10";
	
	
switch(message)		 // Обработчик сообщений
{ 
	case WM_CREATE:
		Bt1= CreateWindow(TEXT("button"), TEXT("Играть"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  300, 120,
  500, 100,
  hWnd,
  NULL,
  NULL, NULL);
		Bt2= CreateWindow(TEXT("button"), TEXT("Выйти из игры"),
  WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
  300, 240,
  500, 100,
  hWnd,
  NULL,
  NULL, NULL);
		break;
	case WM_COMMAND:
		hdc = GetDC(hWnd);
		if (lParam == (LPARAM)Bt2)    // если нажали на кнопку
    {
		PostQuitMessage(0); 
	};
		if (lParam == (LPARAM)Bt1)    // если нажали на кнопку
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
			Bt3= CreateWindow(TEXT("button"), TEXT("Проверить букву"),
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
			CreateWindow(TEXT("STATIC"),TEXT("Ты проиграл"),
			WS_VISIBLE | WS_CHILD | SS_CENTER | SS_CENTERIMAGE,
			700, 300,
			200, 60,
			hWnd,(HMENU)1,NULL,NULL);			
			}
			else
				if (vict == 0)
				{
					DestroyWindow (Bt3);
			CreateWindow(TEXT("STATIC"),TEXT("Ты выиграл"),
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
break; 			// Завершение программы 
default : 			// Обработка сообщения по умолчанию 
return DefWindowProc(hWnd, message, wParam, lParam); 
} 
return 0;
}