#include <stdio.h>  
#include<stdlib.h>
#include<time.h>
void printArr(int arr[], int n) {  
    for (int i = 0; i < n; ++i) {  
        printf("%d\n", arr[i]);  
    }  
    printf("\n");
}
void heapify(int a[], int n, int i) {  
    //i is the index of root node in a[] and n is the size of heap
    int largest = i; // initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  {
        largest = left;  
    }
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  {
        largest = right;  
    }
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
        heapify(a, n, largest);  
    }  
}  
void heapSort(int a[], int n)  {  
    for (int i = n / 2 - 1; i >= 0; i--) { //parent nodes
        heapify(a, n, i); 
    }
    printf("The constructed heap:\n");
    printArr(a, n);
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) { 
        /* Move current root element to end*/  
        // swap a[0] with a[i] 
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
        heapify(a, i, 0);  
    }  
}  
void main(){  
    int n;
    clock_t start,end;
    printf("Enter number of engineering graduates:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the ranks:\n");
    for(int i=0;i<n;i++){
	    a[i]=rand()%1000; 
    }
    printf("Before sorting, ranks are: \n");  
    printArr(a, n);  
    start=clock();
    heapSort(a, n);  
    end=clock();
    double t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("After sorting, ranks are: \n");    
    printArr(a, n);  
    printf("Time taken for heap sort is: %f",t);
}
