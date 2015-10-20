// Author: liuhan (liuhan333@126.com)
//
// ����һ��ͽṹ��

#pragma once
//��ͣ
#define SUSPEND		(' ')
//����
#define LEFT		('j')
#define RIGHT		('l')
#define DOWN		('k')
#define UP			('i')

#define LEFT2		('a')
#define RIGHT2		('d')
#define DOWN2		('s')
#define UP2			('w')

		
#define ESC			(27)

//�ߵ����ڵ���
#define NODE		(400)

// ���ƶ��ٶ�
#define NORMAL_SPEED (400)

// ǽ��ÿ��ש�ĺ��
#define BRICK_DEEP		(8)
//ש��֮��ļ�϶
#define BRICK_CHINK		(2)
//Χǽ��ʼ����X
#define BEGIN_POS_X		(12)
//Χǽ��ʼ����Y
#define BEGIN_POS_Y		(12)
//���굥λ
#define POS_UINT		(10)
//��ʳ��õ��ķ���
#define	SCORE			(10)
//�ָ�
#define WORD_HEIGHT		(POS_UINT+2)
//�ֿ�
#define WORD_WIDTH		(0)

// @brief	: �ƶ�����
typedef enum Move_Direct
{
	DIRECT_RIGHT = 1,
	DIRECT_LEFT  = 2,
	DIRECT_UP	 = 3,
	DIRECT_DOWN  = 4,
} MOVE_DIRECT;

// @brief	: ʳ��
struct Food
{
	int x;//x����
	int y;//y����
	int eat;//1:�Ѿ����Ե��ˣ�0:δ����

	Food(int _x, int _y, int _eat):x(_x),y(_y),eat(_eat){}
};


struct Snake
{
	int				x[NODE];
	int				y[NODE];//�����ߵ�����
	int				node;//�ߵĽڵ���
	MOVE_DIRECT		direction;//�ƶ�����
	int				life;//0:���ˣ�1:����
};

struct Config
{
	char key;
	Food food;
	Snake snake;
	COLORREF colorref;
};