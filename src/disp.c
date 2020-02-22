#include <stdio.h>
#include "disp.h"
#include "data.h"
void update()
{
    printf("\33[2J]");
    dispGameArea();
    dispInfoArea();
    fflush(NULL);
}

void dispGameArea()
{
    //1打印蛇
    int i;
    for(i = 0; i < snack.len; i++)
    {
        printf("\33[%d;%dH\33[43m[]\33[0m",snack.body[i].y,(snack.body[i].x+1)*2);
    }
    //2打印果子
    printf("\33[%d;%dH\33[42m[]\33[0m",fruit_y,(fruit_x+1)*2);
    //3打印地图
    int x,y;
    for(y = 0; y < 30; y++)
    {
        for(x = 0; x < 30; x++)
        {
            if(gameArea[x][y] == 1)
                printf("\33[%d;%dH\33[44m[]\33[0m",y,(x+1)*2);    
           if(x==22&&y==7)
            {
                printf("当前难度为： %d ",k);
            }
            if(x==22&&y==13)
            {
                printf("当前得分为： %d ",score);
            }
            if(x==22&&y==22)
            {
                printf("当前最高分：%d",gscore);
            }
        }
    }
}
void dispInfoArea()
{
    
}

void initDisp()
{
    printf("\33[2J");
    printf("\33[?25l");
    fflush(NULL);
}

void closeGame()
{
    printf("\33[?25h");
    printf("\n");
    close=1;
}

