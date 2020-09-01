#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "Scene.h"

void main()
{
	float timeDelta = 0.0f;		//�ѹ��� �������� ������ �ð�
	float lastTime = 0.0f;		//���������� ������ �Ϸ��� �ð�

	float Timer = 0.0f;			//Ÿ�̸�
	int FrameCount = 0;			//Frame ī��Ʈ
	int FPS = 0;				//Frame Per Second(�ʴ� ������ ��)

	

	//Draw �ʱ�ȭ
	DrawInit();

	//â �̸� ����
	SetConsoleTitle(TEXT("5415052 ��ö��"));

	while (true)
	{
		//���� �õ尪 �ʱ�ȭ
		srand((int)time(NULL));

		//���� �ð� ��������
		float currentTime = clock() * 0.001;
		//���� �ð��� ���� �ð��� ���� TimeDelta ���ϱ�
		timeDelta = currentTime - lastTime;

		//ȭ�� �����
		Clear(false);

		//Ű���� �Է� ������Ʈ
		InputUpdate();

		//������(Rendering)
		if (!SceneRender(timeDelta)) break;

		removebar(timeDelta);
		//ȭ����ȯ, Flipping
		Flipping();

		//������ ��, Ű���� �Է� �� ������Ʈ
		InputLateUpdate();

		//���� �ð��� ���� �ð����� �����ϱ�
		lastTime = currentTime;
		//Frame Per Second ����
		Timer += timeDelta;
		FrameCount++;			//Frame ī��Ʈ
								//1�ʰ� �� �� ���� ����
		if (Timer >= 1.0f)
		{
			//FPS ����
			FPS = FrameCount;
			//ī��Ʈ �ʱ�ȭ
			FrameCount = 0;
			//Ÿ�̸� �ʱ�ȭ(0�ʺ��� �ٽ� ����)
			Timer = 0.0f;
		}
	}
}

