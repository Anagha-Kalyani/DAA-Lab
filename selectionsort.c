//PROGRAM FOR SELECTION SORT
#include<stdio.h>
#include<time.h>
void printEle(int a[],int n){
        for(int i=0;i<n;i++)
                printf("%d\n",a[i]);
        printf("\n");
}
void selection(int a[],int n){
        for(int i=0;i<=n-2;i++){
                int min=i;
                for(int j=i+1;j<=n-1;j++){
                        if(a[j]<a[min])
                                min=j;
                }
                int temp=a[i];
                a[i]=a[min];
                a[min]=temp;
        }
}
void main(){
        int n;
        clock_t start,end;
        printf("How many packages?\n");
        scanf("%d",&n);
        int a[n];
        int r;
        for(int i=0;i<n;i++){
                r=rand();
                a[i]=r;
        }
        printf(“The packages before sorting: \n");
        printEle(a,n);
        start=clock();
        selection(a,n);
        end=clock();
        printf(“The packages after sorting: \n");
        printEle(a,n);
        double timetaken=(double)(end-start)/CLOCKS_PER_SEC;
	   printf("Time taken for selection sort is: %f\n",timetaken);
}
