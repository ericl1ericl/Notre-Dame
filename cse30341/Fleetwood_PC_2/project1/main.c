// Fleetwood_PC
// Eric Layne, Gabe King
// Project 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <signal.h>
#include "zmq.h"
#include <assert.h>
#include <string.h>

void signalHandler(int signum) {
	printf("\ninterrupt signal %i received.\n", signum);
	printf("closing.\n");
	exit(signum);
}

void userHelp() {
  printf("valid commands:\n");
  printf("\thelp\t\tdisplay this menu\n");
  printf("\tsend FILENAME\tsend file FILENAME to all subscribed clients\n");
  printf("\tquit\t\texit this code\n");
}

void sendMessage(void *publisher, char *filename) {
	char msg[120]; // establish char buffer

	FILE* file; // declare file pointer and open file at filename
	file = fopen(filename, "r");
		
	if (file == NULL) { // check for invalid file name
		printf("error: invalid file name\n");
		return;
	}
	
	// find length of text from file
	// adapted from https://stackoverflow.com/questions/21074084/check-text-file-length-in-c
	size_t pos = ftell(file);
	fseek(file, 0, SEEK_END);
	size_t length = ftell(file);
	fseek(file, pos, SEEK_SET);

	if (length >= 120) { // catch files that are too long
		printf("error: file length exceeds allowable 120 characters\n");
		return;
	}
	
	if (!fgets(msg, sizeof(msg), file)) { // catches failed transfer of file text to string
		printf("error: %s\n", strerror(errno));
	}

  for (int i = 0; i < length; i++) { // check for characters out of ascii range
    if ((msg[i] < 32) || (msg[i] > 126)) {
      if ((msg[i] != 10) && (msg[i] != 9) && (msg[i] != 0)) { // tab and newline explicitly allowed
        printf("error: file contains non ASCII characters (permissible range: 32 - 126, tab & newline)\n");
        return;
      }
    }
  }

	fclose(file);

	printf("The following message will be sent (file length of %i characters): \n", (int) length);
	printf(msg);

	// prompt user to send message
	char confirm[10];
	printf("type YES to confirm: ");
	scanf("%s", confirm);
	if (strcmp(confirm, "YES") == 0) {
		zmq_send(publisher, msg, strlen(msg), 0); // sent!
		printf("message sent.\n");
	}
	else {
		printf("not confirmed. exiting.\n");
	}
	return;
}

int main(int argc, char* argv[]) {
  	printf("welcome to FLEETWOOD_PC's publisher server.\n");
  	int portno = 61717; // sets default port
	char port[32]; // buffer allows adequate space for socket string
	
	// if user enters extra arguments
	if (argc > 2) {
		printf("error: invalid usage. please use ./project1 PORTNUMBER\n");
   	return 1;
  	}

	// if user specifies a second argument (like a port)
	if (argc == 2) {
		int i = 0;
		char* input = argv[1];

		// see if second argument is a number for a port
		for (; input[i] != 0; i++) {
			if(!isdigit(input[i])) {
				printf("error: invalid usage. please use ./project1 PORTNUMBER\n");
				return 1;
			}
		}	
		portno = strtol(argv[1], NULL, 10);
  	}

	// create socket to port
	if (argc == 1) {
		printf("no port specified. defaulting to %i\n", portno);
	}
  	sprintf(port, "tcp://*:%i.", portno);
	printf("attempting connection to %s.\n", port);
  	void *context = zmq_ctx_new();
	void *publisher = zmq_socket(context, ZMQ_PUB);
	int rc = zmq_bind(publisher, port);
	assert (rc == 0);

	sleep(1); // fixes 'slow joiner' issue and allows publisher socket to be established

	printf("connection successful, ready to publish to %s\n", port);
	
  	// register signal SIGINT and signal handling callback fcn
	signal(SIGINT, signalHandler);

	// main functioning loop
	while(1) {
   	printf("> "); // input line
    	char command[4];
		scanf("%s", command); // get first argument in input
		// user wants to send message
    	if (strcmp(command, "send") == 0) {
      	char filename[64];
      	scanf("%s", filename);
      	sendMessage(publisher, filename); // function to send message
    	}
		// user wants to quit
		else if (strcmp(command, "quit") == 0) {
			zmq_close(publisher); // reacting to quit, closing server
			zmq_ctx_destroy(context);	// reacting to quit, destroying context
			printf("closing.\n");
			return 0;
		}
		// user requests help or enters bad input
		else {
      	userHelp();
    	}
   	sleep(1);
	}

}
