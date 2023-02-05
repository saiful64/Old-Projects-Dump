//Multiplication of Matrix
//Downloaded From www.c4cpp.co.nr
//(C)2009.All rights reserved.

#include<iostream.h>
#include<conio.h>

class matrix
{
int x[10][10];
int m,n;
public:
void input();
void output();
void multiply(matrix,matrix);
};

void matrix::input()
{
cout<<"Enter Row"<<endl;
cin>>m;
cout<<"Enter Column"<<endl;
cin>>n;
cout<<"Matrix"<<endl;
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
cin>>x[i][j];
}
}
}
void matrix :: output()
{
for(int i=0;i<m;i++)
{
cout<<endl;
for(int j=0;j<n;j++)
{
cout<<x[i][j]<<"   ";
}
}
}
void matrix :: multiply(matrix m1, matrix m2)
{
for(int i=0;i<m1.m;i++)
{
for(int j=0;j<m2.n;j++)
{
x[i][j]=0;
for(int k=0;k<m1.n;k++)
{
x[i][j]=x[i][j] +( m1.x[i][k] * m2.x[k][j]);
m=m1.m;
n=m2.n;
}
}
}
}
void main()
{
clrscr();
matrix m1,m2,m3;
m1.input();
m2.input();
m3.multiply(m1,m2);
m3.output();
getch();
}
