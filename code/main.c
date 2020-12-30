#include "all.h"

int main ()
{   struct node list[100];
    int run=0, number=0, flag=1, returnvalue=0;
    char str[100],command;

    printf("\n--------------Welcome to LinkedList program--------------\n");
    init(list); //initilaize the list
    while(flag==1)//loop
    {       printf (">");
        fgets(str, 100, stdin);// get input
        returnvalue=sscanf(str,"%c%d", &command, &number);
        if(returnvalue!=2)
        {       if(command=='x')
            {       flag=0;
                return 0;
            }
            else if(command=='p')
            {       print(list);
            }
            else if(command=='v')
            {       view(list);
            }
            else {prompt(1);}
        }
        if(returnvalue==2)
        {
            switch(command){
                case'i': insert(list,number);break;
                case'p': print(list);break;
                case's': run=search(list,number);break;
                case'd': erase(list,number);break;
                case'x': flag=0;break;
                case'v': view(list);break;
                default: prompt(1);
            }
            if (command=='s' && run==1) printf("FOUND\n");//if search is success
            if (command=='s' && run==0) printf ("NOT FOUND\n");//if search is not success
        }
    }
    return 0;
}