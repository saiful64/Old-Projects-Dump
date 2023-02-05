#include<iostream.h>
#include<stdio.h>
#include <fstream.h>
#include <conio.h>

void CountLine()
{
  ifstream FIL("STORY.TXT");
  int LINES=0;
  char STR;
   while (FIL)
      {
	FIL.get(STR);
	if (STR=='.')
	LINES++;
      }
  cout << "\nNo. of lines:"<<LINES<< endl;
}

void Countcharecters()
{
	ifstream afile;
	afile.open("STORY.TXT");
	char ch;
	int c=0;
	while(afile)
	{
		afile.get(ch);
		if(ch!=' '&&ch!='.')
		   c++;
	}
	cout<<"\nNo. of charecters:"<< c;
}

void Countwords()
{
	ifstream affile;
	affile.open("STORY.TXT");
	char chh;
	int cc=1;
	while(affile)
	{
		affile.get(chh);
		if(chh==' ')
		   cc++;
	}
	cout<<"\nNo. of words:"<<cc;
}

void main( )
{
	clrscr();
	Countcharecters();
	CountLine();
	Countwords();
  getch();
}
