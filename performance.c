#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define IO_VALUE 10000
#define CPU_VALUE 100

int main() {
	time_t t[20];
	int pid[20];

	int num;
	int is_child=0, i=0; float avg = 0;
	for(num=0;num<20;num++) {
		pid[num]=fork();
		t[num]=time(NULL);
		
		if(pid[num]==0) {
			
			if(num&1)
				for(i=0;i<IO_VALUE;i++);
			else
				for(i=0;i<CPU_VALUE;i++);
			is_child=1;
			break;
		}
	}
	if(!is_child) {
		
		for(i=0;i<20;i++) {
			int pid1=wait(NULL);
			int j;
			for(j=0;j<20;j++) {
				if(pid[j] == pid1) {
					avg += difftime(time(NULL),t[j]);
					break;
				}
			}
		}
		printf("%f",avg/20);
	}
}
 	
	


