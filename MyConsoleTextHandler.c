// Manipulacion de la consola
#include <windows.h>

//enum Colors 
//{ 
//	BLACK 	= 0,  	BLUE 	= 1,  	GREEN 	= 2, 	CYAN 	= 3,
// 	RED 	= 4, 	MAGENTA = 5, 	BROWN 	= 6, 	LGREY 	= 7,
//
// 	DGREY 	= 8, 	LBLUE 	= 9, 	LGREEN 	= 10, 	LCYAN 	= 11,
// 	LRED 	= 12, 	LMAGENTA= 13, 	YELLOW 	= 14, 	WHITE 	= 15
//};

void gotoxy(int px,int py) 
{
	HANDLE Console;
	COORD  hPos1;
	Console         = GetStdHandle(STD_OUTPUT_HANDLE);
	hPos1.X         = px;
	hPos1.Y         = py;
	SetConsoleCursorPosition(Console, hPos1);
}

void FnSetColor (int piFondo, int piColor) { 
	HANDLE Console;
	Console         = GetStdHandle(STD_OUTPUT_HANDLE); 
	int New_Color       = (piFondo * 16) + piColor; 
	SetConsoleTextAttribute(Console, New_Color); 
}
