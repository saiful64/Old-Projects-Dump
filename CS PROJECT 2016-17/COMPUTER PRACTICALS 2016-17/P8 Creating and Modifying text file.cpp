#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>

 void create();
 void modify();
 void display();

void main()
 {
  clrscr();
  int op;
  cout<<"Please select any option:-\n1.Create File\n2.Modify\n3.Display the File\n4.Exit";
  cin>>op;
  switch(op)
   {
    case 1:
     create();
     cout<<"\nFile created Successfully";
     break;

    case 2:
     modify();
     cout<<"\nFile Modified";
     break;

    case 3:
    display();
    break;

    case 4:
     exit(0);

    default:
     cout<<"Wrong Choice";
    break;
   }
  getch();
 }

void create()
 {
  char content[20];
  ofstream fout;
  fout.open("File.txt");
  cout<<"Enter Your Contents:";
  cin.get(content,30,'%');
  fout<<content;
  fout.close();
 }

void modify()
 {
  int ch; char con[20];
  cout<<"What would you like:-\n1.Add more \n2.Delete";
  cin>>ch;
  ofstream f;
  if(ch==1)
   {
    f.open("File.txt",ios::app);
    cout<<"Enter additional contents:";
    cin.get(con,20,'%');
    f<<con;
    f.close();
   }
   else if(ch==2)
    {
     f.open("File.txt",ios::trunc);
     cout<<"Enter new contents:";
     cin.get(con,20,'%');
     f<<con;
     f.close();
    }
    else
     cout<<"Wrong Choice";
  }

  void 	display()
   {
    char cont[50];
    ifstream fin("File.txt");
    fin.seekg(0,ios::cur);
    fin.get(cont,50,'%');
    puts(cont);
    fin.close();
   }

