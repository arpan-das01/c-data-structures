#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int push(int data);
int pop(void);
void display(void);

int is_empty(void);
int is_full(void);

int stack[MAX], top = -1;
// just copied some code from singlyLinkedList

int main()
{
    int choice, data;
    printf("YOU ARE USING A STACK IMPLEMENTED USING ARRAY PROGRAM");

    do{
        printf("\n\nEnter Your Choice:\n");
        printf("\n0: Exit\n1: Push Data\n2: Pop Data\n3: Display All Values\n\nYou Entered: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0: return 0;
        case 1: printf("\nEnter an integer value to push: ");
                scanf("%d", &data);
                if (push(data))
                    printf("\n%d was pushed successfully\n", data);
                else
                    printf("\nFAILED TO PUSH %d!\n", data);
                break;

        case 2: if (pop())
                    printf("\ndata was popped successfully\n");
                else
                    printf("\nTHE STACK IS EMPTY!\n");
                break;

        case 3: display();
                break;
        
        default: printf("\nINVALID CHOICE!\nTRY AGAIN\n");
                 break;
        }
    }while(choice!=0);
    
    return 0;
}

int is_empty(void)
{
    if (top == -1)
        return 1;
    else
        return 0;
}
