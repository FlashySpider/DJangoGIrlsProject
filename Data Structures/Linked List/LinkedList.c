/*
 TO DO: Find the time and space COmplexities of every function 
*/

/*
    ISSUES:

    1 - free() is giving segmentation fault:11  or Abort:6 (Don't know why)

    2 - delete from beginning is not changing the head pointer of linked list we have to specifically five the 
        head pointer to delete the node from beginning

    Solutions:
    1 - It solved automatically (Don't know why?). It is not giving an error now
    2 - We have to do it as we  have to change the head everytime
*/



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Structure of a Node
typedef struct node{
    int data;
    struct node * next;
} Node;

 // Structure of Linked List
typedef struct linkedlist{
    struct node * head;
    int count;
} LinkedList;

// Linked List Functions Declatation
struct node * makeDemoLL(); 

void print_LL_Iteratively(Node * node);
void print_LL_Recursively(Node * node);
void print_LL_Reverse_Iteratively(Node * node, int numOfNodes);
void print_LL_Reverse_Recursively(Node * node);

void insert_LL_beginning(LinkedList * ll, int data);
void insert_LL_end(LinkedList * ll, int data);
void insert_LL_atPostion(LinkedList * ll, int data, int atPosition); // THIS IS MESSY IMPROVE IT https://www.geeksforgeeks.org/insert-a-node-at-a-specific-position-in-a-linked-list/
void insert_LL_afterData(LinkedList * ll, int data, int afterData);

void delete_LL_beginning(LinkedList * ll);
void delete_LL_end(LinkedList * ll);
void delete_LL_atPosition(LinkedList * ll, int atPosition);
void delete_LL_afterData(LinkedList * ll, int afterData); // -> Nice Approach

void reverse_LL_Iteratively(LinkedList * ll);
void reverse_LL_Recursively(LinkedList * ll, Node * p, Node * q);
void reverse_LL_Recursively_Ver2(LinkedList * ll, Node * head); // -> This is a nice approach (I like it)
// -> same as ver 2 but returns head 
// - > take a look to learn how to return the same var always
Node * reverse_LL_Recursively_Ver3( Node * head); 

//-------------------------------------------------------------------------------------------//

// Print Linked List Iteratively
void print_LL_Iteratively(Node * node){
    if(!node){
        printf("Cannot print Linked List. Linked List is EMPTY");
    }
    while(node){
        printf("%d  ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

// Print Linked List Recursively
void print_LL_Recursively(Node * node){
    if(!node){
        printf("\n");
        return;
    }
    printf("%d  ", node->data);
    return print_LL_Recursively(node->next);
}

// Print Reverse of Linked List Iteratively
void print_LL_Reverse_Iteratively(Node * node, int numOfNodes){
    int arr[numOfNodes];
    int i = numOfNodes-1;
    while(node){
        arr[i--] = node->data;
        node = node->next;
    }

    for(i=0; i < numOfNodes; i++){
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// Print Reverse of Linked List Recursively
void print_LL_Reverse_Recursively(Node * node){
    if(!node){
        printf("\n");
        return;
    }
    print_LL_Reverse_Recursively(node->next);
    printf("%d  ", node -> data);
}
       
// Insertion at beginning of the linked list
void insert_LL_beginning(LinkedList * ll, int data){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = ll->head;
    ll->head = newnode;
    ll->count += 1;
}

// Insertion at end
void insert_LL_end(LinkedList * ll, int data){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    Node * temp = ll->head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = newnode;
    ll->count += 1;
}

// Insertion at a particulat position
// THIS IS MESSY IMPROVE IT
void insert_LL_atPostion(LinkedList * ll, int data, int atPosition){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    int currentPos = 1;
    Node * temp = ll->head;

    if(atPosition > ll->count+1  ||  atPosition < 1){
        printf("Cannot insert at %d positon - Position is out of bounds\n",atPosition);
        return;
    }
   
    if(atPosition == 1){
        // If position is beginning 
        newnode->next = temp;
        ll->head = newnode;
    }
    else{
        // Every other position
        while(currentPos != atPosition-1){ 
            temp = temp->next;
            currentPos += 1;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
    ll->count += 1;
}

// Insertion after a data item
void insert_LL_afterData(LinkedList * ll, int data, int afterData){
    Node * newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    bool dataFound = false;
    Node * temp = ll->head;

    while(temp->next){
        if(temp->data == afterData){
            dataFound = true;
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        } 
        temp = temp->next;
    }
    if(dataFound == false){
        printf("The data %d is not present in the linked list - Cannot Perform Insertion \n", afterData);
    }


}

// Delete node from beginning
void delete_LL_beginning(LinkedList * ll){
    Node * cur = ll->head;
    Node * temp;
    if(cur == NULL){
        printf("Cannot perform deletion as Linked List is Empty\n");

    } else{
        temp = cur;
        cur = cur->next;
        free(temp);
        ll->count -= 1;
        ll->head = cur;
    }
}

// Delete node at end
void delete_LL_end(LinkedList * ll){

    Node * cur = ll->head;
    Node * temp;

    if(cur == NULL){
        printf("Cannot perform deletion as Linked LIst is Empty\n");

    } else if(cur->next == NULL){
        cur = NULL;
        ll->count -= 1;
        printf("Linked List had 1 note. It is Empty Now (After Deletion Operation\n");

    } else {
        while(cur->next->next){
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = NULL;
        free(temp);     
        ll->count -= 1;
    }
}

// Delete note at position arPosition
void delete_LL_atPosition(LinkedList * ll, int atPosition){
    Node * cur = ll->head;
    Node * temp;

    // If List is empty
    if(!cur){
        printf("Linked List is empty. Cannot Perform Deletion\n");
        return;
    }

    // If position doesn't exist
    if(atPosition > ll->count || atPosition <= 0){
        printf("Positon not present in Linked List. Cannot Perform Deletion\n");
        return;
    }

    // Position is beginning
    if(atPosition == 1){
        if(cur->next == NULL){
            cur = NULL;
        } else {
            temp = cur;
            cur = cur->next;
            ll->head = cur;
            //free(temp);
        }
        ll->count -= 1;
        return;
    }

    // Position is end
    if(atPosition == ll->count){
        while(cur->next->next){
            cur = cur->next;
        }
        temp = cur;
        cur->next = NULL;
        //free(temp);
        ll->count -= 1;
        return;
    }

    // Deleting not somewhere in between list 
    int tempInt = atPosition-1;
    while(--tempInt){
        cur = cur->next;
    }
    
    temp = cur->next;
    cur->next = cur->next->next;
    //free(temp);  
    ll->count -= 1;
}

// Delete the node after the node with data withData
void delete_LL_afterData(LinkedList * ll, int afterData){

    Node * cur = ll->head;
    Node * temp;
    bool dataPresent = false;

    if(cur == NULL){
        printf("Cannot perform deletion as Linked List is Empty\n");
    }

    while(cur->next){
        if(cur->data == afterData){
            dataPresent = true;
            if(cur->next == NULL){
                printf("Cannot delete after data %d as no data is present after it\n", afterData);
                break;

            } else{
                temp = cur->next;
                cur->next = cur->next->next;
                //free(temp);
                ll->count -= 1;
                break;
            }
        }
        cur = cur->next;
    }

    if(dataPresent == false){
        printf("Cannot perform Deletion. 'afterData' Not Found\n");
    }
}

// Reverse a Linked List Iteratively
void reverse_LL_Iteratively(LinkedList * ll){
    Node * p = NULL;
    Node * q = ll->head;
    Node * temp;
    while(q){
        temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    ll->head = p;
}

// Reverse a Linked List Recursively version 1
void reverse_LL_Recursively(LinkedList * ll, Node * prev, Node * cur){
    if(!cur){
        ll->head = prev;
        return;
    } else{
        reverse_LL_Recursively(ll, cur, cur->next);
        cur->next = prev;
    }
}

// Reverse a linked list Recursively Version 2
void reverse_LL_Recursively_Ver2(LinkedList * ll, Node * head){
    if(!head || !head->next){
        ll->head = head;
        return;
    } else {
        reverse_LL_Recursively_Ver2(ll, head->next);
        head->next->next = head;
        head->next = NULL;
    }
}

Node * reverse_LL_Recursively_Ver3( Node * head){
    Node * newHead_lastNode;
    if(!head || !head->next){
        return head;
    }

    newHead_lastNode = reverse_LL_Recursively_Ver3(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead_lastNode;
}

//---------------------------------makeDemoLL()---------------------------------------------//

// Function to initialize a linked list to work with 
struct node * makeDemoLL() {
// head -> 1 -> 2 -> 3 -> 4 -> NULL

    struct node * head;

    struct node * Node1 = (Node *)malloc(sizeof(Node));
    struct node * Node2 = (Node *)malloc(sizeof(Node));
    struct node * Node3 = (Node *)malloc(sizeof(Node));
    struct node * Node4 = (Node *)malloc(sizeof(Node));

    Node1->data = 1;
    Node1->next = Node2;

    Node2->data = 2;
    Node2->next = Node3;

    Node3->data = 3;
    Node3->next = Node4;

    Node4->data = 4;
    Node4->next = NULL;

    head = Node1;
    return head;
}

//-----------------------------------------main()----------------------------------------------//
int main(){

    struct linkedlist * LL1 = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    LL1 -> head = makeDemoLL(); // head -> 1 -> 2 -> 3 -> 4 -> NULL
    LL1->count = 4 ;

    printf("\nPrint Initial Linked List Iteratively\n");
    print_LL_Iteratively(LL1->head);

    printf("Print Initial Linked List Using Recursion\n");
    print_LL_Recursively(LL1->head); 

    printf("Print Reverse of Linked List Iteratively\n");
    print_LL_Reverse_Iteratively(LL1->head, LL1->count);

    printf("Print Reverse of Linked List Recursively");
    print_LL_Reverse_Recursively(LL1->head);

    printf("\n\nInsert 5 in  Linked List at beginning\n");
    insert_LL_beginning(LL1, 5);
    print_LL_Iteratively(LL1->head);

    printf("\nInsert 6 in Linked List at end\n");
    insert_LL_end(LL1, 6);
    print_LL_Iteratively(LL1->head);

    printf("\nInsert 7 in  Linked List at positon 4 (Position is Present)\n");
    insert_LL_atPostion(LL1, 7, 4);
    print_LL_Iteratively(LL1->head);

    printf("\nInsert 8 in  Linked List at positon 9 (Position is Not Present) \n");
    insert_LL_atPostion(LL1, 8, 9);
    print_LL_Iteratively(LL1->head);

    printf("\nInsert 8 in  Linked List at positon 7(Position is End Position) \n");
    insert_LL_atPostion(LL1, 8, 7);
    print_LL_Iteratively(LL1->head);

    printf("\nInsert 9 in  Linked List at positon 1(Position is Beginning Position) \n");
    insert_LL_atPostion(LL1, 9, 1);
    print_LL_Iteratively(LL1->head);

    printf("\nInsert 10 in  Linked List after data 4 (Data is Present) \n");
    insert_LL_afterData(LL1, 9, 4);
    print_LL_Iteratively(LL1->head);

    printf("\nInsert 11 in  Linked List after data 15 (Data is NOT Present) \n");
    insert_LL_afterData(LL1, 10, 15);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete from beginning \n");
    delete_LL_beginning(LL1);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete from ending \n");
    delete_LL_end(LL1);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete atPosition 1 \n");
    delete_LL_atPosition(LL1, 1);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete atPosition ending \n");
    delete_LL_atPosition(LL1, LL1->count);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete atPosition 4 \n");
    delete_LL_atPosition(LL1, 4);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete atPosition 56 (Position does NOT exist) \n");
    delete_LL_atPosition(LL1, 56);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete afterData 4 (Data is present) \n"); 
    delete_LL_afterData(LL1,4);
    print_LL_Iteratively(LL1->head);

    printf("\nDelete afterData (Data is NOT present) \n");
    delete_LL_afterData(LL1,67);
    print_LL_Iteratively(LL1->head);

    printf("\nReverse the Linked List Iteratively \n");
    reverse_LL_Iteratively(LL1);
    print_LL_Iteratively(LL1->head);

    printf("\nReverse the Linked List Recursively \n");
    reverse_LL_Recursively(LL1, NULL, LL1->head);
    print_LL_Iteratively(LL1->head);

    printf("\nReverse the Linked List Recursively Version 2\n");
    reverse_LL_Recursively_Ver2(LL1, LL1->head);
    print_LL_Iteratively(LL1->head);

    printf("\nReverse the Linked List Recursively Version 3\n");
    LL1->head = reverse_LL_Recursively_Ver3(LL1->head);
    print_LL_Iteratively(LL1->head);

    return 0;
}




/* Time and Space Complexity Analysis */
/*
-> void print_LL_Iteratively(Node * node);
    TC = O()
    SC = O()

-> void print_LL_Recursively(Node * node);
    TC = O()
    SC = O()

->void print_LL_Reverse_Iteratively(Node * node, int numOfNodes);
    TC = O()
    SC = O()

->void print_LL_Reverse_Recursively(Node * node);
    TC = O()
    SC = O()

--------------------------------------------------------------------------------------------
-> void insert_LL_beginning(LinkedList * ll, int data);
    TC = O()
    SC = O()

-> void insert_LL_end(LinkedList * ll, int data);
    TC = O()
    SC = O()

-> void insert_LL_atPostion(LinkedList * ll, int data, int atPosition); 
    TC = O()
    SC = O()

-> void insert_LL_afterData(LinkedList * ll, int data, int afterData);
    TC = O()
    SC = O()

--------------------------------------------------------------------------------------------
-> void delete_LL_beginning(LinkedList * ll);
    TC = O()
    SC = O()

-> void delete_LL_end(LinkedList * ll);
    TC = O()
    SC = O()

-> void delete_LL_atPosition(LinkedList * ll, int atPosition);
    TC = O()
    SC = O()

-> void delete_LL_afterData(LinkedList * ll, int afterData);
    TC = O()
    SC = O()

--------------------------------------------------------------------------------------------
-> void reverse_LL_Iteratively(LinkedList * ll);
    TC = O()
    SC = O()

-> void reverse_LL_Recursively(LinkedList * ll, Node * p, Node * q);
    TC = O()
    SC = O()

-> void reverse_LL_Recursively_Ver2(LinkedList * ll, Node * head); 
    TC = O()
    SC = O()

-> Node * reverse_LL_Recursively_Ver3( Node * head); 
    TC = O()
    SC = O()

*/