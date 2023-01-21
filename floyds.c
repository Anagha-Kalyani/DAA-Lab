#include<stdio.h>
#include<stdio.h>
int min(int a, int b){
        return (a<b? a:b); //to find the minimum number
}
void floyd(int d[10][10],int n){ //to find shortest distance matrix
        for(int k=0;k<n;k++){ //intermediate matrices
                for(int I=0;i<n;i++){ //row number
                        for(int j=0;j<n;j++){ //column number
                                d[I][j]=min(d[i][j],d[i][k]+d[k][j]); //value of cell is the minimum among the already existing distance and the distance through intermediate city
                        }
                }
        }
}
void main(){
        int n; //number of cities(vertices) in the graph
        printf("Enter the number of cities:\n”);        scanf("%d",&n);
        int d[10][10]; //distance matrix
        printf("Enter the distance matrix:\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        scanf(“%d",&d[i][j]); //input distance matrix
                }
        }
        printf("The entered distance matrix is:\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        printf(“%d\t",d[i][j]); //print distance matrix
                }
                printf("\n");
        }
        floyd(d,n); //call the Floyd function
        printf("The shortest distance matrix is:\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        printf(“%d\t",d[i][j]); //print the shortest distance matrix
                }
                printf("\n");
        }
}
