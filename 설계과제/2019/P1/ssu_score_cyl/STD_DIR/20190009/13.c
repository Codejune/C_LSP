#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ssu_signal_handler(int signo);

int count=0;

int main(void)
{
	struct sigaction sig_act;

	sig_act.sa_flags=0;
	sig_act.sa_handler=ssu_signal_handler;
	sigemptyset(&sig_act.sa_mask);
	sigaction(SIGALRM,&sig_act,NULL);

	alarm(1);

	while(1);

	exit(0);
}

void ssu_signal_handler(int signo){
	printf("alarm %d\n",count++);

	alarm(1);

	if(count > 3)
		exit(0);
}
