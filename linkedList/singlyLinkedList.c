#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}List;

List *head_node = NULL;


//function prototypes

int push_front(int data); // returns 1 if successfull, 0 if failed
int push_back(int data); // same return values for push_back, pop_front & pop_back

int pop_front(void);
int pop_back(void);

void display(void);


int main()
{
    int choice, data;
    printf("YOU ARE USING A SINGLY LINKED LIST PROGRAM");

    do{
        printf("\n\nEnter Your Choice:\n");
        printf("\n0: Exit\n1: Insert Data at the Front\n2: Insert Data at the Back\n3: Delete Data at the Front\n4: Delete Data at the Back\n5: Display All Values\n\nYou Entered: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0: return 0;
        case 1: printf("\nEnter an integer value to insert at the front: ");
                scanf("%d", &data);
                if (push_front(data))
                    printf("\n%d was inserted successfully at the front\n", data);
                else
                    printf("\nFAILED TO INSERT %d AT FRONT!\n", data);
                break;

        case 2: printf("\nEnter an integer value to insert at the back: ");
                scanf("%d", &data);
                if (push_back(data))
                    printf("\n%d was inserted successfully at the back\n", data);
                else
                    printf("\nFAILED TO INSERT %d AT BACK!\n", data);
                break;

        case 3: if (pop_front())
                    printf("\ndata was deleted successfully at the front\n");
                else
                    printf("\nTHE LINKED LIST IS EMPTY!\n");
                break;

        /*case 4: if (pop_back())
                    printf("\ndata was deleted successfully at the back\n");
                else
                    printf("\nTHE LINKED LIST IS EMPTY!\n");
                break;*/

        case 5: display();
                break;
        
        default: printf("\nINVALID CHOICE!\nTRY AGAIN\n");
                 break;
        }
    }while(choice!=0);
    
    return 0;
}

int push_front(int data)
{
    List *new_node = malloc(sizeof(List));
    if (new_node == NULL) // if malloc fails and returns NULL
        return 0;

    new_node->data = data;
    if (head_node == NULL) // if linked list is empty
        new_node->link = NULL;
    else
        new_node->link = head_node;
    head_node = new_node;
    return 1;
}

int push_back(int data)
{
    List *temp_node = head_node, *new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return 0;

    new_node->data = data;
    new_node->link = NULL;
    if (head_node == NULL)
        head_node = new_node;
    else
    {
        while (temp_node->link != NULL)
            temp_node = temp_node->link;
        temp_node->link = new_node;
    }
    return 1;
}

void display()
{
    List *current_node = head_node;
    if(head_node == NULL)
    {
        printf("\nTHE LINKED LIST IS EMPTY!\n");
        return;
    }

    while (current_node->link != NULL)
    {
        printf("\nData: %d", current_node->data);
        current_node = current_node->link;
    }
    printf("\nData: %d", current_node->data);
}