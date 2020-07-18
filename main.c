#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"

#define USERNAME	"zeeking99"
#define PASSWORD	"9985767410"

int main()
{
	char upassword[11],ch,username[10];
	int len=0;
	
	printf("Enter username: ");
	fgets(username, 10, stdin);
	getchar(); // to take the input of the newline in the buffer and clear it
	printf("Enter your password to login: ");
	GetPassword(upassword);		

	if(strcmp(upassword, PASSWORD)==0 && strcmp(username, USERNAME)==0)
	{
		printf("\n\tLOGIN SUCCESS\n");
	}
	else
	{
		printf("\n\tLOGIN FAILED\n");
	}

	return 0;
}
