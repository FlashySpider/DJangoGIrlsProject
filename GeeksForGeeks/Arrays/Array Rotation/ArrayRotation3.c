// LINK: https://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/
// Question : Write a function rotate(ar[], d, n) that left rotates arr[] of size n by d elements.
// To Understand -> http://code.cloudkaksha.org/arrays/block-swap-algorithm-for-array-rotation

#include<stdio.h>
// ---------------Function Declarations-------------------------------------------------------

void printArray(int * arr, int size);

void BlockSwap_Recursively(int * arr, int d, int n);  // -> " BLOCK SWAP ALGORITHM" - RECURSIVELY

void BlockSwap_Iteratively(int * arr, int d, int n);  // -> " BLOCK SWAP ALGORITHM" - ITERATIVELY

// It swaps 'd' elements of 2 arrays whise starting indices are s1 and s2
void swap(int * arr, int s1, int s2, int d); // -> Helper function to Block Swap Algorithm



// ---------------Function Definitions-------------------------------------------------------

// Helper function printArray()
void printArray(int * arr, int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


void BlockSwap_Recursively(int * arr, int d, int n){
    // Return if d is '0' or 'n' as it will give the original array
    if(d == 0 || d == n){
        return;
    }

    if(n-d == d){

        return;
    }

    // If A is shorter
    if(d < n-d){
        swap(arr, 0, n-d, d);
        BlockSwap_Recursively(arr, d, n-d);
    }
    // Else B is shorter
    else { 
        swap(arr, 0, d, n-d);
        BlockSwap_Recursively(arr, )
    }
}

void swap(int * arr, int s1, int s2, int d){
    int i,temp;
    for(i=0; i<d; i++){
        arr[s1+i] = temp;
        arr[s1+i] = arr[s2+i];
        arr[s2+i] = temp;
    }  
}

// ---------------MAIN Function-------------------------------------------------------
int main(){
    printf("\n");

    const int sizeArr = 8;
    int arr[sizeArr] = {1, 2, 3, 4, 5, 6, 7, 8};
    int rotateBy = 3;

    void BlockSwap_Recursively(arr, rotateBy, sizeArr);
    printArray(arr, sizeArr);

    // void BlockSwap_Iteratively(arr, rotateBy, sizeArr);
    // printArray(arr, sizeArr);

    printf("\n");
    return 0;

}