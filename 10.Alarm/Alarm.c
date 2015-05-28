#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define first 2
#define interval 3

struct itimerval timer;
int count=first;

void alarmHandler(int sig)
{
	printf("%d seconds\tAlarm Hits!!\n",count);
	count+=interval;
}
int main()
{
	timer.it_value.tv_sec=first;//first alarm time
	timer.it_value.tv_usec=0;
	timer.it_interval.tv_sec=interval;//alarm interval(snooze) time
	timer.it_interval.tv_usec=0;
	signal(SIGALRM,alarmHandler);
	if((setitimer(ITIMER_REAL,&timer,NULL)) ==-1)
	{
		perror("setitimer");
		return -1;
	}
	while(1)
	{
	}
	return 0;
}
