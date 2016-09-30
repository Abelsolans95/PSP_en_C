#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid_padre;
	pid_t pid_actual;
	pid_t pid;
	pid_t pid_hijo;

	pid_actual = getpid();
	pid_padre = getppid();


	fprintf(stdout, "PID proceso actual: %d\n", pid_actual);
	fprintf(stdout, "PID proceso padre: %d\n", pid_padre);

	pid = fork();

	if (pid == -1)
	{
		fprintf(stderr, "Error en el Fork() \n");
		exit(-1);
			}

		if(pid == 0){// nos encontramos en el proceso hijo.
			fprintf(stdout, "En el hijo: PID: %d\n", getpid());
			fprintf(stdout, "En el hijo: PPID: %d\n", getppid());
			sleep(5);

	}else {// estamos en el proceso padre.
		fprintf(stdout, "En el padre: PID: %d\n", getpid());
		fprintf(stdout, "En el padre: PPID: %d\n", getppid());
		pid_hijo = wait( NULL );
		fprintf(stdout, "En el padre. Mi hijo con el pid: %d. ha finalizado", pid_hijo);

	}
	return 0;
}