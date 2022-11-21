/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "file.h"


void
add_prog_1(char *host, float x, float y, int choix)
{
	CLIENT *clnt;
	float  *result_1;
	number  add_1_arg;
	add_1_arg.x=x;
	add_1_arg.y=y;
	float  *result_2;
	number  substract_1_arg;
	substract_1_arg.x=x;
	substract_1_arg.y=y;
	float  *result_3;
	number  multi_1_arg;
	multi_1_arg.x=x;
	multi_1_arg.y=y;
	float  *result_4;
	number  div_1_arg;
	div_1_arg.x=x;
	div_1_arg.y=y;
	
	float x1,x2;
#ifndef	DEBUG
	clnt = clnt_create (host, ADD_PROG, ADD_VER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */


	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = substract_1(&substract_1_arg, clnt);
	if (result_2 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = multi_1(&multi_1_arg, clnt);
	if (result_3 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = div_1(&div_1_arg, clnt);
	if (result_4 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	switch(choix){
		case 1:
		printf("Resultat d'addition = %f\n",*result_1);
		break;
		
		case 2:
		printf("Resultat de soustraction = %f \n",*result_2);
		break;
		
		case 3:
		printf("Resultat de multiplication = %f \n",*result_3);
		break;
		
		case 4:
		printf("Resultat de division = %f \n",*result_4);
		break;
		
	}
	
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[])
{
	char *host;

	if (argc < 4) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	
	float x= atof(argv[2]);
	float y= atof(argv[3]);
	int choix;
	printf(" --------- Menu --------- \n");
	printf(" *** Entrer votre choix ! *** \n");
    printf("1- Addition\n2- Soustraction\n3- Multiplication\n4- Division\n");
	scanf("%d",&choix);
	
	
	add_prog_1 (host,x,y,choix);
exit (0);
}