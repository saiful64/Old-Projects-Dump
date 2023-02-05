#include<iostream.h>
#include<conio.h>

int BSearch(int[],int,int);    //binary search(array,size,item)
void main()
{
  int  AR[50],ITEM,N,index;
  clrscr();

  cout<<"How many elements you want to enter?:";
  cin>>N;
      cout<<"Enter element in Ascending order...\n";
      for(int i=0;i<N;i++)
      {
	 cout<<i<<".element?:";
	 cin>>AR[i];
      }

      cout<<"Enter the element to be searched?:";
      cin>>ITEM;

      index = BSearch(AR,N,ITEM);
      if(index==-1)
      cout<<"Sorry! Item not found!";
      else
      cout<<"element found at index:"<<index;

      getch();
}

int BSearch(int AR[],int size,int item)
{
 int beg, last, mid;

   beg = 0;
   last = size - 1;

   while(beg<=last)
   {
      mid = (beg + last)/2;
      if(item==AR[mid])
       return mid;
      else
       if(item>AR[mid])
	beg = mid + 1;
       else
       last = mid - 1;
  }
  return -1;
}
