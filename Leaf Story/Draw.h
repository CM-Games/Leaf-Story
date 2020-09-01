#ifndef __DRAW_H__
#define __DRAW_H__

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

//색상 매크로 정의
#define RED				(FOREGROUND_RED | FOREGROUND_INTENSITY)
#define GREEN			(FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define GREEN2	(62)
#define BLUE			(FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define PURPLE			(RED | BLUE)
#define WHITE			(RED | GREEN | BLUE)
#define YELLOW			(RED | GREEN)
#define SKYBLUE			(GREEN | BLUE)
#define MINT		(0x3)
#define GARY		(RED & BLUE)


#define BG_RED			(BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_GREEN		(BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_BLUE			(BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BG_PURPLE		(BG_RED | BG_BLUE)
#define BG_WHITE		(BG_RED | BG_GREEN | BG_BLUE)
#define BG_YELLOW		(BG_RED | BG_GREEN)
#define BG_SKYBLUE		(BG_GREEN | BG_BLUE)
#define BG_GARY		(BG_RED & BG_BLUE)

//창 크기
#define WIDTH 145
#define HEIGHT 40

//Draw Init 함수
void DrawInit();
//Draw 함수
void Draw(int x, int y, int color, char *text, ...);
//버퍼(화면) 업데이트
void Flipping();
//화면 정리
void Clear(bool cls);

#endif

