// QUESTION LINK: https://www.geeksforgeeks.org/array-rotation/
// Question : Write a function rotate(ar[], d, n) that  left rotates arr[] of size n by d elements.

/*

TO DO: LEARN HOW JUGGLING ALGORITHM IS WORKING ?

*/



#include<stdio.h>

// Function Declarations
void printArray(int * arr, int sizeArr);
int g_c_d(int a, int b);

void rotate1(int * arr, int d, int n); // -> Rotating by shifting whole array one by one
void rotate2(int * arr, int d, int n); // -> Rotating using a buffer to reduce time Complexity
void rotate3(int * arr, int d, int n); // -> " JUGGLING ALGORITHM "



// Helper Function printArray()
void printArray(int * arr, int sizeArr){
    int i;
    for (i = 0; i < sizeArr; i++){
        printf("%d \t",arr[i]);
    }
    printf("\n");
} 


// Function fot GCD to be used in rotation3()
int g_c_d(int a, int b){ 
    if(a>b){
        if(b == 0){
            return a;

        } else{
            return g_c_d(b, a%b);
        }

    } else{
        if(a == 0){
            return b;

        } else{
            return g_c_d(b%a , a);
        }
    }
}


// Function rotate1()
void rotate1(int * arr, int d, int n){
    int i, temp, j;
    for (i = 0; i < d; i++){
        temp = arr[i];
        for(j = 0; j < n-1; j++){
            arr[j] = arr[j+1];
        }
        arr[j] = temp;
    }
}


// Function rotate2()
void rotate2(int * arr, int d, int n){
    int temp[d], i;
    // Make temp using the first d number of elements of arr.
    for(i = 0; i < d; i++){
        temp[i] = arr[i];
    }
    // Rotate the rest d places
    for(i = 0; i < n-d; i++){
        arr[i] = arr[i+d];
    }
    // Place temp at the end of rotated array in the last d places.
    for(i = 0; i < d; i++){
        arr[n-d+i] = temp[i];
    }

}


// Function rotate3() -- Juggling Algorithm
void rotate3(int * arr, int d, int n){
    int i, j, temp, k;
    int cycles = g_c_d(n, d);

    for (i = 0; i < cycles; i++){
        temp = arr[i];

        j = i; 
        while (1) { 
            k = j + d; 
            if (k >= n) 
                k = k - n; 
            if (k == i) 
                break; 
            arr[j] = arr[k]; 
            j = k; 
            printArray(arr, n);
        } 
        arr[j] = temp; 
    }
}


// Function main()
int main(){
    printf("\n");

    const int sizeArr = 8;
    int arr[sizeArr] = {1, 2, 3, 4, 5, 6, 7, 8};
    int rotateBy = 3;

    //rotate1(arr, rotateBy, sizeArr);
    //rotate2(arr, rotateBy, sizeArr);
    rotate3(arr, rotateBy, sizeArr);
    printArray(arr, sizeArr);
    printf("\n");
    return(0);
}



/*
->rotate1()
->rotate1()
Time Complexity= O(n*d)
Space Complexity= O(1)

We are rotating elements of array one by one
*/


/*
->rotate2()
Time Complexity = O(n+d) = O(n)
Space Complexity = O(d)


Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store d elements in a temp array
   temp[] = [1, 2]
2) Shift rest of the arr[]
   arr[] = [3, 4, 5, 6, 7, 6, 7]
3) Store back the d elements
   arr[] = [3, 4, 5, 6, 7, 1, 2]

*/


/*
->rotate3()
Time Complexity = O(n)
Space Complexity = O(1)
// This is a good method for rotating arrays 

This is the best the above mentioned three.
The total elements moving are equal to the number of elements.

*/