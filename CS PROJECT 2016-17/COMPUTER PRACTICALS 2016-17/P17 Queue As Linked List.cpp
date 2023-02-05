//Queue as a linked list
//Downloaded From www.c4cpp.co.nr
//(C)2009.All rights reserved.
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

struct node
  {char name[20];
   int age;
   node *link;
  }*ptr=NULL,*save=NULL;
class queue
  {node *rear,*front;
   public:
   queue()
     {rear=NULL;
      front=NULL;
     }
   void queins();
   void quedel();
   void display();
  }q;

void queue::queins()
  {ptr=new node;
   if(ptr==NULL)
     {cout<<"Queue overflow ";
     }
   else
     {cout<<"Enter the name ";
      gets(ptr->name);
      cout<<"Enter the age ";
      cin>>ptr->age;
      ptr->link=NULL;
      if(rear==NULL)
	{rear=ptr;
	 front=ptr;
	}
      else
	{rear->link=ptr;
	 rear=ptr;
	}
     }
   }

void queue::quedel()
  {if(rear==NULL)
    {cout<<"Queue underflow ";
    }
   else
    {if(front==rear)
      {save=front;
       front=NULL;
       rear=NULL;
       cout<<"Name ";
       puts(save->name);
       cout<<"Age "<<save->age;
       delete save;
      }
     else
      {save=front;
       front=front->link;
       cout<<"Name ";
       puts(save->name);
       cout<<"Age "<<save->age;
       delete save;
      }
    }
  }

void queue::display()
  {if(rear==NULL)
    {cout<<"No elements ";
    }
   else
    {ptr=front;
     while(ptr!=NULL)
       {cout<<"Name ";
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
     {case 1:q.queins();
	     goto X;
      case 2:q.quedel();
	     goto X;
      case 3:q.display();
	     goto X;

      case 4:exit(0);

      default:cout<<"Wrong choice ";
	      goto X;
     }
   getch();
  }