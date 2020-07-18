#include <termios.h>
#include <stdio.h>

static struct termios old, new; // termios structures to store the settings of terminals

void InitTermios(int echo) // function to change the property of terminal
{
	tcgetattr(0, &old); // getting the settings of the terminal
	new = old; // assigning the settings to the new termios struct
	new.c_lflag &= ~ICANON; // setting to change into non canonical mode (taking one letter at a time as input
	new.c_lflag &= echo ? ECHO : ~ECHO; // setting the echo mode according to the input given by the user
	tcsetattr(0, TCSANOW, &new); // implementing the changed settings to the terminal (TCSANOW is used to implement the settings right at the moment.)
}

void ResetTermios(void) // Fucntion to reset the old settings of the terminal
{
	tcsetattr(0, TCSANOW, &old); // setting the properties
}

char getch_(int echo) // function to get a character echo can be 1 or 0
{
	char ch;
	
	InitTermios(echo);
	ch = getchar();
	ResetTermios();
	
	return ch;
}

char getch(void) // will take character immediately as it is typed
{
	getch_(0);
}

char getche(void) // will take character immediately and prints back the character
{
	getch_(1);
}
