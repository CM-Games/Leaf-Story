#include "Draw.h"

//���۹迭 ����
int MainBuffer[2][HEIGHT][WIDTH];
int BackBuffer[2][HEIGHT][WIDTH];

void DrawInit()
{
	//���� 2�� �ʱ�ȭ
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			for (int k = 0; k < WIDTH; k++)
			{
				//i=0 : �ؽ�Ʈ / i=1 : ��������
				MainBuffer[i][j][k] = 0;
				BackBuffer[i][j][k] = 0;
			}
		}
	}
	//ȭ��ũ�� ����
	char tmp[128];
	sprintf(tmp, "mode con:cols=%d lines=%d", WIDTH, HEIGHT);
	system(tmp);
}

void Draw(int x, int y, int color, char *text, ...)
{
	//"..."�� ���� ���� �������� ���ڿ��� ó���ϱ� ���� ���
	va_list va_ptr;
	char msg[512] = { NULL, };
	va_start(va_ptr, text);
	vsprintf(msg, text, va_ptr);
	va_end(va_ptr);
	//���� ����
	for (int i = 0; i < strlen(msg); i++)
	{
		BackBuffer[0][y][x + i] = *(msg + i);
		BackBuffer[1][y][x + i] = color;
	}
}

//Ŀ����ġ ���� �Լ�
void GotoXY(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//����(ȭ��) ������Ʈ
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

//ȭ����ü ����
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