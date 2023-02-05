//Stack as a linked list
//Downloaded From www.c4cpp.co.nr
//(C)2009.All rights reserved.
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>

struct node
  {char name[20];
   int age;
   node *link;
  }*ptr=NULL,*save=NULL;
class stack
  {node *top;
   public:
   stack()
     {top=NULL;
     }
   void stackpush();
   void stackpop();
   void display();
  }st;

void stack::stackpush()
  {ptr=new node;
   if(ptr==NULL)
     {cout<<"Overflow ";
     }
   else
     {cout<<"Enter the name ";
      gets(ptr->name);
      cout<<"Enter the age ";
      cin>>ptr->age;
      ptr->link=NULL;
      if(top==NULL)
	{top=ptr;
	}
      else
	{ptr->link=top;
	 top=ptr;
	}
     }
   }

void stack::stackpop()
  {if(top==NULL)
    {cout<<"Underflow ";
    }
   else
    {save=top;
     top=top->link;
     cout<<"Name ";
     puts(save->name);
     cout<<"Age "<<save->age;
     delete save;
    }
  }

void stack::display()
  {if(top==NULL)
    {cout<<"No elements.."<<endl;
    }
   else
    {ptr=top;
     while(ptr!=NULL)
       {cout<<"\nName ";
	puts(ptr->name);
	cout<<"Age "<<ptr->age;
	ptr=ptr->link;
       }
    }
  }



void main()
  {clrscr();
   int ch;
      X:
   cout<<"\nEnter your choice\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
   cin>>ch;
   switch(ch)
     {case 1:st.stackpush();
	     goto X;
      case 2:st.stackpop();
	     goto X;
      case 3:st.display();
	     goto X;
      default:cout<<"Wrong choice ";
	      goto X;
      case 4:exit(0);
     }
   getch();
  }