#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

 struct address
  {
   int houseno;
   char area[20],city[20],state[20];
  };
 struct worker
  {
   int id;
   char name[20],designation[20];
   address addr;
   float salary;
  };
 void main()
 {
  clrscr();
  worker w[10]; int empno;
  for(int i=0;i<10;i++)
  {
   cout<<"Enter The Details of Employee("<<i+1<<"/10):-"<<endl;
   cout<<"Worker id:";
   cin>>w[i].id;
   cout<<"\nName:";
   gets(w[i].name);
   cout<<"\nDesignation:";
   gets(w[i].designation);
   cout<<"\nArea:";
   gets(w[i].addr.area);
   cout<<"\nCity:";
   gets(w[i].addr.city);
   cout<<"\nState:";
   gets(w[i].addr.state);
  }

  cout<<"\nEnter the Employee id you want to Display:";
  cin>>empno;

  for(i=0;i<10;i++)
  {
   if(empno==w[i].id)
    {
      cout<<"\nEmployee Details:-"<<endl;
      cout<<"\nWorker id:"<<w[i].id;
      cout<<"\nName:";
      puts(w[i].name);
      cout<<"\nDesignation:";
      puts(w[i].designation);
      cout<<"\nArea:";
      puts(w[i].addr.area);
      cout<<"\nCity:";
      puts(w[i].addr.city);
      cout<<"\nState:";
      puts(w[i].addr.state);
    }
   else
    cout<<"Employee Details Not Found!!!";
    getch();
    exit(0);
  }
  getch();
  }
