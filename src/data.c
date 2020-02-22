#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
//游戏界面
int gameArea[30][30] = {0};
//果子坐标
int fruit_x,fruit_y;
//蛇
Snack snack;
int score=100;
int gscore=0;
int k1=0;
FILE *f;
static int checkFruitCoordinate();
void initData()
{
    srand(time(NULL));
    //初始化游戏地图
    int x,y;
    for(x = 0; x < 30; x++)
    {
        for(y = 0; y < 30; y++)
        {
            if(x == 0 || y == 0 || x == 19 || y == 29||x==29||(y==15&&x>=20))
                       gameArea[x][y] = 1;
            else
                gameArea[x][y] = 0;
        }
    }
    //初始化蛇
    snack.len = 5;
    snack.dir = 0;
    int i;
    for(i = 0; i < 5; i++)
    {
        snack.body[i].x = 8+i;
        snack.body[i].y = 15;
    }
    //初始化果子
    do{   
       fruit_x = random() % 18 + 1;
        fruit_y = random() % 28 + 1;
    }while(checkFruitCoordinate());
}
void eat()
{
     score+=100;
    //初始化果子
    if(score>gscore)
    {
        gscore=score;
        rewind(f);
        fprintf(f,"%d\n",gscore);
    }
if(score%2000==0&&k<6)
    {
        k1++;
    }
    do{   
        fruit_x = random() % 18 +1;
        fruit_y = random() % 28 + 1;

    } while(checkFruitCoordinate());
}

static int checkFruitCoordinate()
{
    int i;
    for(i = 0; i < snack.len; i++)
    {
        if(fruit_x == snack.body[i].x && fruit_y == snack.body[i].y&&fruit_x==1)
            return 1;
    }
    return 0;
}
