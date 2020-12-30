//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name: Vuochlang Chang                                                                                                            //
// Class: CSE222        Winter-2020     2419                                                                                        //
// Date: 01/16/2020                                                                                                                 //
// Assignment: PA1                                                                                                                  //
// This code will allow user to configuring a given link list by adding, deleting, printing and searching for a certain number.     //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#define MYNULL -1

struct node {   int data;
    int next;
    int valid;
};

void prompt(int);  //print instruction
void init (struct node *); //initialise the list
void view(struct node *); // view linkedlist in a TABLE-VIEW
int get_node(struct node *);    //get first node with empty list
void release_node (struct node *, int); // change valid value to 0
void insert(struct node *, int); //insert number
int search(struct node *, int);  // search number
int add(struct node *, int); //add and organize the list
void print(struct node *); // print number
int delete(struct node *, int);
void erase(struct node *, int);