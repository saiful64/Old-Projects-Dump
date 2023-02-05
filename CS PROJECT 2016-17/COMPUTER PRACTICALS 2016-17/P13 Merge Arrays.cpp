//prg to merge arrays
//Downloaded From www.c4cpp.co.nr
//(C)2009.All rights reserved.
#include<iostream.h>
#include<conio.h>
int c[100],i,j,k;

class merged
{
int na,nb,a[50],b[50];
public:
void merge();
void display();
void input();
}g;

void merged::merge()
{
int j=0;
int i=na-1;
while((i>0)&&(j<nb))
{
if (b[j]<a[i])
{
c[k]=a[i];
i--;
k++;
}
if (b[j]>a[i])
{
c[k]=b[j];
j++;
k++;
}
if (b[j]==a[i])
{
c[k]=b[j];
j++;
k++;
c[k]=a[i];
i--;
k++;
}
}
if(i==-1)
{
while(j<nb)
{
c[k]=b[j];
j++;
k++;
}
}
if(j==nb)
{
while(i>=0)
{
c[k]=a[i];
i--;
k++;
}
}
}


void merged::display()
{
for(i=0;i<na+nb;i++)
cout<<c[i];
}

void merged::input()
{
cout<<"Enter A Lim"<<endl;
cin>>na;
cout<<"Enter B Limit"<<endl;
cin>>nb;
cout<<"Enter array A"<<endl;
for(i=0;i<na;i++)
cin>>a[i];
cout<<"Enter Array B"<<endl;
for(j=0;j<nb;j++)
cin>>b[j];
}


void main()
{
clrscr();
g.input();
g.merge();
g.display();
getch();
}
