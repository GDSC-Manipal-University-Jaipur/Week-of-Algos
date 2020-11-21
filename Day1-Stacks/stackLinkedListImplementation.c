#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int val;
} node;

int isEmpty(node* top){
    if(top==NULL)
        return 1;
    return 0;
    
}

node* push(int val, node *top)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = top;
    newNode->val = val;
    return newNode;
}

int pop(node **top)
{   
    node* temp = *top;
    int val = temp->val;
    node *toDelete = temp;
    temp = temp->prev;
    *top = temp;
    free(toDelete);
    return val;
}

void display(node *top)
{
    node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->prev;
    }
}
void peek(node *top)
{
    printf("%d ", top->val);
    printf("\n");
}

int main()
{
    node *stack = NULL;
    int ch,val = 0;

    while (1)
    {
        printf("choose operation: \n 1.)push 2.)pop 3.) display 4.)peek 5.)is empty?\n press 6 to exit\n");
        scanf("%d", &ch);
        if(ch==1){
            printf("enter value \n ");
            scanf("%d",&val);
            stack = push(val,stack);
            printf("\n");
        }
        else if(ch==2){
            if(!isEmpty(stack)){
                val = pop(&stack);
                printf("popped val: %d \n",val);
            }
            else
                printf("can't pop an empty stack duh!\n ");
            printf("\n");
            
        }
        else if(ch==3){
             if(!isEmpty(stack)){
                display(stack);
                
            }
            else
                printf("can't display an empty stack duh!\n ");
            printf("\n");
        }
        else if(ch==4){
             if(!isEmpty(stack)){
                peek(stack);
                
            }
            else
                printf("can't peek an empty stack duh!\n ");
            printf("\n");
        }
        else if(ch==5){
            if(isEmpty(stack))
                printf("true\n ");
            else
                printf("false\n ");
            printf("\n");   
        }
        else if(ch==6){
             return 0;
            
        }
        else{
            printf("invalid choice!\n ");
            printf("\n");
        }
        printf("\n");
    }       
}