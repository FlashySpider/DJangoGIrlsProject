/*
    I have used a Singly Linked List.
    That's why I am using 2 pointers in Queue -> rear and front
    HEAD of Linked List is FRONT.
*/

/*
    I have not used a circular Linked List. 
    By using circular Linked List,
    we can maintain only one pointer to rear and insert and delete in O(1) time
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct queue{
    Node * frontNode; // -> It is the HEAD of Linked List
    Node * rearNode;
}Queue;



//-------------Function Declarations---------------------------------

// Initializes the array
Queue * initializeQueue();

// Returns true if Queue is Empty
bool queue_isEmpty(Queue *q);

// Dont't need it while using Linked List
// // Returns true is queue is Full
// bool queue_isFull(Queue *q);

// Inserts elements in the Queue (Front)
void enqueue(Queue *q, int data);

// Removes element from the Queue (Rear)
int dequeue(Queue *q);

// Prints Queue from Front to Rear
void displayQueue_FrontToRear(Queue *q);

// Returns Front element of Queue
int peekFront(Queue *q);

// Returns Rear element of Queue
int peekRear(Queue *q);

//-------------Function Definitions---------------------------------

Queue * initializeQueue(){
    
    Queue *q = (Queue *)malloc(sizeof(Queue));
    
    if(q){
        q->frontNode = NULL;
        q->rearNode = NULL;
        
        printf("\nQueue Initialized \n");
        return q;      
    } 
    else {
        printf("\nQueue Initialization Unsuccessful . ERROR 1\n");
        return NULL;
    }

}


bool queue_isEmpty(Queue *q){
    if(q->frontNode == NULL){
        return true;
    } else {
        return false;
    }
}


void enqueue(Queue *q, int data){
    
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if(!newnode){
        printf("\nCannot ENQUEUE %d. ERROR OCCURED\n",data);
        return;
    }

    if(queue_isEmpty(q)){
        q->frontNode = newnode;
        q->rearNode = newnode;

    } else {
        Node * temp = q->frontNode;

        while(temp != q->rearNode){
            temp = temp->next;
        }

        temp->next = newnode;
        q->rearNode = newnode;
    }

    printf("\n Enqueued %d\n", data);

}


int dequeue(Queue *q){
    if(queue_isEmpty(q)){
        printf("\nCannot DEQUEUE. Queue is EMPTY. Returning INT_MIN\n");
        return INT_MIN;
    }

    int returnData = q->frontNode->data;
    Node * temp = q->frontNode;

    q->frontNode = q->frontNode->next;
    free(temp);

    return returnData;
}


void displayQueue_FrontToRear(Queue *q){

    printf("\nQueue -> ");

    if( queue_isEmpty(q) ){
        printf("Queue is EMPTY\n");
    }
    else {
        Node * tempHead = q->frontNode;
        while(tempHead != q->rearNode){
            printf("%d  ", tempHead->data);
            tempHead = tempHead->next;
        }
        printf("\n");
    }
}


int peekFront(Queue *q){
    if(queue_isEmpty(q)){
        printf("Queue is Empty. Returning INT_MIN\n");
        return INT_MIN;
    }
    else {
        return q->frontNode->data;
    }
}


int peekRear(Queue *q){
    if(queue_isEmpty(q)){
        printf("Queue is Empty. Returning INT_MIN\n");
        return INT_MIN;
    }
    else {
        Node * temp = q->frontNode;
        while(temp != q->rearNode){
            temp = temp->next;
        }
        return temp->data;
    }
}


//-------------Main Function---------------------------------
int main(){

    Queue * Q1;

    Q1 = initializeQueue();
    
    displayQueue_FrontToRear(Q1);

    enqueue(Q1,0);
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));
    enqueue(Q1,1);
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));
    enqueue(Q1,2);
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));
    enqueue(Q1,3);
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));

    displayQueue_FrontToRear(Q1);

    printf("\n DEQUEUED %d\n", dequeue(Q1));
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));
    displayQueue_FrontToRear(Q1);

    printf("\n DEQUEUED %d\n", dequeue(Q1));
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));
    displayQueue_FrontToRear(Q1);

    printf("\n DEQUEUED %d\n", dequeue(Q1));
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));
    displayQueue_FrontToRear(Q1);

    printf("\n DEQUEUED %d\n", dequeue(Q1));
    printf("Front -> %d  Rear = %d \n", peekFront(Q1), peekRear(Q1));
    displayQueue_FrontToRear(Q1);


    return 0;
}