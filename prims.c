#include<stdio.h>
#define INF 99 //infinite distance of vertices are not adjacent
void main() {
  int V; //number of vertices
  int cost=0; //weight of minimum spanning tree
  printf("Enter the number of vertices:\n");
  scanf("%d",&V); 
  int G[V][V]; //adjacency matrix
  printf("Enter the adjacency matrix:\n");
  for(int i=0;i<V;i++){
      for(int j=0;j<V;j++){
          scanf("%d",&G[i][j]);
      }
  }
  int no_edge; //number of edges included in subgraph
  int selected[V]; //vertices included in the subgraph
  for(int i=0;i<V;i++){
      selected[i]=0; //initially no vertex is in the subgraph. all set to false(0)
  }
  no_edge=0; //initially no edges in the subgraph
  selected[0]=1; //choose 0th vertex and make it true(1)
  int x; //row number
  int y; //column number
  printf("The edges and their weights in the minimum spanning tree are: \n");
  while(no_edge<V-1){ //number of edges in the min spanning tree is always lesser than V-1
    int min=INF; //initially set minimum weighted edge from vertex as infinity
    x=0;
    y=0;
    for(int i=0;i<V;i++){
      if(selected[i]){ //if a vertex is selected
        for(int j=0;j<V;j++){
          if(!selected[j]){ //if an adjacent vertex is not selected yet
            if(min>G[i][j]){
              min=G[i][j]; //choose the minimum weighted edge
              x=i;
              y=j; //note down the vertices i and j of the selected vertex 
            }
          }
        }
      }
    }

    cost+=G[x][y]; //add weight 
    printf("Edge: %d - %d\t Weight: %d\n", x, y, G[x][y]); //display the selected edge and its weight
    selected[y]=1; //set the selected vertex as true(1)
    no_edge++;
  }
  printf("The total weight of the minimum spanning tree is %d",cost);
}
