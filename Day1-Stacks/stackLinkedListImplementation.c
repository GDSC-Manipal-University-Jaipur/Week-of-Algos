#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    struct Node *prev;
    int val;
} node;

//function to check if the stack is empty 
int isEmpty(node* top){
    if(top==NULL)//if the top pointer is pointing at NULL it means the stack is empty
        return 1;
    return 0;
    
}

//function to insert a value into the stack 
node* push(int val, node *top)
{
    node *newNode = (node *)malloc(sizeof(node));//allocate memory for a node struct instance and assign it's address to newNode pointer
    newNode->prev = top;
    newNode->val = val;
    return newNode;
}
// function to remove the top most element from the stack 
int pop(node **top)//used pointer to a pointer since we need to update the value of pointer top 
{   
    node* temp = *top;
    int val = temp->val;
    node *toDelete = temp;
    temp = temp->prev;
    *top = temp;
    free(toDelete);//frees the previously allocated memory 
    return val;
}
//function that traverses the stack top to bottom and prints each elements value
void display(node *top)
{
    node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->prev;
    }
}
//function to get the top of stack without popping it
void peek(node *top)
{
    printf("%d ", top->val);
    printf("\n");
}
//driver code
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
