#include <sys/time.h>
#include <stdio.h>

int main (void){
	struct timeval	time;
	gettimeofday(&time, NULL);
	printf("%ld\n", time.tv_sec*1000);
	printf("%d\n", time.tv_usec);
	printf("%ld\n", time.tv_sec*1000 + time.tv_usec);
}