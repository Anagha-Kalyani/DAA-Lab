#include<stdio.h>
int max(int a,int b){
        return (a>b)?a:b; //returns maximum value
}
int knapsack(int W, int w[10],int v[10], int n){
        int i,j;
        int K[n+1][W+1]; //n items, W max capacity
        for(i=0;i<=n;i++){ 
                for(j=0;j<=W;j++){
                        if(i==0||j==0){
                                K[i][j]=0; //first row and column are initialized with 0
                        }
                        else if(j-w[i-1]>=0){ //if the item can be included in the knapsack
                                K[i][j]=max(K[i-1][j],v[i-1]+K[i-1][j-w[i-1]]);
                                /*maximum of the existing value and the value after adding item*/
                        }
                        else{ //if item cannot be included in knapsack
                                K[i][j]=K[i-1][j]; //retain existing value
                        }
                }
        }
	   printf(“The matrix is:\n”);
        for(i=0;i<=n;i++){
                for(j=0;j<=W;j++){
                        printf("%d\t",K[i][j]); //print matrix
                }
                printf("\n");
        }
        int capacity=W;
        int selected[n]; //to find most valuable subset
        selected[0]=0;
        for(int i=n;i>=1&&capacity!=0;i--){
            if(K[i][capacity]!=K[i-1][capacity]){ //if item is included
                selected[i]=1; //mark as 1
                capacity=capacity-w[i-1]; //remaining capacity after adding item
            }


            else{ //if item is not included
                selected[i]=0; //mark as 0
            }
        }
        printf("The items selected are:\n");
        for(int i=1;i<=n;i++){
            if(selected[i])
                printf("%d\t",i); //print only those items marked as 1 ie included
        }
        printf("\n");
        return K[n][W]; //result is in the last cell of matrix
}
void main(){
        int W; //capacity of knapsack
        printf("Enter the maximum capacity of the bag:\n");
        scanf("%d",&W);
        int n; //number of items
        printf("Enter the number of items:\n");
        scanf("%d",&n);
        int w[n]; //weight of items
        int v[n]; //value of items
        for(int i=0;i<n;i++){
                printf("Enter value of item %d:\n”,i+1);
                scanf("%d",&v[i]);
                printf("Enter weight of item %d:\n”,i+1);
                scanf("%d",&w[i]);
        } //to find value and weight of each item
        int result=knapsack(W,w,v,n); //last cell of matrix holds the maximum profit
        printf("The maximum profit is %d\n",result);

}
