#include <stdio.h>


// void WAIT_PRESS(void)
// {
	// while(kbhit())
		// getch();
	// while(!kbhit())
	// { 
	// }; 
	// getch();
// }

int main()
{
	printf("Hello world!\n");	

	while(1)
	{
		if(kbhit())
		{
			printf("%c\n",getch());
		}
	}


			
	return 0;
}

