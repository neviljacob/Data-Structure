#include<stdio.h>
#include<conio.h>
struct node
 { int data;
   struct node *left;
   struct node *right;
 };
typedef struct node node;
node *getnode();
main()
 { node *first;
   int ch,item,pos,n,d;
   InDL(&first);
   clrscr();
   printf("\n Creating a doubly linked list...");
   printf("\n How many nodes do you want to create?");
   scanf("%d",&n);
   DLC(&first,n);
   while(1)
    { printf("\n... Enter your choice...");
      printf("\n 1.Insert at first node");
      printf("\n 2.Insert at last node");
      printf("\n 3.Insert at any position");
      printf("\n 4.Delete at first node");
      printf("\n 5.Delete at last node");
      printf("\n 6.Delete at any node");
      printf("\n 7.Display all operations");
      printf("\n 8.Exit\n");
      scanf("%d",&ch);
      switch(ch)
       { case 1:printf("\n Enter the item to be inserted:");
		scanf("%d",&item);
		IDLF(&first,item);
		break;
	 case 2:printf("\n Enter the item to be inserted:");
		scanf("%d",&item);
		IDLL(&first,item);
		break;

	 case 3:printf("\n Enter the item:");
		scanf("%d",&item);
		printf("\n Enter the position");
		scanf("%d",&pos);
		IDLA(&first,item,pos);
		break;
	 case 4:DDLF(&first);
		break;
	 case 5:DDLL(&first);
		break;
	 case 6:printf("\n Enter the node number to be deleted:");
		scanf("%d",&n);
		DDLA(&first,n);
		break;
	 case 7:TDL(first);
		break;
	 case 8:exit(0);
		break;
	}
     }
 }


InDL(node **first)
{ (*first)=NULL;
return 0;
 }



DLC(node **f,int n)
 { node *temp,*current;
   int i,item;
   for(i=1;i<=n;i++)
    { printf("\n Enter the data field %d:",i);
      scanf("%d",&item);
      temp=getnode();
      temp->data=item;
      temp->right=NULL;
      if(*f==NULL)
       { (*f)=temp;
	  temp->left=NULL;
	}
      else
       { current->right=temp;
	 temp->left=current;
	}

       current=temp;
    }
   return 0;
  }


IDLF(node **f,int item)
 { node *temp;
   int i;
   temp=getnode();
   temp->data=item;
   temp->left=NULL;
      if(*f==NULL)
       {
	  temp->right=NULL;
	}
      else
       { temp->right=(*f);
	 (*f)->left=temp;
	}

    (*f)=temp;

   return 0;
  }


IDLL(node **f,int item)
 { node *temp,*current;

      temp=getnode();
      temp->data=item;
      temp->right=NULL;
      if(*f==NULL)
       {
	  temp->left=NULL;
	  (*f)=temp;
	}
      else
       { current=(*f);
	 while(current->right!=NULL)
	   { current=current->right;
	    }
	 temp->left=current;
	 current->right=temp;
	}
	return 0;
  }


IDLA(node **f,int item,int pos)
 { node *temp,*current;
      int i;
      temp=getnode();
      temp->data=item;

      if(pos==1)
       { if(*f!=NULL)
	    (*f)->left=temp;
	 temp->right=(*f);
	 temp->left=NULL;
	 (*f)=temp;
	}
      else
       { i=2;
	 current=(*f);
	 while((i<pos)&&(current->right!=NULL))
	   { i++;
	     current=current->right;
	    }
	 temp->left=current;
	 temp->right=current->right;
	 if(current->right!=NULL)
	   { temp->right->left=temp;
	     current->right=temp;
	}
  }
  return 0;
}


DDLF(node **first)
 { node *current;
   int item;
   if(*first==NULL)
       { printf("\n List is empty");
	 return 0;
	}

    current=(*first);
    (*first)=(*first)->right;
    if(*first!=NULL)
	(*first)->left=NULL;
    item=current->data;
    freenode(current);
    printf("\n Deleted item is:%d",item);

   return 0;
  }


DDLL(node **first)
 { node *current;
   int item;
   if(*first==NULL)
       { printf("\n List is empty");
	 return;
	}

    current=(*first);
    while(current->right!=NULL)
      current=current->right;
    if(current->left!=NULL)
	current->left->right=current->right;
    else
	(*first)=NULL;

    item=current->data;
    freenode(current);
    printf("\n Deleted item is:%d",item);
    return;

  }


DDLA(node **first,int pos)
 { node *current,*prev;
   int i=1,item;
   if(*first==NULL)
    { printf("\n List is empty.");
      return;
     }
   current=(*first);
   while(current!=NULL)
    { if(i==pos)
      { item=current->data;
	if(current->left==NULL)
	  { current->right->left=NULL;
	    (*first)=current->right;
	    freenode(current);
	  }
	else if(current->right==NULL)
	 { current->left->right=current->right;
	   freenode(current);
      }
	else
	 { current->left->right=current->right;
	   current->right->left=current->left;
	   freenode(current);
	 }
	printf("\n Deleted item is:%d",item);
	return;
      }
     i++;
     current=current->right;
   }
  printf("\n No node found..");
  return;
 }





TDL(node *first)
 { if(first==NULL)
    { printf("\n List is empty..");
      return;
    }
   printf("\n Doubly linked list is..\n");
   printf("\n Start");
   do
    { printf("%d*",first->data);
      first=first->right;
    }while(first!=NULL);
   printf("END\n");
 return;
 }

node *getnode()
 { node *t;
   t=(node *)malloc(sizeof(node));
   return t;
 }
freenode(node *t)
 { free(t);
return 0;
 }