#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "disp.h"
#include "active.h"
#include <signal.h>
#include <sys/time.h>
#include "tools.h"
int k;
int main()
{
    printf("请选择难度（1-6数字越大，难度越大）：\n");
    scanf("%d",&k);
    if(k==1)
    {
        alarmUs(800000); 
    }
    
    if(k==2)
    {
        alarmUs(600000); 
    }
    if(k==3)
    {
        alarmUs(400000); 
    }
    if(k==4)
    {
        alarmUs(300000); 
    }
    if(k==5)
    {
        alarmUs(200000); 
    }
    if(k==6)
    {
        alarmUs(100000); 
    }
    f=fopen("./Gscore","r+");
    if(f==NULL)
    {
    f=fopen("./Gscore","w");
    }
    fscanf(f,"%d",&gscore);
    initData();
    initDisp();
    update();
    signal(SIGALRM,catchSignal);
    k1=k;
   

    char ch;

    while(1)
    {
        ch = getch();
        switch(ch)
        {
            case 'a':
                _left();
            break;
            case 'w':
                _up();
            break;
            case 'd':
                _right();
            break;
            case 's':
                _down();
            break;
            case 'q':
                closeGame();
                exit(0);
            break;
        }

    if(k1==1)
    {
        alarmUs(800000); 
    }
    
    if(k1==2)
    {
        alarmUs(600000); 
    }
    if(k1==3)
    {
        alarmUs(400000); 
    }
    if(k1==4)
    {
        alarmUs(300000); 
    }
    if(k1==5)
    {
        alarmUs(200000); 
    }
    if(k1==6)
    {
        alarmUs(100000); 
    }
    }
      closeGame();
    return 0;
}
