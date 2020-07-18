#include <stdio.h>
#include "console.h"

void GetPassword(char *pass) // function which will take the password and print a * for every character 
{
	char ch;
	int len=0;
	
	while((ch=getch())!='\n') // will take input until enter is pressed
	{
		if(ch==0x7f) // checks that the character pressed is not backspace or delete
		{
			if(len==0)	continue; 
			printf("\b \b"); // deletes the * , prints a space and then clears it 
			len--; // decrementing length because the character is deleted
			continue;
		}
		
		printf("*");
		pass[len]=ch; 
		len++;
	}
	pass[len]='\0'; // assigning the null character to mark the end of the string
}
