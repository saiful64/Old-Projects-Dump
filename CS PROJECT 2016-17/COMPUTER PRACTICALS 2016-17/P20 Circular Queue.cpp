//Circular queue
//Downloaded From www.c4cpp.co.nr
//(C)2009.All rights reserved.
#include<iostream.h>
#include<conio.h>
#include<process.h>

class queue
  {int data[10];
   int front,rear;
   public:
   queue()
     {front=-1;
      rear=-1;
     }
   void add();
   void remove();
   void display();
  };

void queue::add()
  {if((rear+1==front)||(rear==9&&front==0))
     {cout<<"Overflow ";
     }
   else
     {if((rear==-1) &&(front==-1))
	{rear=0;
	 front=0;
	}
      else if(rear==9)
	{rear=0;
	}
      else
	{rear++;
	}
      cout<<"Enter the element ";
      cin>>data[rear];
     }
  }

void queue::remove()
  {if(front==-1&&rear==-1)
     {cout<<"Underflow ";
     }
   else
     {if(front==9)
       {front=0;
       }
      else if(front==rear)
       {front=-1;
	rear=-1;
       }
      else
       {front++;
       }
     }
  }

void queue::display()
  {int i=0,n=9;
   if(rear==-1)
     {cout<<"No elements.."<<endl;
     }
   else
   { if(rear>front)
     {for(i=0;i<front;i++)
	{cout<<"_";
	}
      for(i=front;i<=rear;i++)
	{cout<<data[i];
	}
      for(i=rear+1;i<n;i++)
	{cout<<"_";
	}
     }
   else
     {for(i=0;i<=rear;i++)
	{cout<<data[i];
	}
      for(i=rear+1;i<front;i++)
	{cout<<"_";
	}
      for(i=front;i<n;i++)
	{cout<<data[i];
	}
    } }
  }

void main()
  {clrscr();
   int ch;
   queue queue;
   X:
   cout<<"\nEnter your choice\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
   cin>>ch;
   switch(ch)
     {case 1:queue.add();
	     goto X;
      case 2:queue.remove();
	     goto X;
      case 3:queue.display();
	     goto X;
      case 4:exit(0);
     }
   getch();
  }