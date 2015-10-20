// Author: liuhan (liuhan333@126.com)
// DoubleSnake.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"

#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
//#include <process.h>
#include "snake.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CSnake doubleSnake;
	doubleSnake.Init(500, 450, 540);

	//unsigned threadID;
	//Config config;
	//config.colorref  = RED;
	//HANDLE hThread1 = (HANDLE)_beginthreadex( NULL, 0, &Play, &config, 0, &threadID );
	//CloseHandle(hThread1);

	doubleSnake.Play2();
	closegraph();
	return 0;
}


