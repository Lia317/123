#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <sys/neutrino.h>

void server()
{
	int rcvid;
	int child;
	char message[512];
	printf("server start working \n");
	
	child = ChannelCreate(0);
	printf("Channel id: %d\n", child);
	printf("PID: %d\n", getpid());
	
	char name[] = "Natalia";
	while(1)
	{
		rcvid = MsgReceive(child, message, sizeof(message), NULL);
		printf("Polychili message, rcvid %X\n", rcvid);
		printf("Message: \"%s\"\n", message);
				
		if(strcmp(message, name) == 0){
			strcpy(message, "Harina");
		}
		else{
			strcpy(message, "Error");
		}
			
		MsgReply(rcvid, EOK, message, sizeof(message));
		printf("\"%s\"\n", message);
	}
}

int main(){
	printf("Prog server");
	server();
	sleep(5);
	return 1;
}
