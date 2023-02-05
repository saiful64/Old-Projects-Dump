#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class student
 {
  private:
   char name[20];
   int rno;

  protected:
   float percentage;
   int rank;

  public:
  void enter();
  void disp();
 };

 void main()
 {
   clrscr();
   student s[10];
   cout<<"Enter Student Paticulars:-"<<endl;
   for(int i=0;i<10;i++)
    {
     cout<<"Student ("<<i+1<<"/10)";
     s[i].enter();
    }
   cout<<"Student Details:-"<<endl;
   for(int j=0;j<10;j++)
   {
     cout<<"Student ("<<j+1<<"/10)";
     s[j].disp();
   }
   getch();
 }

 void student::enter()
  {
   cout<<"\nRno:"; cin>>rno;
   cout<<"\nName:"; gets(name);
   cout<<"\nPercentage:"; cin>>percentage;
   cout<<"\nRank:"; cin>>rank;
  }

 void student::disp()
  {
   cout<<"\nRno:"<<rno<<endl;
   cout<<"Name:"; puts(name);
   cout<<"Percentage:"<<percentage<<"\nRank:"<<rank;
  }
