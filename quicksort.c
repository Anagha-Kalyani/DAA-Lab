#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printEle (int a[],int n){
    for (int i=0;i<n;i++)
        printf("%d\n",a[i]); //print all array elements
    printf("\n");
}
int partition(int a[], int l, int r){    
    int i,j,pivot,temp;
    if(l<r){
        pivot=l; //pivot element is the first element of array
	   i=l;
        j=r;
	    while(i<j){
	        while(a[i]<=a[pivot] && i<r)
		        i++; //increment i till an element > pivot is found
	        while(a[j]>a[pivot])
		        j--; //decrement j till an element < pivot is found
	        if(i<j){
		        temp=a[i];
		        a[i]=a[j];
		        a[j]=temp; //swap elements in ith and jth position
	        }  
	    }  
	    temp=a[pivot];
	    a[pivot]=a[j];
        a[j]=temp; //swap pivot and jth element
	}  
	return j;
} 
void quickSort(int a[],int l,int r){
        if(l<r){
                int s=partition(a,l,r); //position to partition array
                quickSort(a,l,s-1); //recursively sort subarray before s
                quickSort(a,s+1,r); //recursively sort subarray after s
        }
}


void main(){
        int n;
        clock_t start,end;
        printf("How many files?\n");
        scanf("%d",&n); //input number of files
        int a[n]; //array of n file IDs
        int r;
        for(int i=0;i<n;i++){
                r=rand(); //generate random file IDs
                a[i]=r; //store generated random IDs in array
        }
        printf("The file IDs before sorting: \n");
        printEle(a,n);
        start=clock(); //start clock
        quickSort(a,0,n-1); //perform quicksort
        end=clock(); //end clock
        printf("The file IDs after sorting: \n");
        printEle(a,n);
        double timetaken=(double)(end-start)/CLOCKS_PER_SEC;//time taken
	   printf("Time taken for quick sort is: %f\n",timetaken);
}
