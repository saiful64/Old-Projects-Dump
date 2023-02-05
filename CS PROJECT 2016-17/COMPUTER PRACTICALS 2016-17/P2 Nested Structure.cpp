#include<iostream.h>
#include<conio.h>
#include<stdio.h>

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
  worker w;
  cout<<"Worker id:";
  cin>>w.id;
  cout<<"\nName:";
  gets(w.name);
  cout<<"\nDesignation:";
  gets(w.designation);
  cout<<"\nArea:";
  gets(w.addr.area);
  cout<<"\nCity:";
  gets(w.addr.city);
  cout<<"\nState:";
  gets(w.addr.state);
  cout<<"\nEmployee Details:-"<<endl;
  cout<<"\nWorker id:"<<w.id;
  cout<<"\nName:";
  puts(w.name);
  cout<<"\nDesignation:";
  puts(w.designation);
  cout<<"\nArea:";
  puts(w.addr.area);
  cout<<"\nCity:";
  puts(w.addr.city);
  cout<<"\nState:";
  puts(w.addr.state);
  getch();
  }
