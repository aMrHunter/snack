#include <stdlib.h>
#include "active.h"
#include "data.h"
#include "disp.h"
static void checkFruit();
static void checkSnack(int d);
void up()
{
    //向下忽略
    if(snack.dir == 3)
        return;
    checkSnack(1);
    int i;
    for(i = snack.len; i > 0; i--)
    {
        snack.body[i] = snack.body[i-1];
    }
    snack.body[0].y--;
    snack.dir = 1;
    //吃果子
    checkFruit();
    update();
}

void down()
{
    //向上忽略
    if(snack.dir == 1)
        return;
    checkSnack(3);
    int i;
    for(i = snack.len; i > 0; i--)
    {
        snack.body[i] = snack.body[i-1];
    }
    snack.body[0].y++;
    snack.dir = 3;
    //吃果子
    checkFruit();
    update();

}
void _left()
{

    if(snack.dir == 2)
        return;

    snack.dir=0;
}
void _right()
{
    if(snack.dir==0)
    return ;
    snack.dir=2;
}
void _up()
{
    if(snack.dir==3)
    return;
    snack.dir=1;
}
void _down()
{
    if(snack.dir==1)
    return ;
    snack.dir=3;
}
void left()
{
    //向右忽略
    if(snack.dir == 2)
        return;
    checkSnack(0);
    int i;
    for(i = snack.len; i > 0; i--)
    {
        snack.body[i] = snack.body[i-1];
    }
    snack.body[0].x--;
    snack.dir = 0;
    //吃果子
    checkFruit();
    update();

}

void right()
{
    //向左忽略
    if(snack.dir == 0)
        return;
    checkSnack(2);
    int i;
    for(i = snack.len; i > 0; i--)
    {
        snack.body[i] = snack.body[i-1];
    }
    snack.body[0].x++;
    snack.dir = 2;
    //吃果子
    checkFruit();
    update();

}

void go()
{
    if(snack.dir == 1)
    {
          up();
    }
 if(snack.dir == 2)
    {
        right();
    }
 if(snack.dir == 0)
    {
        left();
    }
 if(snack.dir == 3)
    {
        down();
    }

}
static void checkFruit()
{
    if(fruit_x == snack.body[0].x && fruit_y == snack.body[0].y)
    {
        snack.len++;
        eat();
    }
}
static void checkSnack(int d)
{
    int x,y,i;
    if(d == 0)
    {
        x = snack.body[0].x-1;
        y = snack.body[0].y;
    }
    else if(d == 1)
    {
        x = snack.body[0].x;
        y = snack.body[0].y-1;
    }
    else if(d == 2)
    {
        x = snack.body[0].x+1;
        y = snack.body[0].y;
    }
    else if(d == 3)
    {
        x = snack.body[0].x;
        y = snack.body[0].y+1;
    }
    if(x == 0 || x == 19 || y == 0 || y == 29)
    {
        closeGame();
        exit(0);
    }
    for(i = 0; i < snack.len - 1; i++)
    {
        if(x == snack.body[i].x && y == snack.body[i].y)
        {
            closeGame();
            exit(0);
        }
    }
}
