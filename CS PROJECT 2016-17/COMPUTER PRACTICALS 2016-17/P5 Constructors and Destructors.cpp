#include<iostream.h>
#include<conio.h>

class T
{
 private:
 int a,b,c;

 public:
 T()
  {
   a=8;b=4;c=7;
  }
 T(int x, int y)
  {
   a=x;
   b=y;
  }
 ~T()
  {
   cout<<"Destroyed!!!"<<endl;
  }
 void display()
  {
   cout<<a<<":"<<b<<":"<<c<<endl;
  }
 };

 void main()
 {
 T T1;
 T T2(3,5);
 T1.display();
 getch();
 }