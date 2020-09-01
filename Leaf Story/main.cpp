#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#include "Scene.h"

void main()
{
	float timeDelta = 0.0f;		//한번의 렌더링을 수행한 시간
	float lastTime = 0.0f;		//마지막으로 렌더링 완료한 시간

	float Timer = 0.0f;			//타이머
	int FrameCount = 0;			//Frame 카운트
	int FPS = 0;				//Frame Per Second(초당 프레임 수)

	

	//Draw 초기화
	DrawInit();

	//창 이름 변경
	SetConsoleTitle(TEXT("5415052 최철민"));

	while (true)
	{
		//랜덤 시드값 초기화
		srand((int)time(NULL));

		//현재 시간 가져오기
		float currentTime = clock() * 0.001;
		//이전 시간과 현재 시간의 차로 TimeDelta 구하기
		timeDelta = currentTime - lastTime;

		//화면 지우기
		Clear(false);

		//키보드 입력 업데이트
		InputUpdate();

		//렌더링(Rendering)
		if (!SceneRender(timeDelta)) break;

		removebar(timeDelta);
		//화면전환, Flipping
		Flipping();

		//렌더링 후, 키보드 입력 후 업데이트
		InputLateUpdate();

		//현재 시간을 이전 시간으로 저장하기
		lastTime = currentTime;
		//Frame Per Second 측정
		Timer += timeDelta;
		FrameCount++;			//Frame 카운트
								//1초가 될 때 마다 수행
		if (Timer >= 1.0f)
		{
			//FPS 저장
			FPS = FrameCount;
			//카운트 초기화
			FrameCount = 0;
			//타이머 초기화(0초부터 다시 시작)
			Timer = 0.0f;
		}
	}
}

