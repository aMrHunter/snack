#include <termios.h>
#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include "active.h"

struct termios tm_old;
//获取一个字符而 不回显
int getch()
{
	struct termios tm;
	tcgetattr(0,&tm_old);
	cfmakeraw(&tm);
	tcsetattr(0,0,&tm);
	int ch = getchar();
	tcsetattr(0,0,&tm_old);
	return ch;
}

void alarmUs(int n)
{
	struct itimerval value;
	//定时器启动的初始值
	value.it_value.tv_sec = 0;
	value.it_value.tv_usec = n;

	//定时器启动后的间隔时间值
	value.it_interval.tv_sec = 0;
	value.it_interval.tv_usec = n;

	setitimer(ITIMER_REAL,&value,NULL);
}

//SIGALRM 信号处理函数
void catchSignal(int s)
{
	go();
}
