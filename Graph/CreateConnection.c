/*                                                 Adjacency Matrix:
 a----b               Connections a -> b, a -> c       A  B  C  D 
 |    |                           b -> a ,b -> a    A  0  1  1  0
 |    |                           c -> a ,c -> d    B  1  0  0  1     
 c----d                           d -> c ,d -> b    C  1  0  0  1
                                                    D  0  1  1  0
*/
#include<stdio.h>
#define max_vertices 10
int adj[max_vertices][max_vertices];
/*
function to initialize adjacence Matrix.
Before connection initialize all elements  of adj matrix with Zero.
*/
void initializeMatrix(int vertices){
    for(int i = 0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            adj[i][j]=0;
        }
    }
}
// function for add edges for connect vertices.
void addEdges(int src,int dest){
    adj[src][dest] = 1;
    adj[dest][src] = 1; // This is for undirected graph 
}
void printMatrix(int vertices){
    for(int i = 0;i<vertices;i++){
        for(int j = 0;j<vertices;j++){
            printf(" %d ",adj[i][j]);
        }
            printf("\n");
    }
}
void main(){
    int vertices,edges,src,dest;
    printf("Enter Number of vertices: ");
    scanf("%d",&vertices);
    // How many connections you want to do enter edges.
    printf("Enter Number of edges:");
    scanf("%d",&edges);
    initializeMatrix(vertices);
    // format of input 1 2 
    for(int i = 0;i<edges;i++){
        printf("\nEnter edge %d (format: source destination): ",i+1);
        scanf("%d %d",&src,&dest);
        addEdges(src,dest);
    }
    printf("\n Adjacency Matrix:\n");
    printMatrix(vertices);

}