/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "file_transfer.h"


void
file_transfer_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	file  send_file_1_arg;
	char file_name[100];
	char *s;
	FILE *fs;

#ifndef	DEBUG
	clnt = clnt_create (host, FILE_TRANSFER_PROG, FILE_TRANSFER_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	
	int temp = 0;
	int c;
	printf("Enter file name: ");
	scanf("%s",file_name);

	strcpy(send_file_1_arg.file_name,file_name);

	fs = fopen(file_name,"r");
	if(fs == NULL){
		printf("LOL. File does not exist dude!");
		exit(1);
	}
	//get the length of file's content + filename
	fseek(fs, 0, SEEK_END);    // Go to end
	size_t length = ftell(fs); // read the position which is the size
	fseek(fs, 0, SEEK_SET);
	int lengthint = length+strlen(file_name);

	//allocate data into string
 	s = (char *) malloc(lengthint*sizeof(char));
	//save content of file into s
	if (fs){
		while((c = getc(fs))!=EOF)
			s[temp++] = c;
	}

	strcpy(send_file_1_arg.file_content,s);
	free(s);

	result_1 = send_file_1(&send_file_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	file_transfer_prog_1 (host);
        exit (0);
}
