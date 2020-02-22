#ifndef _DATA_H_
#define _DATA_H_
#include<stdio.h>
typedef struct{
    int x,y,c;  //坐标及颜色
}Body;

typedef struct{
    int len;    //蛇的长度
    int dir;    //蛇的方向 0-左 1-上 2-右 3-下
    Body body[600];     //蛇的身体
}Snack;

extern int gameArea[30][30];
extern int fruit_x,fruit_y;
extern Snack snack;
extern int k1;
extern int k;
extern FILE *f;
extern int gscore;
extern int score;
void initData();
void eat();     //吃掉果子

#endif
