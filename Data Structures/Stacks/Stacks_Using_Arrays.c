#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// Structure for Stack
typedef struct stack{
    int * stackArray;
    int top;
    int capacity;
} Stack;

// -------------------Function Declarations----------------------------------------------

// Initialize a Stack of size "ofSize"
Stack * initializeStack(int ofSize);

// Returns true if stack is Empty
bool stack_isEmpty(Stack * s);

// Returns true if stack is Full
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

Stack * initializeStack(int ofSize){
    
    if(ofSize <= 0){
        printf("\nInvalid input. Stack cannot be initialized\n");
        return NULL;
    }

    Stack * s = (Stack *)malloc(sizeof(Stack));

    if(s){
        s->top = -1;
        s->capacity = ofSize;    
        s->stackArray = (int *)calloc(s->capacity, sizeof(int));

        if(!s->stackArray){
            printf("\nStack Initialization Unsuccessful . ERROR 2\n");
            return NULL;
        }
        printf("\nStack of capacity %d Initialized\n", ofSize);
        return s;

    } else{
        printf("\nStack Initialization Unsuccessful . ERROR 1\n");
        return NULL;
    }
}


bool stack_isEmpty(Stack * s){
    if (s->top == -1){
        return true;
    } else {
        return false;
    }
}


bool stack_isFull(Stack * s){
    if( s->top == s->capacity-1 ){
        return true;
    } else {
        return false;
    }
}


void push(Stack * s, int data){
    if(stack_isFull(s)){
        printf("\nCannot PUSH %d. Stack is FULL\n",data);

    } else{
        s->top += 1;
        s->stackArray[s->top] = data;
        printf("\n Pushed %d\n", data);
    }
}


int pop(Stack * s){
    int dataToReturn;

    if(stack_isEmpty(s)){
        printf("\nCannot POP. Stack is EMPTY. Returning INT_MIN\n");
        return INT_MIN;

    } else{
        dataToReturn = s->stackArray[s->top];
        s->top -= 1;
        return dataToReturn;
    }
}


int peek(Stack * s){
    if(stack_isEmpty(s)){
        printf("\nCannot PEEK. Stack is EMPTY. NO element Present. Returning INT_MIN\n");
        return INT_MIN;

    } else{
        return s->stackArray[s->top];
    }
}


void displayStack_topToBottom(Stack * s){
    
    printf("\nStack -> ");

    if(stack_isEmpty(s)){
        printf("Stack is EMPTY\n");

    } else {
        int i;
        
        for(i=s->top; i >= 0; i--){
            printf("%d  ",s->stackArray[i]);
        }

        printf("\n");
    }
}


// -----------------------------------main()-------------------------------------------
int main(){
    Stack * S1;

    S1 = initializeStack(3);

    push(S1,0);
    push(S1,1);
    push(S1,2);
    push(S1,3);
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