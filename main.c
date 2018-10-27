#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void board();
void assign();
int check();
void computer();

struct name
{
	char player1[20];
	char player2[20];
};
char number[9] = {'1','2','3','4','5','6','7','8','9'};
int buffer[9];
int i;
int main() 
{
	struct name player;
	int a,human = 1,input;
	printf("\t=Hello There! Welcome to Rivaldo and Fashhandi Tic Tac Toe!!=\n\n");
	printf("Player 1 name: ");
	scanf("%s", &player.player1);

	printf("Player 2 name: ");
	scanf("%s", &player.player2);
	int g=0;
	int i;
	system("cls");
	char symbol;
	do
	{
		board(number);
		
		human = (human % 2) ? 1 : 2;
		symbol = (human == 1)? 'X' : 'O';
		
		if (human == 1)
		{
			printf("\n%s, Enter your number: ", player.player1);
			scanf("%d", &input);	
			
			assign(input, symbol, number, human);
		}
		if (human == 2)
		{
			printf("\n%s, Enter your number: ", player.player2);
			scanf("%d", &input);
			if (input == 0)
			{
				computer(number);
			}
			assign(input, symbol, number, human);
		}
		a = check(number);
		buffer[g] = input;
		g++;
        human++;
		system("cls");
	}while(a == -1);
	board(number);
	
	if (a == 1)
	{	
		human--;
		if(human == 1)
		{
			printf("\n--> %s WIN", player.player1);
		}
		if(human == 2)
		{
			printf("\n--> %s WIN", player.player2);
		}
	}
	else
	{
		printf("\nGame is Draw");
	}
	return 0;
}

void board(char * number)
{
	printf("\t\t\t\t\t=Tic Tac Toe=\n\n");
	printf("    Player 1 (X)  -  Player 2 (O)\n\n\n");
	printf("\t _____ _____ _____\n");
	printf("\t|     |     |     |\n");
	printf("\t|  %c  |  %c  |  %c  |\n", number[0], number[1], number[2]);
	printf("\t|_____|_____|_____|\n");
	printf("\t|     |     |     |\n");
	printf("\t|  %c  |  %c  |  %c  |\n", number[3], number[4], number[5]);
	printf("\t|_____|_____|_____|\n");
	printf("\t|     |     |     |\n");
	printf("\t|  %c  |  %c  |  %c  |\n", number[6], number[7], number[8]);
	printf("\t|_____|_____|_____|\n"); 
}

void assign(int input,int symbol,char * number,int human)
{ 
	
	if (input == 1 && number[0] == '1')
    {
    	number[0] = symbol;
	}
    else if (input == 2 && number[1] == '2')
    {
		number[1] = symbol;
	}
    else if (input == 3 && number[2] == '3')
    {
	    number[2] = symbol;
	}
    else if (input == 4 && number[3] == '4')
    {
	    number[3] = symbol;
	}
    else if (input == 5 && number[4] == '5')
    {
	    number[4] = symbol;
	}
    else if (input == 6 && number[5] == '6')
    {
	    number[5] = symbol;
	}
    else if (input == 7 && number[6] == '7')
    {
	    number[6] = symbol;
	}
    else if (input == 8 && number[7] == '8')
    {
	    number[7] = symbol;
	}
    else if (input == 9 && number[8] == '9')
    {
	    number[8] = symbol;
	}
    else if (input != 0)
    {
        printf("Invalid move ");
        human--;
        getch();
    }
}

int check(char * number)
{
    if (number[0] == number[1] && number[1] == number[2])
    {
	    return 1;
	}
    else if (number[3] == number[4] && number[4] == number[5])
    {
	    return 1;
	}
    else if (number[6] == number[7] && number[7] == number[8])
    {
	    return 1;
	}
    else if (number[0] == number[3] && number[3] == number[6])
    {
	    return 1;
	}
    else if (number[1] == number[4] && number[4] == number[7])
    {
	    return 1;
	}
    else if (number[2] == number[5] && number[5] == number[8])
    {
	    return 1;
	}
    else if (number[0] == number[4] && number[4] == number[8])
    {
	    return 1;
	}
    else if (number[2] == number[4] && number[4] == number[6])
    {
	    return 1;
	}
    if (number[0] != '1' && number[1] != '2' && number[2] != '3' &&
        number[3] != '4' && number[4] != '5' && number[5] != '6' && number[6]
        != '7' && number[7] != '8' && number[8] != '9')
	{
        return 2;
	}
    else
    {
	    return  - 1;
	}
}

void computer(char * number)
{
    if(number[4] != 'X' && number[4] == '5')
    {
        number[4] = 'O';
    }
    if(number[4] == 'X' && number[0] == '1')
    {
        number[0] = 'O';
    } 
    else if(number[0] == 'X' && number[1] == 'X' && number[2] == '3')
    {
        number[2] = 'O';
    }
    else if(number[2] == 'X' && number[1] == 'X' && number[0] == '1')
    {
        number[0] = 'O';
    }
    else if(number[0] == 'X' && number[2] == 'X' && number[1] == '2')
    {
        number[1] = 'O';
    }
    else if(number[3] == 'X' && number[4] == 'X' && number[5] == '6')
    {
        number[5] = 'O';
    }
    else if(number[5] == 'X' && number[4] == 'X' && number[3] == '4')
    {
        number[3] = 'O';
    }
    else if(number[3] == 'X' && number[5] == 'X' && number[4] == '5')
    {
        number[4] = 'O';
    }
    else if(number[6] == 'X' && number[7] == 'X' && number[8] == '9')
    {
        number[8] = 'O';
    }
    else if(number[8] == 'X' && number[7] == 'X' && number[6] == '7')
    {
        number[6] = 'O';
    }
    else if(number[6] == 'X' && number[8] == 'X' && number[7] == '8')
    {
        number[7] = 'O';
    }
    else if(number[0] == 'X' && number[3] == 'X' && number[6] == '7')
    {
        number[6] = 'O';
    }
    else if(number[6] == 'X' && number[3] == 'X' && number[0] == '1')
    {
        number[0] = 'O';
    }
    else if(number[0] == 'X' && number[6] == 'X' && number[3] == '4')
    {
        number[3] = 'O';
    }
    else if(number[1] == 'X' && number[4] == 'X' && number[7] == '8')
    {
        number[7] = 'O';
    }
    else if(number[7] == 'X' && number[4] == 'X' && number[1] == '2')
    {
        number[1] = 'O';
    }
    else if(number[1] == 'X' && number[7] == 'X' && number[4] == '5')
    {
        number[4] = 'O';
    }
    else if(number[2] == 'X' && number[5] == 'X' && number[8] == '9')
    {
        number[8] = 'O';
    }
    else if(number[8] == 'X' && number[5] == 'X' && number[2] == '3')
    {
        number[2] = 'O';
    }
    else if(number[2] == 'X' && number[8] == 'X' && number[5] == '6')
    {
        number[5] = 'O';
    }
    else if(number[6] == 'X' && number[4] == 'X' && number[2] == '3')
    {
        number[2] = 'O';
    }
    else if(number[2] == 'X' && number[4] == 'X' && number[6] == '7')
    {
        number[6] = 'O';
    }
}
