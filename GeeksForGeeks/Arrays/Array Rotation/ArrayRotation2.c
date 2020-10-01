// LINK: https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/
// Question : Write a function rotate(ar[], d, n) that left rotates arr[] of size n by d elements.

#include<stdio.h>
// Function Declarations
void reverseArray1(int * arr, int startIndex, int endIndex);
void reverseArrayRecursion(int * arr, int startIndex, int endIndex);
void printArray(int * arr, int size);

void rotate4(int * arr, int d, int n);  // -> " REVERSAL ALGORITHM " - Using reverse()

// Helper function printArray()
void printArray(int * arr, int size){
    int i;
    for (i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// Function to reverse the array reverseArray1()
void reverseArray1(int * arr, int startIndex, int endIndex){
    int temp;
    while(startIndex < endIndex){
        temp = arr[startIndex];
        arr[startIndex] = arr[endIndex];
        arr[endIndex] = temp;
        startIndex += 1;
        endIndex -= 1;
    }
}

// Function to reverse Array using recursion
void reverseArrayRecursion(int * arr, int startIndex, int endIndex){
    if(startIndex >= endIndex){
        return ;
    } else{
    int temp;
    temp = arr[startIndex];
    arr[startIndex] = arr[endIndex];
    arr[endIndex] = temp;
    reverseArrayRecursion(arr, ++startIndex, --endIndex);
    }

}


// rorate4() function to rotate array by d using reverseArray()
void rotate4(int * arr, int d, int n){
    reverseArray1(arr, 0, d-1);
    reverseArray1(arr, d, n-1);
    reverseArray1(arr, 0, n-1);

    // reverseArrayRecursion(arr, 0, d-1);
    // reverseArrayRecursion(arr, d, n-1);
    // reverseArrayRecursion(arr, 0, n-1);
}


// MAIN FUNCTION
int main(){
    printf("\n");

    const int sizeArr = 8;
    int arr[sizeArr] = {1, 2, 3, 4, 5, 6, 7, 8};
    int rotateBy = 3;

    // We calcualte rotateBy_Actual to handle the case 
    // When rotateBy is greater than sizeArr
    int rotateBy_Actual = rotateBy % sizeArr;
    reverseArray1(arr,0,7);
    rotate4(arr, rotateBy_Actual, sizeArr);
    printArray(arr, sizeArr);

    printf("\n");
    return 0;

}


/*
-> rotate4()
Time Complexity : O(n) -> if we use reverseArray1()
                : O(n) -> if we use reverseArrayRecursion()

Space Complexity : O(1) -> for reverseArray1()
                 : O(n) -> for reverArrayRecursion()

-> For reverseArray1(){
    Time Complexity depends on the number of elements moved i.e. n
    Space Complexity is constant
}

-> for reverArrayRecursion(){
    Time Complexity is found the way we find TC for recursice functions
    Space Complexity for each call is O(1) but there can be n-1 stack calls, therefore it is O(n)
}
*/