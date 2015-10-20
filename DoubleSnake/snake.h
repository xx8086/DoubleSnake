// Author: liuhan (liuhan333@126.com)
//
// 
#pragma once

#include "config.h"

class CSnake
{
public:
	CSnake();
	virtual ~CSnake();
public:
	// @brief	: ��ʼ��
	// @param	: [IN] iWallWide		Χǽ���
	// @param	: [IN] iWallHigh		Χǽ����
	// @param	: [IN] iDescribeBeginX	����������ʵλ��
	// @return 
	void Init(int iWallWide, int iWallHigh, int iDescribeBeginX);

	// @brief	: ����ǰ�����Ѿ�������Ӧ����
	// @param 
	// @return 
	void goodbay(void);

	// @brief	: ��
	// @param 
	// @return 
	void Play2(void );

	//unsigned __stdcall Play(void* pArguments );
private:
	// @brief	: ��Χǽ
	// @param	: [IN] iLeft		����Χǽ����ʼλ��
	// @param	: [IN] iTop			����Χǽ����ʼλ��
	// @param	: [IN] iWide		ǽ��
	// @param	: [IN] iHigh		ǽ��
	// @return	: true				�ɹ�
	bool draw_wall(int iLeft, INT iTop, int iWide, int iHigh);

	// @brief	: ��Ϸ��������
	// @param	: [IN] iBeginX		������ʵ����X
	// @param	: [IN] iBeginX		������ʵ����Y
	// @param	: [IN] irowheight	�и�
	// @return	: true				�ɹ�
	bool draw_describe(int iBeginX, int iBeginY, int irowheight);

	// @brief	: ˢ�·���
	// @param
	// @return 
	void draw_score(void);

private:
	// @brief	: ˢ�·���
	// @param	: [OUT] food	�������һ����ʳ��
	// @return	: true
	bool create_food(Food& food);

	// @brief	: ��ʼ���ߵ���ʼλ��
	// @param	: [OUT] red_snake	����һ������
	// @param	: [OUT] blue_snake	����һ������
	// @return	: true
	bool init_snake_pos(Snake& red_snake, Snake& blue_snake); 

	// @brief	: �ߵ��ƶ�
	// @param	: [OUT] x_snake	�ƶ������
	// @return	: true
	bool snake_move(Snake& x_snake);

	// @brief	: ������Ƿ�����
	// @param	: [OUT] x_snake	��������
	// @return	: true
	bool life_check(Snake& x_snake);

	// @brief	: ����
	// @param	: [OUT] x_snake		��������
	// @param	: [OUT] food		��ǰʳ��
	// @param	: [IN]  snake_color	�����ߵ���ɫ
	// @return	: true
	bool draw_snake(Snake& x_snake, Food& food, COLORREF snake_color);
	
	// @brief	: �������ƶ�����
	// @param	: [OUT] red_snake		���ƺ��ߵķ���
	// @param	: [OUT] blue_snake		�������ߵķ���
	// @return	: ����true������Ϸ��ֻ�������߶����˻����˳���ESC�ŷ���false,������Ϸ
	bool snake_directe(Snake& red_snake, Snake& blue_snake);

private:
	int m_score;//ʵʱ����
	int m_gamespeed;//�ٶ�

	int m_wall_wide;//ǽ��
	int m_wall_high;//ǽ��
	int m_describe_begin;//������ʼλ��

	int m_die_snake;//���˼�����
};