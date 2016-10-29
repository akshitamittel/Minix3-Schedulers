#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	printf("Process id: %d\n", getpid());
	do {
	} while(1);
	return 0;
}
