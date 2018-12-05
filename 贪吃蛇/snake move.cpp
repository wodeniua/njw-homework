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

int snakeY[SNAKE_MAX_LENGTH] = { 1,2,3,4,5 };//�趨��ʼλ��
int snakeX[SNAKE_MAX_LENGTH] = { 1,1,1,1,1 };
int snakeLength = 5;//��ʼ����
int gamerunning = 1;//�ж��Ƿ�����Ϸ

void GameOver(void)//������Ϸ
{
	gamerunning = 0;
}

void snakeMove(char control)
{
	if (map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] == WALL_CELL || map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] == SNAKE_BODY)//�ж��Ƿ���Ϸ����
	{
		GameOver();
	}
	if (gamerunning == 1) {
		for (int i = 0; i < snakeLength - 1; i++)
			map[snakeX[i]][snakeY[i]] = BLANK_CELL;//���ԭ������
		int presnakeX = snakeX[snakeLength - 1];
		int presnakeY = snakeY[snakeLength - 1];//��¼ԭ����ͷ��λ��
		switch (control) {                    //aswd����ͷ���˶�
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

		for (int j = 0; j < snakeLength - 2; j++)//�ߵ�ÿ�����嶼������һ�ڵ�λ��
		{
			snakeX[j] = snakeX[j + 1];
			snakeY[j] = snakeY[j + 1];
		}
		snakeX[snakeLength - 2] = presnakeX;//ԭ����ͷ��������嵽��ͷ��λ��
		snakeY[snakeLength - 2] = presnakeY;

		map[snakeX[snakeLength - 1]][snakeY[snakeLength - 1]] = SNAKE_HEAD;//��ӡ�µ�ͷ��λ��
		for (int i = snakeLength - 2; i >= 0; i--)
			map[snakeX[i]][snakeY[i]] = SNAKE_BODY;//��ӡ����
	}
}

void output()//��ӡ��ͼ
{
	system("cls");
	for (int i = 0; i < 12; ++i) {
		printf("%s\n", map[i]);
	}
}

int main(void)
{
	output();//��ʼ�ȴ�ӡһ���ͼ
	char control=0;
	while (gamerunning) {
		scanf(" %c", &control);
		snakeMove(control);
		output();
	}
	printf("Game Over!!!");
	return 0;
}
