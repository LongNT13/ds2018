/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "file_transfer.h"

int *
send_file_1_svc(file *argp, struct svc_req *rqstp)
{
	static int  result;

	FILE *fr;
	char *file_name;
	char *file_content;

	file_name = (char *) malloc(sizeof(char)*strlen(argp->file_name));
	strcpy(file_name,argp->file_name);
	fr = fopen(file_name,"w");
	file_content = (char *) malloc(sizeof(char)*strlen(argp->file_content));
	int j=0;
	for (int i = 0; i < strlen(argp->file_content); ++i)
	{
		file_content[j++] = argp->file_content[i];                            
	}
	fprintf(fr,"%s",file_content);
	fflush(stdin);
        fclose(fr);
	free(file_name);
	free(file_content);
        printf("--Receive successfuly\n");
        result = 1;

	return &result;
}