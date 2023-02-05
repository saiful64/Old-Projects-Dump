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
   student s;
   cout<<"Enter Student Paticulars:-"<<endl;
   s.enter();
   cout<<"Student Details:-"<<endl;
   s.disp();
   getch();
 }

 void student::enter()
  {
   cout<<"Rno:"; cin>>rno;
   cout<<"\nName:"; gets(name);
   cout<<"\nPercentage:"; cin>>percentage;
   cout<<"\nRank:"; cin>>rank;
  }

 void student::disp()
  {
   cout<<"Rno:"<<rno<<endl;
   cout<<"Name:"; puts(name);
   cout<<"Percentage:"<<percentage<<"\nRank:"<<rank;
  }
