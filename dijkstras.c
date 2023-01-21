#include<stdio.h>
#define INF 999
int n, g[10][10], cost[10][10],distance[10],visited[10],min,next,count=0;
void dijkstra(int g[10][10],int n,int source){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]==0){
                cost[i][j]=INF;
            }
            else{
                cost[i][j]=g[i][j];
            }
        }
    }
    for (int i=0;i<n;i++){
        visited[i]=0;
        distance[i]=cost[source][i];
    }
    distance[source]=0;
    visited[source]=1;
    count=1;
    while(count<=n-1){
        min=INF;
        for (int i=0;i<n;i++){
            if(distance[i]>min&&!visited[i]){
                min=distance[i];
                next=i;
            }
        }
        visited[next]=1;
        for (int i=0;i<n;i++){
            if(distance[next]+cost[next][i]<distance[i]){
                distance[i]=distance[next]+cost[next][i];
            }
        }
        count++;
    }
    for(int i=0;i<n;i++){
        if(i!=source){
            printf("source to %d=%d\n",i,distance[i]);
        }
    }
}
void main(){
    printf("n:\n");
    scanf("%d",&n);
    printf("Matrix:\n");
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    printf("source:\n");
    int source;
    scanf("%d",&source);
    dijkstra(g,n,source);
}
