#include<stdio.h>
int max(int a, int b){ 
        return (a>b? a:b); 
} //to find the maximum of two numbers
void warshall(int r[10][10],int n){ //to find transitive closure
        for(int k=0;k<n;k++){ //intermediate matrices
                for(int i=0;i<n;i++){  //row number
                        for(int j=0;j<n;j++){ //column number 
                            r[I][j]=max(r[i][j],r[i][k]&&r[k][j]);
	/*the value in the cell is 1 if it was already 1 or if there exists a path from i to j via k*/
                        }
                }
        }
}
void main(){
        int n; //number of systems(vertices) gives the order of the matrix
        printf("Enter the number of systems in the network:\n");
        scanf("%d",&n);
        int r[10][10]; //adjacency matrix indicates whether two vertices are directly connected
        printf("Enter the adjacency matrix (1 if the systems are directly connected, 0 otherwise):\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        scanf("%d",&r[i][j]); 
                }
        } //input the matrix elements

        printf("The entered adjacency matrix is:\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        printf("%d\t",r[i][j]);
                }
                printf("\n");
        } //print the matrix
        warshall(r,n); //call the warshall function
        printf("The transitive closure is (1 if there is a connection between the systems, 0 otherwise):\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        printf("%d\t",r[i][j]);
                }
                printf("\n");
        } //print the transitive closure matrix
}
