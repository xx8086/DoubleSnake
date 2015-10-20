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
	// @brief	: 初始化
	// @param	: [IN] iWallWide		围墙宽度
	// @param	: [IN] iWallHigh		围墙长度
	// @param	: [IN] iDescribeBeginX	描述文字其实位置
	// @return 
	void Init(int iWallWide, int iWallHigh, int iDescribeBeginX);

	// @brief	: 结束前清理已经结束响应操作
	// @param 
	// @return 
	void goodbay(void);

	// @brief	: 玩
	// @param 
	// @return 
	void Play2(void );

	//unsigned __stdcall Play(void* pArguments );
private:
	// @brief	: 画围墙
	// @param	: [IN] iLeft		绘制围墙的起始位置
	// @param	: [IN] iTop			绘制围墙的起始位置
	// @param	: [IN] iWide		墙宽
	// @param	: [IN] iHigh		墙高
	// @return	: true				成功
	bool draw_wall(int iLeft, INT iTop, int iWide, int iHigh);

	// @brief	: 游戏操作描述
	// @param	: [IN] iBeginX		描述其实坐标X
	// @param	: [IN] iBeginX		描述其实坐标Y
	// @param	: [IN] irowheight	行高
	// @return	: true				成功
	bool draw_describe(int iBeginX, int iBeginY, int irowheight);

	// @brief	: 刷新分数
	// @param
	// @return 
	void draw_score(void);

private:
	// @brief	: 刷新分数
	// @param	: [OUT] food	随机创建一个新食物
	// @return	: true
	bool create_food(Food& food);

	// @brief	: 初始化蛇的起始位置
	// @param	: [OUT] red_snake	创建一条红蛇
	// @param	: [OUT] blue_snake	创建一条蓝蛇
	// @return	: true
	bool init_snake_pos(Snake& red_snake, Snake& blue_snake); 

	// @brief	: 蛇的移动
	// @param	: [OUT] x_snake	移动后的蛇
	// @return	: true
	bool snake_move(Snake& x_snake);

	// @brief	: 检查蛇是否死亡
	// @param	: [OUT] x_snake	被检查的蛇
	// @return	: true
	bool life_check(Snake& x_snake);

	// @brief	: 画蛇
	// @param	: [OUT] x_snake		被画的蛇
	// @param	: [OUT] food		当前食物
	// @param	: [IN]  snake_color	设置蛇的颜色
	// @return	: true
	bool draw_snake(Snake& x_snake, Food& food, COLORREF snake_color);
	
	// @brief	: 控制蛇移动方向
	// @param	: [OUT] red_snake		控制红蛇的方向
	// @param	: [OUT] blue_snake		控制蓝蛇的方向
	// @return	: 返回true继续游戏；只有两条蛇都死了或按了退出键ESC才返回false,结束游戏
	bool snake_directe(Snake& red_snake, Snake& blue_snake);

private:
	int m_score;//实时分数
	int m_gamespeed;//速度

	int m_wall_wide;//墙宽
	int m_wall_high;//墙长
	int m_describe_begin;//描述起始位置

	int m_die_snake;//死了几条蛇
};