#include<stdio.h>

// SIZE here defines the maximum value our Stack will hold at a given time
#define SIZE 10

// stack is our array which we are going to use as our Stack
int stack[SIZE];
// current will store the position of last inserted item in the stack
int current = -1;

// push(int)
// Pushes (Adds) a value to the Stack
void push(int x) {
    // Here we check first if the last known value was inserted at index SIZE - 1
    // which would mean that the last position of stack is filled
    if (current == SIZE - 1) {
        // Overflow is the condition when one tries to add more values to an already full stack
        printf("Overflow!\n");
    }
    else {
        // If the Stack has space for more values, we move the index pointer forward and put our value
        current++;
        stack[current] = x;
        printf("Pushed : %d\n", x);
    }
}

// pop()
// Pops (Removes) a value from the Stack
void pop() {
    // Here we check if any values exist in the stack
    // If current is at -1 then it means either no values have been added yet or
    // all values were removed
    if (current == -1) {
        // Underflow is the condition when one tries to remove a value from an already empty stack
        printf("Underflow!\n");
    }
    else {
        // If the Stack has any value, we take out the last entered value and move the index pointer behind
        int v = stack[current];
        current--;
        printf("Popped : %d\n", v);
    }
}

// print_stack()
// Prints our stack in Last ... First order
void print_stack() {
    if (current == -1) {
        printf("Stack is Empty!\n");
    }
    else {
        printf("Stack :\n");
        int i;
        for (i = current; i > -1; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n\n");
    }
}

int main() {
    printf("Array Implementation of a Stack.\nNote that Maximum size of Stack is %d currently!\n", SIZE);
    while (1) {
        printf("\nEnter\n1. Print Stack\n2. Push value in Stack\n3. Pop value from Stack\nAny other number to exit...\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            print_stack();
        }
        else if (choice == 2) {
            int v;
            printf("Enter value to push : \n");
            scanf("%d", &v);
            push(v);
        }
        else if (choice == 3) {
            pop();
        }
    }
    return 0;
}