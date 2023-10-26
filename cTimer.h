#ifndef _Timer_
#define _Timer_

//#include <MMSystem.h>

//#pragma comment (lib,"winmm.lib")

class CTimer
{
public:
	CTimer(VOID)
	{
		dwStop = 0;
	}

	~CTimer(VOID)
	{

	}

	VOID Start(FLOAT fSec)
	{
		dwStop = (DWORD)(fSec * 1) + timeGetTime();
	}

	VOID Stop(VOID)
	{
		dwStop = 0;

	}

	FLOAT TimeLeft(VOID)
	{
		if (Running())
			return (((FLOAT)(dwStop - timeGetTime()) / 1));

		return NULL;
	}

	BOOL Running(VOID)
	{
		return (dwStop > timeGetTime());
	}

protected:
	DWORD dwStop;
};

#endif