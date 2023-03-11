#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodelinkedlistA{
   int number;
   struct nodelinkedlistA *next;
} nodeA;

typedef struct nodelinkedlistB{
   int number;
   struct nodelinkedlistB *next;
} nodeB;

typedef struct nodelinkedlistC{
   int number;
   struct nodelinkedlistC *next;
} nodeC;

//Function Set A
nodeA *insidenodeSETA(int);
nodeA *searhnameSETA(nodeA*,int);
void insertnodeSETA(nodeA*);
void printnodeSETA(nodeA*);
void printlistSETA(nodeA*);
void deletenodeSETA(nodeA*);

nodeA *headA = NULL;
nodeA *endA = NULL;

//Function Set B
nodeB *insidenodeSETB(int);
nodeB *searhnameSETB(nodeB*,int);
void insertnodeSETB(nodeB*);
void printnodeSETB(nodeB*);
void printlistSETB(nodeB*);
void deletenodeSETB(nodeB*);

nodeB *headB = NULL;
nodeB *endB = NULL;

//Fuction Set C
nodeC *insidenodeSETC(int);
void insertnodeSETC(nodeC*);
void updateSETC(nodeA*,nodeB*,nodeC*);
void printnodeSETC(nodeC*);
void printlistSETC(nodeC*);
void deletenodeSETC(nodeC*);

nodeC *headC = NULL;
nodeC *endC = NULL;

//Function Set A
nodeA *insidenodeSETA(int number){
    nodeA *ptr;
    ptr = new nodeA;
    ptr->number = number;
    ptr->next = NULL;
    return(ptr);
}

void printnodeSETA(nodeA *ptr){
   printf("\t%d\n",ptr->number);
}

void printlistSETA(nodeA *ptr){
    printf("\tNumber Set A\n");
    while(ptr != NULL){
        printnodeSETA(ptr);
        ptr = ptr->next; }
}

nodeA* searhnameSETA(nodeA *ptr, int number){
    if(headA == NULL) return(NULL);
    while(ptr->number!=number){
        ptr = ptr->next;
        if(ptr == NULL) break;
    }
    return(ptr);
}

void deletenodeSETA(nodeA *ptr){
   nodeA *start, *prev;
   start = ptr;
   prev = headA;

   if(start == prev){
      headA = headA->next;
      if(endA == start){
         endA = endA->next;
      }
      delete(start);
   }else{
      while(prev->next != start){
         prev = prev->next;
      }
      prev->next = start->next;
      if(endA == start){
         endA = prev;
      }
      delete(start);
   }

}

void insertnodeSETA(nodeA *newptr){
    nodeA *start, *prev;
    if(headA == NULL){
        headA = newptr;
        endA = newptr;
        return;
    }
    start = headA;
    while(newptr->number>start->number){
        start = start->next;
        if(start == NULL) break;
    }
    if(start == headA){
        newptr->next = headA;
        headA = newptr;
    }else{
        prev = headA;
        while(prev->next!= start){
                prev = prev->next;
        }
        prev->next = newptr;
        newptr->next = start;
        if(endA == prev){
            endA = newptr;
        }
    }
}

//Function Set B
nodeB *insidenodeSETB(int number){
    nodeB *ptr;
    ptr = new nodeB;
    ptr->number = number;
    ptr->next = NULL;
    return(ptr);
}

void printnodeSETB(nodeB *ptr){
   printf("\t%d\n",ptr->number);
}

void printlistSETB(nodeB *ptr){
    printf("\tNumber Set B\n");
    while(ptr != NULL){
        printnodeSETB(ptr);
        ptr = ptr->next; }
}

nodeB* searhnameSETB(nodeB *ptr, int number){
    if(headB == NULL) return(NULL);
    while(ptr->number!=number){
        ptr = ptr->next;
        if(ptr == NULL) break;
    }
    return(ptr);
}

void deletenodeSETB(nodeB *ptr){
   nodeB *start, *prev;
   start = ptr;
   prev = headB;

   if(start == prev){
      headB = headB->next;
      if(endB == start){
         endB = endB->next;
      }
      delete(start);
   }else{
      while(prev->next != start){
         prev = prev->next;
      }
      prev->next = start->next;
      if(endB == start){
         endB = prev;
      }
      delete(start);
   }

}

void insertnodeSETB(nodeB *newptr){
    nodeB *start, *prev;
    if(headB == NULL){
        headB = newptr;
        endB = newptr;
        return;
    }
    start = headB;
    while(newptr->number>start->number){
        start = start->next;
        if(start == NULL) break;
    }
    if(start == headB){
        newptr->next = headB;
        headB = newptr;
    }else{
        prev = headB;
        while(prev->next!= start){
                prev = prev->next;
        }
        prev->next = newptr;
        newptr->next = start;
        if(endB == prev){
            endB = newptr;
        }
    }
}


//Function Set C
nodeC *insidenodeSETC(int number){
    nodeC *ptr;
    ptr = new nodeC;
    ptr->number = number;
    ptr->next = NULL;
    return(ptr);
}

void insertnodeSETC(nodeC *newptr){
    nodeC *start, *prev;
    if(headC == NULL){
        headC = newptr;
        endC = newptr;
        return;
    }

    if(start == headC){
        newptr->next = headC;
        headC = newptr;
    }else{
        prev = headC;
        while(prev->next!= start){
                prev = prev->next;
        }
        prev->next = newptr;
        newptr->next = start;
        if(endC == prev){
            endC = newptr;
        }
    }
}

void updateSETC(nodeA *ptrA ,nodeB *ptrB, nodeC *ptrC){
    int numberA, numberB, Sum;
    while(ptrA && ptrB != NULL){
    if(ptrA != NULL){
        numberA = ptrA->number;
    }
    if(ptrB != NULL){
        numberB = ptrB->number;
    }
    if(ptrA && ptrB != NULL){
        Sum = numberA*numberB;
        ptrC = insidenodeSETC(Sum);
        insertnodeSETC(ptrC);

        printf("\t%d",ptrA->number); 
        printf("\t x "); 
        printf("\t%d",ptrB->number);
        printf("\t=\t%d\n",ptrC->number);
    }
    ptrA=ptrA->next;
    ptrB=ptrB->next;
    ptrC=ptrC->next;
    }
}

void printnodeSETC(nodeC *ptr){
    printf("\t%d\n",ptr->number);
}

void printlistSETC(nodeC *ptr){
    printf("\tNumber Set C\n");
    while(ptr != NULL){
        printnodeSETC(ptr);
        ptr = ptr->next; }
}

void deletenodeSETC(nodeC *ptr){
   nodeC *start, *prev;
   start = ptr;
   prev = headC;

   if(start == prev){
      headC = headC->next;
      if(endC == start){
         endC = endC->next;
      }
      delete(start);
   }else{
      while(prev->next != start){
         prev = prev->next;
      }
      prev->next = start->next;
      if(endC == start){
         endC = prev;
      }
      delete(start);
   }
}

int main(){
   int numberA, numberB;
   int maintop=1, main=1;
   nodeA *ptrA;
   nodeB *ptrB;
   nodeC *ptrC;

    while(maintop!=0){
    system("cls");
    printf("\tProgram collect Data Set A & Set B\n\n");
    printf("\tprovided that\n");
    printf("\t- Must be the set of positive integers.\n");
    printf("\t- Can add unlimited data.\n");
    printf("\t- There is an order of information.\n");
    printf("\t- There is information that each person is unique.\n");
    printf("\t- Create a data structure to collect data.\n");
    printf("\t- Members have no need to press\n");
    printf("\t- C=A*B\n\n");

    printf("\t1. Data Set A\n");
    printf("\t2. Data Set B\n");
    printf("\t3. Data Set C\n");
    printf("\t0. Quit\n\n");
    printf("\tPlease Select your Set to continue... ");
    scanf("%d",&maintop);
    main=1;
    while(main!=0){
            switch(maintop){
            case 1 :
                system("cls");
                printf("\tData SET A\n\n");
                printf("\t1. Add Number \n");
                printf("\t2. Delete Number \n");
                printf("\t3. Printlist all Number \n");
                printf("\t4. Search Number \n");
                printf("\t0. Quit\n\n");
                printf("\tPlease Select function number...");
                scanf("%d",&main);
                        switch(main){
                            case 1 :
                                system("cls");
                                printf("\tEnter Your Number : ");
                                scanf("%d",&numberA);
                                ptrA = searhnameSETA(headA,numberA);
                                if(ptrA == NULL){
                                ptrA = insidenodeSETA(numberA);
                                    if(numberA>0){
                                        if(headA == NULL){
                                                insertnodeSETA(ptrA);
                                                printf("\n\t[%d] ",ptrA->number);
                                                printf("Add Data in Set A succeed \n");
                                                printf("\tPlease any key to continue...");
                                                getch();
                                        }else if(headA != NULL){
                                                insertnodeSETA(ptrA);
                                                printf("\n\t[%d] ",ptrA->number);
                                                printf("Add Data in Set A succeed \n");
                                                printf("\tPlease any key to continue...");
                                                getch();
                                        }
                                    }else{
                                        printf("\n\tCan't add number becuase Data less or equal than 0\n");
                                        printf("\tPlease any key to continue...");
                                        getch();
                                    }
                                }else if (numberA == ptrA->number){
                                    printf("\n\tCan't add number becuase Data duplicate\n");
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }
                                break;

                            case 2 :
                                system("cls");
                                printf("\tEnter number for delete : ");
                                scanf("%d",&numberA);
                                printf("\n");
                                ptrA = searhnameSETA(headA,numberA);
                                if(ptrA == NULL){
                                    printf("\t[%d] not found in Set A\n",numberA);
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }else if (numberA == ptrA->number){
                                    deletenodeSETA(ptrA);
                                    printf("\tData deleted...\n");
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }
                                break;

                            case 3 :
                                system("cls");
                                printlistSETA(headA);
                                printf("\t\nPlease any key to continue...");
                                getch();
                                break;

                            case 4 :
                                system("cls");
                                printf("\tEnter number for search : ");
                                scanf("%d",&numberA);
                                printf("\n");
                                ptrA = searhnameSETA(headA,numberA);
                                if(ptrA == NULL){
                                    printf("\t[%d] not found in Set A\n",numberA);
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }else{
                                    printf("\t[%d] Data is found in Set A\n",numberA);
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }
                                break;

                            }break;
            case 2 :
                system("cls");
                printf("\tData SET B\n\n");
                printf("\t1. Add Number \n");
                printf("\t2. Delete Number \n");
                printf("\t3. Printlist all Number \n");
                printf("\t4. Search Number \n");
                printf("\t0. Quit\n\n");
                printf("\tPlease Select function number...");
                scanf("%d",&main);

                        switch(main){
                            case 1 :
                                system("cls");
                                printf("\tEnter Your Number : ");
                                scanf("%d",&numberB);
                                ptrB = searhnameSETB(headB,numberB);
                                if(ptrB == NULL){
                                ptrB = insidenodeSETB(numberB);
                                    if(numberB>0){
                                        if(headB == NULL){
                                                insertnodeSETB(ptrB);
                                                printf("\n\t[%d] ",ptrB->number);
                                                printf("Add Data in Set B succeed \n");
                                                printf("\tPlease any key to continue...");
                                                getch();
                                        }else if(headB != NULL){
                                                insertnodeSETB(ptrB);
                                                printf("\n\t[%d] ",ptrB->number);
                                                printf("Add Data in Set B succeed \n");
                                                printf("\tPlease any key to continue...");
                                                getch();
                                        }
                                    }else{
                                        printf("\n\tCan't add number becuase Data less or equal than 0\n");
                                        printf("\tPlease any key to continue...");
                                        getch();
                                    }
                                }else if (numberB == ptrB->number){
                                    printf("\n\tCan't add number becuase Data duplicate\n");
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }
                                break;

                            case 2 :
                                system("cls");
                                printf("\tEnter number for delete : ");
                                scanf("%d",&numberB);
                                printf("\n");
                                ptrB = searhnameSETB(headB,numberB);
                                if(ptrB == NULL){
                                    printf("\t[%d] not found in Set B\n",numberB);
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }else{
                                    deletenodeSETB(ptrB);
                                    printf("\tData deleted...\n");
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }
                                break;

                            case 3 :
                                system("cls");
                                printlistSETB(headB);
                                printf("\t\nPlease any key to continue...");
                                getch();
                                break;

                            case 4 :
                                system("cls");
                                printf("\tEnter number for search : ");
                                scanf("%d",&numberB);
                                printf("\n");
                                ptrB = searhnameSETB(headB,numberB);
                                if(ptrB == NULL){
                                    printf("\t[%d] not found in Set B\n",numberB);
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }else{
                                    printf("\t[%d] Data is found in Set B\n",numberB);
                                    printf("\tPlease any key to continue...");
                                    getch();
                                }
                                break;
                            }break;
            case 3 :
                system("cls");
                printf("\tData SET C\n\n");
                printf("\t1. Update Set C\n");
                printf("\t2. Printlist all Number \n");
                printf("\t0. Quit\n\n");
                printf("\tPlease Select function number...");
                scanf("%d",&main);
                        switch(main){

                            case 1 :
                                system("cls");
                                while (headC != NULL)
                                {   
                                    deletenodeSETC(headC);
                                }
                                updateSETC(headA,headB,headC);
                                printf("\tUpdate Data Set C succeed");
                                printf("\n");
                                printf("\tPlease any key to continue...");
                                getch();
                                break;

                            case 2 :
                                system("cls");
                                printlistSETC(headC);
                                printf("\t\nPlease any key to continue...");
                                getch();
                                break;
                            }break;
                }
            }
    }
}