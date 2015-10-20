// Author: liuhan (liuhan333@126.com)

#include "stdafx.h"
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
//#include <process.h>
#include "snake.h"

CSnake::CSnake():
m_score(0),
m_gamespeed(NORMAL_SPEED),
m_wall_wide(1),
m_wall_high(1),
m_describe_begin(1),
m_die_snake(0)
{}

CSnake::~CSnake()
{}

void CSnake::Init(int iWallWide, int iWallHigh, int iDescribeBeginX)
{
	int gdriver = 9, gmode = 2;
	initgraph(&gdriver, &gmode, "");//BGI ��ʽ�ĳ�ʼ��ͼ���豸
	cleardevice();// ����
	setcolor(LIGHTCYAN);// ���õ�ǰ��ͼǰ��ɫ
	setlinestyle(PS_SOLID);// ���õ�ǰ������ʽ

	draw_wall(BEGIN_POS_X, BEGIN_POS_Y, iWallWide, iWallHigh);//��Χǽ����ʼ����(8,8)������(iWallWide,iWallHigh)
	draw_describe(iDescribeBeginX, 60, 19);//��Ϸ������������ʼ����(iDescribe,60)���и�19

	m_wall_wide = iWallWide;
	m_wall_high = iWallHigh;
	m_describe_begin = iDescribeBeginX;

}

bool CSnake::draw_wall(int iLeft, INT iTop, int iWide, int iHigh)
{
	const int iBrickDistance = BRICK_DEEP + BRICK_CHINK;
	for(int iLine = iLeft; iLine < iLeft + iWide; iLine += iBrickDistance)
	{
		//void fillrectangle (int left, int top, int right, int bottom);	// ��������(�б߿�)
		//��Χǽ������
		fillrectangle(iLine, iTop, iLine + BRICK_DEEP, iTop + BRICK_DEEP);
		fillrectangle(iLine, iTop + iHigh, iLine + BRICK_DEEP, iTop + iHigh + BRICK_DEEP);
	}

	for(int iColumn = iTop; iColumn < iTop + iHigh; iColumn += iBrickDistance)
	{
		//��Χǽ������
		fillrectangle(iLeft, iColumn, iLeft + BRICK_DEEP, iColumn + BRICK_DEEP);
		fillrectangle(iLeft + iWide, iColumn, iLeft + iWide + BRICK_DEEP, iColumn + BRICK_DEEP);
	}

	return true;
}

bool CSnake::draw_describe(int iBeginX, int iBeginY, int irowheight)
{
	int iHight = iBeginY;
	int iRow = 0 ;
	setcolor(RED);
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"���ߣ�");
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"i(��)");
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"j(��),l(��)");
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"k(��)");
	
	setcolor(BLUE);
	iRow++;
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"���ߣ�");
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"w(��)");
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"a(��),d(��)");
	outtextxy(iBeginX, iHight + (iRow++) * irowheight, L"s(��)");
	
	return true;
}

bool CSnake::create_food(Food& food)
{
	srand(time(NULL));

	//�������ʳ�������
	//��BRICK_DEEPȷ�����ɵ�ʳ��������++������պ��ܰ�����ǽ
	food.x = rand() % m_wall_wide + BEGIN_POS_X - BRICK_DEEP;
	food.y = rand() % m_wall_high + BEGIN_POS_Y - BRICK_DEEP;
	
	//�ߺ�ʳ�ﶼ��POS_UINT��������������
	while(food.x % POS_UINT != 0)
	{
		food.x++;
	}
	while(food.y % POS_UINT != 0)
	{
		food.y++;
	}

	food.eat = 0;

	return true;
}

bool CSnake::init_snake_pos(Snake& red_snake, Snake& blue_snake)
{
	red_snake.life = 1;
	red_snake.direction = DIRECT_RIGHT;
	red_snake.node = 3;

	red_snake.x[0] = 90;
	red_snake.x[1] = 100;
	red_snake.y[0] = 90;
	red_snake.y[1] = 90;

	blue_snake = red_snake;

	blue_snake.x[0] = 100;
	blue_snake.x[1] = 110;
	blue_snake.y[0] = 100;
	blue_snake.y[1] = 100;

	return true;
}

bool CSnake::snake_move(Snake& x_snake)
{
	if(0 == x_snake.life)
		return false;

	//������ǰ�ƶ�
	for( int i = x_snake.node -1;i>0;--i)
	{
		x_snake.x[i] = x_snake.x[i-1];
		x_snake.y[i] = x_snake.y[i-1];
	}

	//������ͷ����
	switch(x_snake.direction)
	{
	case DIRECT_RIGHT:
		x_snake.x[0] += POS_UINT;
		break;
	case DIRECT_LEFT:
		x_snake.x[0] -= POS_UINT;
		break;
	case DIRECT_UP:
		x_snake.y[0] -= POS_UINT;
		break;
	case DIRECT_DOWN:
		x_snake.y[0] += POS_UINT;
		break;
	}

	return true;
}

bool CSnake::life_check(Snake& x_snake)
{
	bool bLife = true;
	if(x_snake.life)
	{
		//����Ƿ�Ե��Լ����壬���0����(��ͷ)�Ƿ���3->nodeλ���غϼ��ɡ�
		for(int i = 3; i<x_snake.node; i++)
		{
			if((x_snake.x[i] == x_snake.x[0]) && 
				(x_snake.y[i] == x_snake.y[0]))
			{
				m_die_snake++;
				x_snake.life = 0;
				bLife = false;
				break;
			}
		}

		//����Ƿ�ײǽ
		if(bLife &&
			(x_snake.x[0] <= BRICK_DEEP + BEGIN_POS_X) || 
			(x_snake.x[0] >= BRICK_DEEP + BEGIN_POS_X + m_wall_wide) || 
			(x_snake.y[0] <= BRICK_DEEP + BEGIN_POS_Y) || 
			(x_snake.y[0] >= BRICK_DEEP + BEGIN_POS_Y + POS_UINT + m_wall_high))
		{
			m_die_snake++;
			x_snake.life = 0;
			bLife = false;
		}
	}
	else
	{
		bLife = false;
	}

	return bLife;
}

bool CSnake::draw_snake(Snake& x_snake, Food& food, COLORREF snake_color)
{
	if(0 == x_snake.life)
	{
		return false;
	}

	bool bEat = false;

	//�Ե�ʳ��
	if( 0 == food.eat &&
		x_snake.x[0] == food.x &&
		x_snake.y[0] == food.y)
	{
		setcolor(BLACK);
		rectangle(food.x, food.y, food.x+10, food.y-10);
		x_snake.x[x_snake.node] = -20;
		x_snake.y[x_snake.node] = -20;//�½ڵ���ڿ�������λ��

		//��ʳ�����һ��
		x_snake.node++;
		food.eat = 1;
		m_score += SCORE;
		bEat = true;

		//�Ե�ʳ��ˢ�·���
		draw_score();
	}

	setcolor(snake_color);
	setfont(WORD_HEIGHT, WORD_WIDTH, L"����");

	//����
	outtextxy(x_snake.x[0], x_snake.y[0]-POS_UINT, L"ͷ");
	for(int i = 1; i < x_snake.node; i++)
	{
		outtextxy(x_snake.x[i], x_snake.y[i]-POS_UINT, L"��");
	}
	
	//���û�Ե�ʳ�����ǰ��һ������һ��β���Ͻڵ��λ�þ�Ӧ����ա�
	if(!bEat)
	{
		setcolor(BLACK);
		outtextxy(x_snake.x[x_snake.node-1], x_snake.y[x_snake.node-1]-POS_UINT, L"  ");
	}

	return true;
}


bool CSnake::snake_directe(Snake& red_snake, Snake& blue_snake)
{
	//�����߶����ˣ�����false,������Ϸ
	if(0 == red_snake.life && 0 == blue_snake.life)
	{
		return false;
	}


	char cDirect = getch();

	//��ESC��������false,������Ϸ
	if(ESC == cDirect)
	{
		return false;
	}

	//��ͣ��Ϸ
	if(SUSPEND == cDirect)
	{
		while( cDirect = getch())
		{
			if(ESC == cDirect)
			{
				return false;
			}

			//�ڶ��ΰ���ͣ����ȡ����ͣ
			if( cDirect == SUSPEND)
				break;
		}
	}


	if(red_snake.life)
	{
		//�ı���߷���
		switch(cDirect)
		{
		case UP:
			{
				if(red_snake.direction != DIRECT_DOWN)
				{
					red_snake.direction = DIRECT_UP;
				}
			}
			break;

		case RIGHT:
			{
				if(red_snake.direction != DIRECT_LEFT)
				{
					red_snake.direction = DIRECT_RIGHT;
				}
			}
			break;

		case LEFT:
			{
				if(red_snake.direction != DIRECT_RIGHT)
				{
					red_snake.direction = DIRECT_LEFT;
				}
			}
			break;

		case DOWN:
			{
				if(red_snake.direction != DIRECT_UP)
				{
					red_snake.direction = DIRECT_DOWN;
				}
			}
			break;

		default:
			break;
		}
	}

	if(blue_snake.life)
	{
		//�ı����߷���
		switch(cDirect)
		{
		case UP2:
			{
				if(blue_snake.direction != DIRECT_DOWN)
				{
					blue_snake.direction = DIRECT_UP;
				}
			}
			break;

		case RIGHT2:
			{
				if(red_snake.direction != DIRECT_LEFT)
				{
					blue_snake.direction = DIRECT_RIGHT;
				}
			}
			break;

		case LEFT2:
			{
				if(blue_snake.direction != DIRECT_RIGHT)
				{
					blue_snake.direction = DIRECT_LEFT;
				}
			}
			break;

		case DOWN2:
			{
				if(blue_snake.direction != DIRECT_UP)
				{
					blue_snake.direction = DIRECT_DOWN;
				}
			}
			break;

		default:
			break;
		}
	}

	return true;
}


void CSnake::Play2(void)
{
	int i, j;
	Food food(0 ,0, 1) ;
	Snake red_snake , blue_snake;

	init_snake_pos(red_snake, blue_snake);
	draw_score();

	while(1)
	{
		while( !kbhit())
		{
			if(m_die_snake >= 2)
			{
				goodbay();
				break;
			}

			if(1 == food.eat)
			{
				create_food(food);
			}
			else if(0 == food.eat)
			{
				setcolor(GREEN);
				rectangle(food.x, food.y, food.x+POS_UINT, food.y-POS_UINT);
				setfont(WORD_HEIGHT, WORD_WIDTH, L"����");
				outtextxy(food.x, food.y-POS_UINT, L"��");
			}

			snake_move(red_snake);
			snake_move(blue_snake);
			
			life_check(red_snake);
			life_check(blue_snake);
			
			draw_snake(red_snake, food, RED);
			draw_snake(blue_snake, food, BLUE);
			
			Sleep(m_gamespeed);
		}

		if(m_die_snake >= 2)
		{
			goodbay();
			break;
		}

		snake_directe(red_snake, blue_snake);
	}
}


void CSnake::goodbay(void)
{
	cleardevice();
	draw_score();
	setcolor(RED);
	setfont(56, 0, L"����");
	outtextxy(200, 200, L"GAME OVER");
	outtextxy(100, 260, L"������������˳�");
	getch();
}

void CSnake::draw_score(void)
{
	wchar_t str[20] = {0};
	setfillstyle(YELLOW);
	bar(520, 10, 620, 50);
	setcolor(RED);
	setfont(16, 0, L"����");
	wsprintf(str, L"������%d", m_score);
	outtextxy(528, 16, str);
}