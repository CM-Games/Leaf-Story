#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <conio.h>

//��ǥ Ű�ڵ� ��
#define KEY_UP 0x48
#define KEY_LEFT 0x4B
#define KEY_RIGHT 0x4D
#define KEY_DOWN 0x50
#define KEY_ENTER 13
#define KEY_Z 122
#define KEY_X 120
#define KEY_A 97
#define KEY_ESC 27
#define KEY_ONE 49

//Ű���� �Է� - ������Ʈ �Լ�
void InputUpdate();
//Ű���� �Է� - �� ������Ʈ �Լ�
void InputLateUpdate();
//Ű���� �Է� Ȯ�� �Լ�
bool KeyDown(int keyCode);

extern int key;

#endif

