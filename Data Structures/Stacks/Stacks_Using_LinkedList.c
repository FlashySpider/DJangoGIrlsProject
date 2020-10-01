#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>


// Structure of Node
typedef struct node{
    int data;
    struct node * next;
} Node;

// Structure for Stack
// top is always head
typedef struct stack{
    struct node * top;
    int count;
} Stack;

// -------------------Function Declarations----------------------------------------------

// Initialize a Stack of size "ofSize"
Stack * initializeStack();

// Returns true if stack is Empty
bool stack_isEmpty(Stack * s);

// Returns true if stack is Full
// Dont need it in case of Linked List
bool stack_isFull(Stack * s);

// Push items to the top of Stack
void push(Stack * s, int data);

// Returns the top element of the Stack and decrease the top pointer 
// Returns INT_MIN if stack is EMPTY
int pop(Stack * s);

// Return the top element. Doesn't change top pointer
// Returns INT_MIN if stack is EMPTY
int peek(Stack * s);

// Print the stack from top to bottom
void displayStack_topToBottom(Stack * s);


// --------------Function Definitions--------------------------------------------------


Stack * initializeStack(){
    Stack * s = (Stack *)malloc(sizeof(Stack));

    if(s){
        s->top = NULL;
        s->count = 0;
        printf("\nStack Initialized\n");
        return s;

    } else {
        printf("\nStack Initialization Unsuccessful .\n");
        return NULL;
    }
}


bool stack_isEmpty(Stack * s){
    if(s->top == NULL){
        return true;
    } else {
        return false;
    }
}


bool stack_isFull(Stack * s){
    // We can Add any number of elements in stack as we are using linked list
    return false;
}


void push(Stack * s, int data){
    Node * newnode = (Node *)malloc(sizeof(Node));
    if(newnode){
        newnode->data = data;
        newnode->next = s->top;
        s->top = newnode;
        s->count += 1;
        printf("\nPUSHED %d\n", data);

    } else{
        printf("\nCannot PUSH %d . ERROR ENCOUNTERED\n", data);
    }
}


int pop(Stack * s){
    if(stack_isEmpty(s)){
        printf("\nCannot POP. Stack is EMPTY. Returning INT_MIN\n");
        return INT_MIN;

    } else{
        int dataToReturn;
        dataToReturn = s->top->data;

        Node * temp = s->top;
        s->top = s->top->next;
        s->count -= 1;
        free(temp);

        return dataToReturn;
    }    
}


int peek(Stack * s){
    if(stack_isEmpty(s)){
        printf("\nCannot PEEK. Stack is EMPTY. NO element Present. Returning INT_MIN\n");
        return INT_MIN;

    } else{
        return s->top->data;
    } 
}


void displayStack_topToBottom(Stack * s){
    printf("\nStack -> ");

    if(stack_isEmpty(s)){
        printf("Stack is EMPTY\n");

    } else {
        Node * temp = s->top;
        while(temp){
            printf("%d  ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}



// -----------------------------------main()-------------------------------------------
int main(){
    Stack * S1;

    S1 = initializeStack();

    push(S1,0);
    push(S1,1);
    push(S1,2);
    printf("Peek top = %d\n",peek(S1));

    displayStack_topToBottom(S1);

    printf("\n Popped %d\n", pop(S1));
    displayStack_topToBottom(S1);

    printf("\n Popped %d\n", pop(S1));
    displayStack_topToBottom(S1);

    printf("\n Popped %d\n", pop(S1));
    displayStack_topToBottom(S1);

    printf("\n Popped %d\n", pop(S1));
    displayStack_topToBottom(S1);
    printf("Peek top = %d\n",peek(S1));

    return 0;
}