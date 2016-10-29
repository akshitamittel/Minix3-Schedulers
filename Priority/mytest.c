#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int pid[20];
	int i;
	char processid[100];
  
    for(i=1;i<=10;i++)
    {
    	pid[i]=fork();
        if(pid[i]==0)
    	{
    		sprintf(processid,"%2d",i);
    		execlp("./longrun0","./longrun0",processid,"100000","1000",NULL);
    	    
        }
        
    }
    for(i=1;i<=10;i++)
    {
    	wait(NULL);
    }	
    return 0;
}