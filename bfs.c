#include<stdio.h>
int g[10][10],n,selected[10],q[10],f=0,r=-1;
void bfs(int v){
    for(int i=0;i<n;i++){
        if(g[v][i]&&!selected[i]){
            q[++r]=i;
            selected[i]=1;
            printf("%d\t",i);
        }
        if(f<=r){
            bfs(q[f++]);
        }
    }
}
void main(){
    printf("n\n");
    scanf("%d",&n);
    printf("matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        selected[i]=0;
    }
    printf("Start vertex:\n");
    int source;
    scanf("%d",&source);
    selected[source]=1;
    printf("bfs traversal:\n");
    printf("%d\t",source);
    bfs(source);
    int reachable[10];
    for(int i=0;i<n;i++){
        reachable[i]=selected[i];
    }
    for(int i=0;i<n;i++){
        if(selected[i]==0){
            selected[i]=1;
            printf("%d\t",i);
            bfs(i);
        }
    }
    printf("\n");
    printf("The reachable vertices from source are:\n");
    for(int i=0;i<n;i++){
        if(reachable[i]){
            printf("%d\t",i);
        }
    }
    printf("\n");
}
