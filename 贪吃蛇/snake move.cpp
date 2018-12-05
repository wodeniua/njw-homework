#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

char map[12][12] =
{
	"***********",
	"*XXXXH    *",
	"*         *",
	"*         *",
	"*         *",
	"*         *",
	"*         *",
	"*         *",
	"*         *",
	"*         *",
	"*         *",
	"***********"
};

int snakeY[SNAKE_MAX_LENGTH] = { 1,2,3,4,5 };//设定初始位置
int snakeX[SNAKE_MAX_LENGTH] = { 1,1,1,1,1 };
int snakeLength = 5;//初始长度
int gamerunning = 1;//判断是否还在游戏

void GameOver(void)//结束游戏
{
	gamerunning = 0;
}

void snakeMove(char control)
{
	if (map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] == WALL_CELL || map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] == SNAKE_BODY)//判断是否游戏结束
	{
		GameOver();
	}
	if (gamerunning == 1) {
		for (int i = 0; i < snakeLength - 1; i++)
			map[snakeX[i]][snakeY[i]] = BLANK_CELL;//清空原来的蛇
		int presnakeX = snakeX[snakeLength - 1];
		int presnakeY = snakeY[snakeLength - 1];//记录原来蛇头的位置
		switch (control) {                    //aswd控制头的运动
		case'w':
			snakeX[snakeLength - 1]--;
			break;
		case 's':
			snakeX[snakeLength - 1]++;
			break;
		case 'a':
			snakeY[snakeLength - 1]--;
			break;
		case 'd':
			snakeY[snakeLength - 1]++;
			break;
		default:
			break;
		}

		for (int j = 0; j < snakeLength - 2; j++)//蛇的每节身体都到了上一节的位置
		{
			snakeX[j] = snakeX[j + 1];
			snakeY[j] = snakeY[j + 1];
		}
		snakeX[snakeLength - 2] = presnakeX;//原来蛇头后面的身体到了头的位置
		snakeY[snakeLength - 2] = presnakeY;

		map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] = SNAKE_HEAD;//打印新的头的位置
		for (int i = snakeLength - 2; i >= 0; i--)
			map[snakeX[i]][snakeY[i]] = SNAKE_BODY;//打印身体
	}
}

void output()//打印地图
{
	system("cls");
	for (int i = 0; i < 12; ++i) {
		printf("%s\n", map[i]);
	}
}

int main(void)
{
	output();//开始先打印一遍地图
	char control=0;
	while (gamerunning) {
		scanf(" %c", &control);
		snakeMove(control);
		output();
	}
	printf("Game Over!!!");
	return 0;
}
