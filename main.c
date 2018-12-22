#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void board();
void assign();
int check();
void computer();
void moves();
void printmoves();
struct name
{
 char player1[20];
 char player2[20];
 int score1;
 int score2;
};
struct push
{
 int data;
 struct push *Ptr;
};
typedef struct push push;
typedef push *nodePtr;
int i;
int main()
{
 nodePtr stackPtr = NULL;
 struct name player;
 char tempc;
 int a=-1,human = 1,input = -1,play=0,b=0,c=0,d=-1, temp;
 printf("\t=Hello There! Welcome to Rivaldo and Fashhandi Tic Tac Toe!!=\n\n");
 printf("Player 1 name: ");
 scanf("%s", &player.player1);

 printf("Player 2 name: ");
 scanf("%s", &player.player2);

 int i;
 system("cls");
 char symbol, again;
 do
 {
  int g=0;
  char number[9] = {'1','2','3','4','5','6','7','8','9'};
  int buffer[9] = {0,0,0,0,0,0,0,0,0};
 do
 {
  board(number);

  human = (human % 2) ? 1 : 2;
  symbol = (human == 1)? 'X' : 'O';

  if (human == 1)
  {
   printf("\n%s, Enter your number: ", player.player1);
   temp = input;
   scanf("%d", &input);
    if (input == 0)
   {
    computer(number);
   }

   printf("%d", input);
   while(input == temp)
            {
                printf("Your choice is invalid! Please enter a number between 1-9.");
                scanf("%c%d", &tempc, &input);
            }
            while(input < 0 || input > 9)
            {
                printf("Your choice is invalid! Please enter a number between 1-9.");
                scanf("%d", &input);
            }
   assign(input, symbol, number, human);
   moves(&stackPtr, input);
  }
  if (human == 2)
  {
   printf("\n%s, Enter your number: ", player.player2);
   temp = input;
   scanf("%d", &input);


   while(input == temp)
            {
                printf("Your choice is invalid! Please enter a number between 1-9.");
                scanf("%c%d", &tempc, &input);
            }
            while(input < 0 || input > 9)
            {
                printf("Your choice is invalid! Please enter a number between 1-9.");
                scanf("%d", &input);
            }
   assign(input, symbol, number, human);
   moves(&stackPtr, input);
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
   printf("\n--> %s WON\n", player.player1);
   b++;
   player.score1++;
  }
  else if(human == 2)
  {
   printf("\n--> %s WON\n", player.player2);
   c++;
   player.score2++;
  }
 }
 else
 {
  printf("\nGame is Draw\n\n");
 }
 reverse(&stackPtr);
 printmoves(stackPtr, player);
 printf("Play again(Y/N)? ");
 scanf(" %c", &again);
 if (again == 'Y' || again == 'y')
 {
  d=-1;
  system("cls");
 }
 if (again == 'N' || again == 'n')
 {
  d=1;
  /*writeToFile(player.player1, player.player2, player.score1, player.score2);*/
  break;
 }
 deletelist(&stackPtr);
 }while(d==-1);

 return 0;
}

/*void writeToFile(char *player1, char *player2, int score1, int score2)
{
    FILE *fp;
    char str[50];
    char temp;

    fp = fopen("data.txt", "a+");
    strcat(str, player1);
    strcat(str, ";");
    temp = score1 + '0';
    strcat(str, temp);
    strcat(str, ";");
    strcat(str, player2);
    strcat(str, ";");
    itoa(score2, temp, 3);
    strcat(str, temp);
    strcat(str, ";");
    strcat(str, "\n");

    fprintf(fp, str);
    fclose(fp);
}*/

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
    if(number[4] != 'O' && number[4] == '5')
    {
        number[4] = 'X';
    }
    else if(number[4] == 'O' && number[0] == '1')
    {
        number[0] = 'X';
    }
    else if(number[0] == 'O' && number[1] == 'O' && number[2] == '3')
    {
        number[2] = 'X';
    }
    else if(number[2] == 'O' && number[1] == 'O' && number[0] == '1')
    {
        number[0] = 'X';
    }
    else if(number[0] == 'O' && number[2] == 'O' && number[1] == '2')
    {
        number[1] = 'X';
    }
    else if(number[3] == 'O' && number[4] == 'O' && number[5] == '6')
    {
        number[5] = 'X';
    }
    else if(number[5] == 'O' && number[4] == 'O' && number[3] == '4')
    {
        number[3] = 'X';
    }
    else if(number[3] == 'O' && number[5] == 'O' && number[4] == '5')
    {
        number[4] = 'X';
    }
    else if(number[6] == 'O' && number[7] == 'O' && number[8] == '9')
    {
        number[8] = 'X';
    }
    else if(number[8] == 'O' && number[7] == 'O' && number[6] == '7')
    {
        number[6] = 'X';
    }
    else if(number[6] == 'O' && number[8] == 'O' && number[7] == '8')
    {
        number[7] = 'X';
    }
    else if(number[0] == 'O' && number[3] == 'O' && number[6] == '7')
    {
        number[6] = 'X';
    }
    else if(number[6] == 'O' && number[3] == 'O' && number[0] == '1')
    {
        number[0] = 'X';
    }
    else if(number[0] == 'O' && number[6] == 'O' && number[3] == '4')
    {
        number[3] = 'X';
    }
    else if(number[1] == 'O' && number[4] == 'O' && number[7] == '8')
    {
        number[7] = 'X';
    }
    else if(number[7] == 'O' && number[4] == 'O' && number[1] == '2')
    {
        number[1] = 'X';
    }
    else if(number[1] == 'O' && number[7] == 'O' && number[4] == '5')
    {
        number[4] = 'X';
    }
    else if(number[2] == 'O' && number[5] == 'O' && number[8] == '9')
    {
        number[8] = 'X';
    }
    else if(number[8] == 'O' && number[5] == 'O' && number[2] == '3')
    {
        number[2] = 'X';
    }
    else if(number[2] == 'O' && number[8] == 'O' && number[5] == '6')
    {
        number[5] = 'X';
    }
    else if(number[6] == 'O' && number[4] == 'O' && number[2] == '3')
    {
        number[2] = 'X';
    }
    else if(number[2] == 'O' && number[4] == 'O' && number[6] == '7')
    {
        number[6] = 'X';
    }
    else if(number[2] == '3')
    {
        number[2] = 'X';
    }
    else if(number[6] == '7')
    {
        number[6] = 'X';
    }
    else if(number[8] == '9')
    {
        number[8] = 'X';
    }
    else if(number[1] == '2')
    {
        number[1] = 'X';
    }
    else if(number[3] == '4')
    {
        number[3] = 'X';
    }
    else if(number[4] == '5')
    {
        number[4] = 'X';
    }
    else if(number[5] == '6')
    {
        number[5] = 'X';
    }
    else if(number[7] == '8')
    {
        number[7] = 'X';
    }
}
void moves(nodePtr *stackPtr,int input)
{
    nodePtr newPtr;
    newPtr = malloc(sizeof(push));

 if (newPtr != NULL)
 {
    newPtr->data = input;
    newPtr->Ptr = *stackPtr;
    *stackPtr = newPtr;
 }
}
void printmoves(nodePtr currentPtr, struct name player)
{
 int x=1;
 printf("Moves:\n");
 while(currentPtr != NULL)
 {
  if (x%2!=0)
  {
   printf("%s\t\t: ", player.player1);
  }
  else if(x%2==0)
  {
   printf("%s\t\t: ", player.player2);
  }
  printf("Block %d\n", currentPtr->data);
  currentPtr = currentPtr->Ptr;
  x++;
 }
}
void reverse(struct push** rev)
{
 struct push *prev = NULL;
 struct push *current = *rev;
 struct push *next = NULL;
 while (current != NULL)
 {
  next = current->Ptr;
  current->Ptr = prev;
  prev = current;
  current = next;
 }
 *rev = prev;
}
void deletelist(struct push** rev)
{
    struct push *current = *rev;
    struct push *next = NULL;

    while (current != NULL)
    {
        next = current->Ptr;
        free(current);
        current = next;
    }
    *rev = NULL;
}
