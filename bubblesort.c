//PROGRAM FOR BUBBLE SORT
#include<stdio.h>
#include<time.h>
void printEle (int a[],int n){
    for (int i=0;i<n;i++)
        printf("%d\n",a[i]);
    printf("\n");
}
void bubbleSort (int a[],int n) {
    clock_t start, end;
    start=clock();
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    end=clock();
    double timetaken= (double) (end-start)/CLOCKS_PER_SEC;
    printf("Time taken for bubble sort is: %f\n",timetaken);
    printf("\n");
}
void main(){
    int n;
    printf ("How many packages?\n");
    scanf("%d",&n);
    printf("\n");
    int a[n];
    int r;
    for (int i=0;i<n;i++){
        r=rand();
        a[i]=r;
    }
    printf(“The packages before sorting: \n");
    printEle(a,n);
    bubbleSort(a,n);
    printf(“The packages after sorting: \n") ;
    printEle(a,n);
}
