//PROGRAM FOR MERGE SORT
#include <stdio.h>
#include <time.h>
void printEle (int a[],int n){
    for (int i=0;i<n;i++)
        printf("%d\n",a[i]);
    printf("\n");
}
void mergeSort(int arr[], int l, int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}
void merge(int arr[], int l, int m, int r){
	int n1=m-l+1;
	int n2=r-m;
	int L[n1], R[n2];
	for(int i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(int j=0;j<n2;j++)
		R[j]=arr[m+1+j];
	i=0; 
	j=0; 
	k=l; 
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
}
void main(){
        int n;
        clock_t start,end;
        printf("How many books?\n");
        scanf("%d",&n);
        int a[n];
        int r;
        for(int i=0;i<n;i++){
                r=rand();
                a[i]=r;
        }
        printf("The ISBN of books before sorting: \n");
        printEle(a,n);
        start=clock();
        mergeSort(a,0,n-1);
        end=clock();
        printf("The ISBN of books after sorting: \n");
        printEle(a,n);
        double timetaken=(double)(end-start)/CLOCKS_PER_SEC;
	   printf("Time taken for merge sort is: %f\n",timetaken);
}
