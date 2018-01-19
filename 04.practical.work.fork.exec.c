#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Main before fork()\n");
	int pid1 = fork();
	int pid2 = fork();
	if (pid1 != 0 && pid2 != 0) {
		printf("These two commands are executed in separate child %d and %d, respectively\n", pid1, pid2);
	}	
	else if (pid1 == 0) {
		printf("Launching free -h\n");
		char *freeh[]= { "free", "-h" , NULL};
		execvp("free", freeh);
		execvp("free", freeh);
	}
	else if (pid2 == 0) {
		printf("Launching ps -ef\n");
		char *psef[]= { "/bin/ps", "-ef" , NULL};

		execvp("/bin/ps", psef);
	}
	
return 0;
}
