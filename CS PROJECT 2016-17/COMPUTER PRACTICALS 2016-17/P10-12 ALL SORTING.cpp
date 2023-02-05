#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{
clrscr();
int ch;
int i,j,x,k,z,l,m,n,o,p,a[50],small;
q :
cout<<"Enter the choice:- \n1:Selection  \n2:Bubble \n3:Insertion \n4:Exit"<<endl;
cin>>ch;
switch(ch)
{
case 1:
cout<<"Enter size of array:- "<<endl;
cin>>n;
cout<<endl;
cout<<"Enter the elements:-"<<endl;

for(i=0;i<n;i++)
   {
   cin>>a[i];
   cout<<endl;
   }

for(j=0;j<n;j++)
   {
   small=a[j];
   p=j;
 for(i=j;i<n;i++)
    {
    if(small>a[i])
    {
    small=a[i];
    p=i;
    }
    }
    for(k=p;k>j;k--)
   {
   a[k]=a[k-1];
   }
   a[j]=small;
   }
cout<<"Result:-"<<endl;
  for(z=0;z<n;z++)
  {
  cout<<a[z]<<" ";
  }
  cout<<endl;
  getch();
  goto q;
  case 2:
cout<<"Enter the size of array:-"<<endl;
cin>>n;
cout<<"Enter the elements:-"<<endl;
  for(i=0;i<n;i++)
  cin>>a[i];
for(j=0;j<n;j++)
  {
  for(i=0;i<n-1;i++)
   {
   if (a[i]>a[i+1])
   {
   x=a[i+1];
   a[i+1]=a[i];
   a[i]=x;
   }
  }
  }
cout<<"Result"<<endl;
  for (i=0;i<n;i++)
   {
   cout<<a[i]<<" ";
   }
   cout<<endl;
   getch();
 goto q;

 case 3 :
 int m=-32767;
  cout<<"enter the size of array:-"<<endl;
  cin>>n;
  cout<<"enter the array"<<endl;
  for(i=1;i<=n;i++)
  {cin>>a[i];}
  a[0]=m;
  for(i=1;i<=n;i++)
  {for(j=0;j<i;j++)
  {if(a[i]<a[j])
  {p=a[i];
  for(k=i-1;k>=j;k--)
  {a[k+1]=a[k];}
  a[j]=p;}}}
  for(i=1;i<=n;i++)
  {cout<<a[i]<<" ";}
  cout<<endl;
  getch();
  goto q;

case 4:
exit(0);
default:
cout<<"Wrong choice"<<endl;
goto q;

}
getch();
}