#include<iostream.h>
#include<conio.h>
int Large(int a[],int size)
 {
  int larg=-32767;
  for(int i=0;i<(size-1);i++)
   {
    if(a[i]>larg)
    larg=a[i];
   }
   return larg;
 }

void main()
 {
  clrscr();
  int arr[20],siz;
  cout<<"Enter the array size:";
  cin>>siz;
  cout<<"\nEnter Array elements:";
  for(int j=0;j<siz;j++)
  cin>>arr[j];
  cout<<"\nLargest Element is:"<<Large(arr,siz);
  getch();
 }











