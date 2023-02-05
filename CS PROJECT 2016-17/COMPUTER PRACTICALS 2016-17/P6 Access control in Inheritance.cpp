#include<iostream.h>
#include<conio.h>
#include<stdio.h>

const int LEN=25;

class Employee
 {
  private:
   char name[LEN];
   unsigned long enumb;

  protected:
   float basic;
   void getbasic()
    {
     cout<<"Basic:"; cin>>basic;
    }

  public:
   void getdata()
    {
      cout<<"Name:"; gets(name);
      cout<<"Empno:"; cin>>enumb;
    }
    void putdata()
    {
     cout<<"Name:"; puts(name);
     cout<<"Empno:"<<enumb;
     cout<<"\nBasic:"<<basic;
    }
  };

 class Manager : public Employee
  {
   private:
    char title[LEN];

   public:
    void getdata()
     {
       Employee::getdata();
       getbasic();
       cout<<"Enter Title:"; gets(title);
     }
    void putdata()
     {
      Employee::putdata();
      cout<<"\nTitle:"; puts(title);
     }
  };

  class CEO : private Employee
   {
     private:
       char designation[LEN];
     public:
       void getdata()
	{
	 Employee::getdata();
	 getbasic();
	 cout<<"Designation:"; gets(designation);
	}
       void putdata()
	{
	 Employee::putdata();
	 cout<<"\nDesignation:"; puts(designation);
	}
   };

   void main()
    {
      Manager m1;
      CEO c1;
      cout<<"Manager:-";
      m1.getdata();
      cout<<"CEO:-";
      c1.getdata();
      cout<<"Manager Detail:-";
      m1.putdata();
      cout<<"\nCEO Details:-";
      c1.putdata();
      getch();
    }