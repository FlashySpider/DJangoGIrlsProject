/*
    I have used a circular array (using modulous). 
    While initializing array we leave 1 space blank.
    Front always points to a blank.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


typedef struct queue{
    int * queueArray;
    int frontIndex;
    int rearIndex;
    int capacity; // -> Size of Array
    int numberOfElements; // -> Elements in Array (capacity-1) as 1 is left blank

}Queue;



//-------------Function Declarations---------------------------------

// Initializes the array
Queue * initializeQueue(int ofSize);

// Returns true if Queue is Empty
bool queue_isEmpty(Queue *q);

// Returns true is queue is Full
bool queue_isFull(Queue *q);

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

Queue * initializeQueue(int ofSize){
    
    if(ofSize <= 0){
        printf("nInvalid input. Queue cannot be initialized\n");
        return NULL;
    } 

    Queue *q = (Queue *)malloc(sizeof(Queue));
    
    if(q){
        q->rearIndex = 0;
        q->frontIndex = 0;
        q->capacity = ofSize + 1;
        q->numberOfElements = ofSize;
        q->queueArray = (int *)malloc( q->capacity * sizeof(int) );

        if(!q->queueArray){
            printf("\nQueue Initialization Unsuccessful . ERROR 2\n");
            return NULL;

        }
        else {
            printf("\nQueue of capacity %d Initialized\n", ofSize);
            return q;

        }
    } 
    else {
        printf("\nQueue Initialization Unsuccessful . ERROR 1\n");
        return NULL;
    }

}


bool queue_isEmpty(Queue *q){
    if(q->frontIndex == q->rearIndex){
        return true;
    } else {
        return false;
    }
}


bool queue_isFull(Queue *q){
    if( (q->rearIndex+1) % (q->capacity) == q->frontIndex ){
        return true;
    } else{
        return false;
    }
}


void enqueue(Queue *q, int data){
    if(queue_isFull(q)){
        printf("\nCannot ENQUEUE %d. Queue is FULL\n",data);
    
    }
    else{
        q->rearIndex = (q->rearIndex + 1) % (q->capacity);
        q->queueArray[q->rearIndex] = data;
        printf("\n Enqueued %d\n", data);
     }
}


int dequeue(Queue *q){
    if(queue_isEmpty(q)){
        printf("\nCannot DEQUEUE. Queue is EMPTY. Returning INT_MIN\n");
        return INT_MIN;
    }
    q->frontIndex = (q->frontIndex +1) % (q->capacity);
    return q->queueArray[q->frontIndex];
}


void displayQueue_FrontToRear(Queue *q){

    printf("\nQueue -> ");

    if( queue_isEmpty(q) ){
        printf("Queue is EMPTY\n");
    }
    else {
        int i;
        int tempFront = q->frontIndex;
        int tempRear = q->rearIndex;
        int tempCapacity = q->capacity;

        while(tempFront != tempRear ){
            tempFront = (tempFront + 1) % tempCapacity;
            printf("%d  ",q->queueArray[tempFront]);
        }
        
        // We can also use Following loop 

        // for (i = (tempFront+1) % tempCapacity; i != (tempRear+1) % tempCapacity; i = (i+1)%tempCapacity){
        //     printf("%d  ",q->queueArray[i]);
        // }

        printf("\n");
    }
}


int peekFront(Queue *q){
    if(queue_isEmpty(q)){
        printf("Queue is Empty. Returning INT_MIN\n");
        return INT_MIN;
    }
    else {
        int tempfront = (q->frontIndex + 1) % q->capacity;
        return q->queueArray[tempfront];
    }
}


int peekRear(Queue *q){
    if(queue_isEmpty(q)){
        printf("Queue is Empty. Returning INT_MIN\n");
        return INT_MIN;
    }
    else {
        return q->queueArray[q->rearIndex];
    }
}


//-------------Main Function---------------------------------
int main(){

    Queue * Q1;

    Q1 = initializeQueue(3);
    
    displayQueue_FrontToRear(Q1);

    enqueue(Q1,0);
    enqueue(Q1,1);
    enqueue(Q1,2);
    enqueue(Q1,3);

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