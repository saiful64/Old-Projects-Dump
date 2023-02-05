#include<iostream.h>
#include<conio.h>
int LSearch(int[],int,int);
void main()
{
	int AR[50],ITEM,N,index;
	clrscr();
	cout<<"How many elements you want to enter?:";
	cin>>N;

	cout<<"\nNow enter Array elements...\n";
	for(int i=0;i<N;i++)
	{
	  cout<<i+1<<".element:";
	  cin>>AR[i];
	}

	cout<<"\nEnter element to be searched for:";
	cin>>ITEM;

	index = LSearch(AR,N,ITEM);
	if(index==-1)
	{
	 cout<<"Sorry!!Element not found.";
	}
	else
	{
	cout<<"Element found at index "<<index;
	cout<<" Position "<<index+1<<endl;
	}
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
