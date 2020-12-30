#include "all.h"

void erase(struct node *ll, int a)
{   int result=0;
    result=delete(ll,a);
    if(result==0)
    {       printf("NODE NOT FOUND\n");
        return;
    }
    if(result==1)
    {       printf("SUCCESS\n");
        return;
    }
}

int delete(struct node *ll, int a)
{   int result=0, previous_index=0, next_index=0, flag=1, temp=0;
    int i=0, indexnumber=0;
    result=search(ll,a); // search if in list
    if(result==0)   //if not in list
        return 0;
    if(result==1)// if in list
    {       for (i=0; i<100; i++)
        {       if (ll[i].data==a && ll[i].valid==1)//find indexnumber
            {       indexnumber=i;  }       }
        release_node(ll,indexnumber);//change .valid to 0
        next_index=ll[previous_index].next;//get the first .next
        while(flag==1)//loop
        {       if(ll[next_index].data==a)//if found number in the list
            {       ll[previous_index].next=ll[next_index].next;//change .next value
                return 1;
            }
            previous_index=next_index;
            next_index=ll[next_index].next; //get next .next indicator
        }
    }
}

void print(struct node *ll)
{   int i=0, next=0, flag=1;
    if(ll[i].next==MYNULL) printf("\n");// if nothing is in the list
    else
    {       i=ll[i].next; // get the .next from sentinel node
        while(flag==1)//loop
        {       if(ll[i].next==MYNULL)
            {       flag=0;
            }
            next=ll[i].next;
            if(ll[i].valid!=0)
            {       printf("%d ",ll[i].data);       }
            i=next;
        }
        printf("\n");
    }
}

void insert (struct node *ll, int a)
{   int result=0;
    result=add(ll,a);
    if (result==1)
    {       printf("SUCCESS\n");
        return;
    }
    if (result==0)
    {       printf("NODE ALREADY IN LIST\n");
        return;
    }
    if (result==MYNULL)
    {       printf("NO SPACE AVAILABLE\n");
        return;
    }
}

int add (struct node *ll, int a)
{   int previous_index=0, next_index=0, emptynode=0;
    int flag=1;
    if(ll[0].next==MYNULL)  //if user enter the first number
    {       ll[1].data=a;
        ll[1].next=MYNULL;
        ll[1].valid=1;
        ll[0].next=1;
        return 1;//success
    }
    if(search(ll,a)==1)
    {       return 0;       }//if already in the list
    emptynode=get_node(ll);
    if(emptynode==MYNULL)
    {       return MYNULL;  }//if there is no more space
    if(emptynode!=MYNULL)
    {       ll[emptynode].data=a;
        next_index=ll[previous_index].next;
        while (flag==1)
        {       if(ll[next_index].next==MYNULL)//when next node is pointing to MYNULL
            {       if(ll[next_index].data<a)
                {       ll[emptynode].next=MYNULL;
                    ll[next_index].next=emptynode;
                    return 1;//success
                }
                if(ll[next_index].data>a)
                {       ll[previous_index].next=emptynode;
                    ll[emptynode].next=next_index;
                    ll[next_index].next=MYNULL;
                    return 1;//success
                }
            }
            if(ll[next_index].next!=MYNULL)//when next node is not pointing to MYNULL
            {       if(ll[next_index].data>a)
                {       ll[previous_index].next=emptynode;
                    ll[emptynode].next=next_index;
                    return 1;//if success
                }
                previous_index=next_index;
                next_index=ll[next_index].next;
            }
        }
    }
}


int search(struct node *ll, int a)
{   for (int i=1; i<100; i++)
    {       if(ll[i].data==a && ll[i].valid==1)
        {return 1;} // found
    }
    return 0; //not found
}

void release_node(struct node *ll, int a)
{       ll[a].valid=0;  }

int get_node(struct node *ll)
{   int i=1;
    for (i=1; i<100; i++)
    {       if(ll[i].valid==0)
        {       ll[i].valid=1;
            return i;
        }
    }
    return MYNULL;
}

void prompt(int a)
{   printf("\n-----PLEASE ENTER ONE OF THE FOLLOWING COMMANDS:-----\n");
    printf("i NUMBER--------to insert NUMBER into the list\n");
    printf("p---------------to print the list in order\n");
    printf("s NUMBER--------to search for NUMBER in the list\n");
    printf("d NUMBER--------to delete NUMBER from the list\n");
    printf("v---------------to view the list in TABLE-FORM (first 10)\n");
    printf("x---------------to exit the program\n");
}

void init (struct node *list)
{   int i=1;
    list[0].valid=1;
    list[0].data=49;
    list[0].next=MYNULL;
    for(i=1; i<100; i++)
    {       list[i].valid=0;        }
}

void view(struct node *ll)
{       int i=0;
    printf( "[i]    ll[i].data     ll[i].next      ll[i].valid\n");
    for (i=0; i<10; i++)
    {       printf( " %d %10d %15d %15d\n", i, ll[i].data, ll[i].next, ll[i].valid); }
}