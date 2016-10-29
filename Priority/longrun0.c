/*
	I created my own longrun without the 'iteration and value' printf -- so as to avoid preemption during priority scheduler which gets 
	preempted during the above mentioned printf; it being an IO operation.
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define LOOP_COUNT_MIN 100
#define LOOP_COUNT_MAX 100000000
long long subtime(struct timeval start,struct timeval end){
  return 1e6*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec);
}
int main (int argc, char *argv[])
{
  char *idStr;
  unsigned int	v;
  int	i = 0;
  int	iteration = 1;
  int	loopCount;
  int	maxloops;


  if (argc < 3 || argc > 4) 
  {
    printf ("Usage: %s <id> <loop count> [max loops]\n", argv[0]);
    exit (-1);
  }

  v = getpid ();

  idStr = argv[1];

  loopCount = atoi (argv[2]);
  if ((loopCount < LOOP_COUNT_MIN) || (loopCount > LOOP_COUNT_MAX)) 
  {
    printf ("%s: loop count must be between %d and %d (passed %s)\n", argv[0], LOOP_COUNT_MIN, LOOP_COUNT_MAX, argv[2]);
    exit (-1);
  }
  if (argc == 4) 
  {
    maxloops = atoi (argv[3]);
  } 
  else 
  {
    maxloops = 0;
  }


  struct timeval start,end,wait,curr; //store start, end (turnaround time) and temporary times for calculations
  double waiting_time=0; 
  gettimeofday(&start,NULL);

  while (1) 
  {
    v = (v << 4) - v;
    if (++i == loopCount) 
    {
      if (iteration == maxloops) 
      {
		 break;
      }

      gettimeofday(&wait,NULL);
      fflush(stdout);
      gettimeofday(&curr,NULL);

      waiting_time=waiting_time+subtime(wait,curr);// add to waiting time
      
      iteration += 1;
      i = 0;
    }

  }
  

  gettimeofday(&end,NULL);
  printf ("CPU Bound The final value of v is 0x%08x\n", v);
  printf("Turnaround time = %0.6lf\n",subtime(start,end)/1e6);
  printf("Waiting time = %0.6lf\n",waiting_time/1e6);
}

