/*                                                    Adjacency Matrix: 
  a--5--b               Connections a -> b, a -> c      A  B  C  D
  |     |                           b -> a ,b -> a   A  0  5  4  0
  4     2                           c -> a ,c -> d   B  5  0  0  2     
  |     |                           d -> c ,d -> b   C  4  0  0  3
  c--3--d                                            D  0  2  3  0
  
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
void addEdges(int src,int dest,int weight){
    adj[src][dest] = weight;
    adj[dest][src] = weight; // This is for undirected graph 
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
    int vertices,edges,src,dest,weight;
    printf("Enter Number of vertices: ");
    scanf("%d",&vertices);
    // How many connections you want to do enter edges.
    printf("Enter Number of edges:");
    scanf("%d",&edges);
    initializeMatrix(vertices);
    // format of input 1 2 3
    for(int i = 0;i<edges;i++){
        printf("\nEnter edge %d (format: source destination weight): ",i+1);
        scanf("%d %d %d",&src,&dest,&weight);
        addEdges(src,dest,weight);
    }
    printf("\n Adjacency Matrix:\n");
    printMatrix(vertices);

}