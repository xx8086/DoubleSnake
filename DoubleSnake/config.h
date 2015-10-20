// Author: liuhan (liuhan333@126.com)
//
// 定义一宏和结构体

#pragma once
//暂停
#define SUSPEND		(' ')
//方向
#define LEFT		('j')
#define RIGHT		('l')
#define DOWN		('k')
#define UP			('i')

#define LEFT2		('a')
#define RIGHT2		('d')
#define DOWN2		('s')
#define UP2			('w')

		
#define ESC			(27)

//蛇的最大节点数
#define NODE		(400)

// 蛇移动速度
#define NORMAL_SPEED (400)

// 墙上每块砖的厚度
#define BRICK_DEEP		(8)
//砖块之间的间隙
#define BRICK_CHINK		(2)
//围墙起始坐标X
#define BEGIN_POS_X		(12)
//围墙起始坐标Y
#define BEGIN_POS_Y		(12)
//坐标单位
#define POS_UINT		(10)
//吃食物得到的分数
#define	SCORE			(10)
//字高
#define WORD_HEIGHT		(POS_UINT+2)
//字宽
#define WORD_WIDTH		(0)

// @brief	: 移动方向
typedef enum Move_Direct
{
	DIRECT_RIGHT = 1,
	DIRECT_LEFT  = 2,
	DIRECT_UP	 = 3,
	DIRECT_DOWN  = 4,
} MOVE_DIRECT;

// @brief	: 食物
struct Food
{
	int x;//x坐标
	int y;//y坐标
	int eat;//1:已经被吃掉了，0:未被吃

	Food(int _x, int _y, int _eat):x(_x),y(_y),eat(_eat){}
};


struct Snake
{
	int				x[NODE];
	int				y[NODE];//保存蛇的身体
	int				node;//蛇的节点数
	MOVE_DIRECT		direction;//移动方向
	int				life;//0:死了，1:活着
};

struct Config
{
	char key;
	Food food;
	Snake snake;
	COLORREF colorref;
};