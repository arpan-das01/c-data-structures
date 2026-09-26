#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init_stack(Stack *new);

int push(Stack *stack1, int data);
int pop(Stack *stack1);
//void display(Stack *stack1);

int is_empty(Stack *stack1);
int is_full(Stack *stack1);

// just copied some code from singlyLinkedList

int main()
{
    Stack *stack1;
    init_stack(stack1);

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
                if (push(stack1, data))
                    printf("\n%d was pushed successfully\n", data);
                else
                    printf("\nFAILED TO PUSH %d!\n", data);
                break;

        case 2: if (pop(stack1))
                    printf("\ndata was popped successfully\n");
                else
                    printf("\nTHE STACK IS EMPTY!\n");
                break;

        /*case 3: display(stack1);
                break;*/
        
        default: printf("\nINVALID CHOICE!\nTRY AGAIN\n");
                 break;
        }
    }while(choice!=0);
    
    return 0;
}

void init_stack(Stack *new)
{
    new->top = -1;
}

int is_empty(Stack *stack1)
{
    if (stack1->top == -1)
        return 1;
    else
        return 0;
}

int is_full(Stack *stack1)
{
    if (stack1->top == MAX - 1)
        return 1;
    else
        return 0;
}

int push(Stack *stack1, int data)
{
    if(is_full(stack1))
        return 0;
    else
    {
        ++stack1->top;
        stack1->data[stack1->top] = data;
        return 1;
    }
}

int pop(Stack *stack1)
{
    if(is_empty(stack1))
        return 0;
    else
    {
        --stack1->top;
        return 1;
    }
}