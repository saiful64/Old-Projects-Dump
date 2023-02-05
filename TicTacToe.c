#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char sq [10]= {'0','1','2','3','4','5','6','7','8','9' };
int choice,player;

int chkForWin();
void dispBoard();
void markBoard(char);

int main()
{
	int gameStatus;
	char mark;
	player=1;
	
	do 
	{
		dispBoard();
		
		//Changing of turns
		player = (player % 2) ? 1 : 2;
		
		printf("Player %d, Enter a number: ",player);
		scanf("%d",&choice);
		
		//Place mark based on player
		mark = (player ==1) ? 'x' : 'o';
		
		//Set board based on player mark
		markBoard(mark);
		
		gameStatus = chkForWin();
		
		player++;
		
		
	}while(gameStatus==-1);
	
	if(gameStatus==1)
		printf("====>\a Player %d win <====", --player);
	else
		printf("====>\a Game Draw <====");
	
	getch();
	return 0;
}

/**********************
FUNCTION TO RETURN GAME STATUS
1  FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
0  FOR GAME IS OVER AND NO RESULT
**********************/

int chkForWin()
{
	int retVal=0;
	
	if(sq[1]==sq[2] && sq[2]==sq[3])
		retVal=1;
	else if(sq[4]==sq[5] && sq[5]==sq[6])
		retVal=1;
	else if(sq[7]==sq[8] && sq[8]==sq[9])
		retVal=1;
	else if(sq[1]==sq[4] && sq[4]==sq[7])
		retVal=1;
	else if(sq[2]==sq[5] && sq[5]==sq[8])
		retVal=1;
	else if(sq[3]==sq[6] && sq[6]==sq[9])
		retVal=1;
	else if(sq[1]==sq[5] && sq[5]==sq[9])
		retVal=1;
	else if(sq[3]==sq[5] && sq[5]==sq[9])
		retVal=1;
	else if(sq[1]!='1' && sq[2]!='2' && sq[3]!='3' && sq[4]!='4' && sq[5]!='5' && sq[6]!='6' && sq[7]!='7' && sq[8]!='8' && sq[9]!='9')
		retVal=0;
	else
		retVal=-1;
		
	return retVal;
}


/*****************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYER MARK
*****************************************************/

void dispBoard()
{
	system("cls");
	
	printf("\n\n Tic Tac Toe \n\n");
	printf("Player1 ( x )  -  Player2 ( 0 ) \n\n");
	
	printf("	|	|	\n");
	printf("    %c   |   %c   |   %c \n",sq[1],sq[2],sq[3]);
	
	printf("________|_______|_______\n");
	printf("	|	|	\n");
	
	printf("	|	|	\n");
	printf("    %c   |   %c   |  %c \n",sq[4],sq[5],sq[6]);
	
	printf("________|_______|_______\n");
	printf("	|	|	\n");
	
		printf("	|	|	\n");
	printf("    %c   |   %c   |  %c \n",sq[7],sq[8],sq[9]);
	
	printf("	|	|	\n");	
}

/***********************
SET THE BOARD WITH x / o 
***********************/

void markBoard(char mark)
{
	if(choice==1 && sq[1]=='1')
	sq[1]=mark;
	else if(choice==2 && sq[2]=='2')
	sq[2]=mark;
	else if(choice==3 && sq[3]=='3')
	sq[3]=mark;
	else if(choice==4 && sq[4]=='4')
	sq[4]=mark;
	else if(choice==5 && sq[5]=='5')
	sq[5]=mark;
	else if(choice==6 && sq[6]=='6')
	sq[6]=mark;
	else if(choice==7 && sq[7]=='7')
	sq[7]=mark;
	else if(choice==8 && sq[8]=='8')
	sq[8]=mark;
	else if(choice==9 && sq[9]=='9')
	sq[9]=mark;
	else
		{
			printf("INVALID MOVE");	
			player--;
			getch();
		}
	
}
