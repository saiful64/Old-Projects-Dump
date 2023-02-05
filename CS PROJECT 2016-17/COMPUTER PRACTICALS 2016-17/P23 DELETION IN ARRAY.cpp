#include<iostream.h>
#include<conio.h>
#include<process.h>

int LSearch(int[],int,int);
void main()
{
   int AR[50],ITEM,N,index;
   clrscr();
   cout<<"How many elements you want to enter?:";
   cin>>N;

   cout<<"\nEnter Array elements...\n";
   for(int i=0;i<N;i++)
   {  cout<<i<<".element:?"; cin>>AR[i]; }

   char ch='y';

   while(ch=='y'||ch=='Y')
   {
	cout<<"\nEnter the element to be deleted?:";
	cin>>ITEM;

	if(N==0)
	{  cout<<"UNDERFLOW!!!"; exit(1); }

	index=LSearch(AR,N,ITEM);
	if(index!=-1)
	   AR[index]=0;
	else
	 {  cout<<"\nSorry! No such element "; exit(1); }

	 cout<<"\nThe Array is as follow\n";

	 for(i=0;i<N;i++)
	 { cout<<AR[i]<<"  "; }
	 getch();

	 cout<<"\nAfter the emptied space shifted to end of array\n";
	 for(i=index;i<N;i++)
	 { AR[i]=AR[i+1]; }

	 N-=1;
	 cout<<"Want to delete more elements?(y/n):";
	 cin>>ch;
      }

      cout<<"\nArray after shifting all emptied space towards right\n";
      for(i=0;i<N;i++)
       cout<<AR[i]<<"  ";

       getch();
}

int LSearch(int AR[],int size,int item)
{
   for(int i=0;i<size;i++)
   {
     if(AR[i]==item)
      return i;
   }
   return -1;
}

