#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
void view(int,int);
int checkmatchX(int[]);
int checkO(int,int[]);
int checkX(int,int[]);
void Gotoxy(int,int);
void Gotoxy(int x,int y)
{
	  COORD c;
  c.X=x;
  c.Y=y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void home();
void home()
{
	char ch;
 Gotoxy(35,0);
  printf("TIC TAC TOE\n\n\n\n");
  printf("Players:- 2\n\n");
  printf("Goal:-\n");
  printf("The goal of Tic Tac Toe is to be the first player to get three in a row on a 3x3 grid\n\n");
  printf("WARNING:-\n");
  printf("Please don't press any extra keys");
  Gotoxy(25,13);
  printf("Enter p to play or y to quit:");
  ch=getchar();
  if(ch=='y')
  exit(1);
  if(ch=='p');
    system ("cls"); 
}
void MainGame();
void MainGame()
{
   COORD c;
  c.X=35;
  c.Y=0;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
  printf("TIC TAC TOE\n\n");
  printf("Players 1's symbol:X\n");
  printf("Players 2's symbol:O\n");	
}
void lines();
void lines()
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut,11);
	int i;
	for(i=5;i<=11;i++)
	{
		Gotoxy(30,i);
		printf("|");
	}	
    for(i=5;i<=11;i++)
	{
		Gotoxy(37,i);
		printf("|");
	}
	  for(i=25;i<=42;i++)
	{
		Gotoxy(i,7);
		printf("-");
	}
	for(i=25;i<=42;i++)
	{
		Gotoxy(i,9);
		printf("-");
	}
	SetConsoleTextAttribute(hStdOut,7);	
	int j=1;
	for(i=27;i<=41;i=i+7){
	Gotoxy(i,6);
	printf("%d",j);
	j++;}
	j=4;	
		for(i=27;i<=41;i=i+7){
	Gotoxy(i,8);
	printf("%d",j);
	j++;}	
	j=7;
		for(i=27;i<=41;i=i+7){
	Gotoxy(i,10);
	printf("%d",j);
	j++;}
}
void logic();
void logic()
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int n,m,arrO[11]={0},arrX[11]={0},draw=0,winX=0,winO=0,count=0;
  printf("\n\n\n");
  printf("Enter your choice X:");
while(1)
{
Gotoxy(18,13);
printf("X");//turn of player 1
Gotoxy(20,13);
scanf("%d",&n);
     while(checkO(n,arrO)==0)//check for valid move
    {
	// Gotoxy(18,14);
	// printf("Enter valid move");
	 Gotoxy(20,13);
	 scanf("%d",&n);
    }
      arrX[n]=1;
      view(n,1);// view X
    if(checkmatchX(arrX)==1)//X win or not
    {
    	winX=69;
    	break;
    }
      count++;
    if(count>=9)//draw
	  {
	  	draw=69;
       break;
      }
    Gotoxy(18,13);
    printf("O");//turn of player 2
    Gotoxy(20,13);
    scanf("%d",&m);
    while(checkX(m,arrX)==0)//check for valid move
    {
      // Gotoxy(18,14);
	    //printf("Enter valid move");
	    Gotoxy(20,13);
	    scanf("%d",&m);		
    }
    view(m,2);//view O
    arrO[m]=1;
    count++;
    if(checkmatchX(arrO)==1)//O win or not
    {
    	winO=69;
    	break;
    }
}
  if(winX==69)
  {
  SetConsoleTextAttribute(hStdOut,5);	
	Gotoxy(30,16);
	printf("Player 1 wins");
  }
      if(winO==69)
     {
     	SetConsoleTextAttribute(hStdOut,5);
	    Gotoxy(30,16);
	     printf("Player 2 wins");
     }
        if(draw==69)
        {
        	SetConsoleTextAttribute(hStdOut,5);
            Gotoxy(30,16);
	        printf("Game is draw");	
        }
}
int checkX(int m,int arrX[])
{
	if(m==0)
	return 0;
	if(arrX[m]==0)
	return 1;
	else
	return 0;	
}
int checkO(int n,int arrO[])
{
	if(n==0)
	return 0;
	if(arrO[n]==0)
	return 1;
	else
	return 0;	
}
int checkmatchX(int arrX[])
{
	int i;
	for(i=1;i<=9;i=i+3)
	{
	     if(arrX[i]==1 && arrX[i+1]==1 && arrX[i+2]==1)
	     return 1;
    }
    for(i=1;i<=3;i++)
    {
    	 if(arrX[i]==1 && arrX[i+3]==1 && arrX[i+6]==1)
    	 return 1;
    }
    if(arrX[1]==1 && arrX[5]==1 && arrX[9]==1)
    return 1;
    if(arrX[3]==1 && arrX[5]==1 && arrX[7]==1)
    return 1;
    return 0;
}
void view(int n,int ver)
{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	while(1)
	{
		if(n==1)
		{
		  Gotoxy(27,6);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
	    if(n==2)
		{
		  Gotoxy(34,6);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
	    if(n==3)
		{
		  Gotoxy(41,6);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
	    if(n==4)
		{
		  Gotoxy(27,8);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
	    if(n==5)
		{
		  Gotoxy(34,8);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
		if(n==6)
		{
		  Gotoxy(41,8);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
	    if(n==7)
		{
		  Gotoxy(27,10);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
	    if(n==8)
		{
		  Gotoxy(34,10);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }
	    if(n==9)
		{
		  Gotoxy(41,10);
		  if(ver==1)
		  printf("X");
		  else
		  printf("O");
		  break;
	    }	
	}
	SetConsoleTextAttribute(hStdOut,7);
	
}
int main(void)
{
	char ce;
    home();
    while(1)
    {
    MainGame();
    lines();
    logic();
    Gotoxy(35,18);
    printf("Press a to play again");
    fflush(stdin);
    ce=getchar();
    if(ce=='a'){
   system ("cls"); 
    continue; 
              }
    else
    break;
    }
 std::cin.get();
 getchar();
}

