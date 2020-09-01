#include "Draw.h"

//버퍼배열 생성
int MainBuffer[2][HEIGHT][WIDTH];
int BackBuffer[2][HEIGHT][WIDTH];

void DrawInit()
{
	//버퍼 2개 초기화
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			for (int k = 0; k < WIDTH; k++)
			{
				//i=0 : 텍스트 / i=1 : 색상정보
				MainBuffer[i][j][k] = 0;
				BackBuffer[i][j][k] = 0;
			}
		}
	}
	//화면크기 변경
	char tmp[128];
	sprintf(tmp, "mode con:cols=%d lines=%d", WIDTH, HEIGHT);
	system(tmp);
}

void Draw(int x, int y, int color, char *text, ...)
{
	//"..."을 통해 들어온 변수들을 문자열로 처리하기 위한 방법
	va_list va_ptr;
	char msg[512] = { NULL, };
	va_start(va_ptr, text);
	vsprintf(msg, text, va_ptr);
	va_end(va_ptr);
	//버퍼 쓰기
	for (int i = 0; i < strlen(msg); i++)
	{
		BackBuffer[0][y][x + i] = *(msg + i);
		BackBuffer[1][y][x + i] = color;
	}
}

//커서위치 지정 함수
void GotoXY(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//버퍼(화면) 업데이트
void Flipping()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (BackBuffer[0][i][j] != MainBuffer[0][i][j] || BackBuffer[1][i][j] != MainBuffer[1][i][j])
			{
				GotoXY(0, i);
				for (int k = 0; k < WIDTH; k++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BackBuffer[1][i][k]);
					printf("%c", (char)BackBuffer[0][i][k]);
					MainBuffer[0][i][k] = BackBuffer[0][i][k];
					MainBuffer[1][i][k] = BackBuffer[1][i][k];
				}
				break;
			}
		}
	}
	GotoXY(WIDTH, HEIGHT);
}

//화면전체 정리
void Clear(bool cls)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			for (int k = 0; k < WIDTH; k++)
			{
				BackBuffer[i][j][k] = 0;
			}
		}
	}
	if (cls == true) system("cls");
}