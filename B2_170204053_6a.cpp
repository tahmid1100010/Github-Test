#include<iostream>
#include<limits.h>

#define V 6
using namespace std;

void dijkstra(int graph[V][V],int source);
int min_distance(int distance[],bool sptSetExplored[]);
void printSolution(int distance[]);

int main(){
    int graph[V][V];
    cout<<"Enter the vertices and their values: \n";

    for(int i=0;i<V;i++){
            cout<<"\t";
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }

    dijkstra(graph,0);

    return 0;
}

void dijkstra(int graph[V][V],int source){
    int distance[V];

    bool sptSetExplored[V];

    for(int i=0;i<V;i++){
        distance[i]=INT_MAX;
        sptSetExplored[i]=false;
    }

    distance[source]=0;

    for(int cnt=0;cnt<V-1;cnt++){
        int u=min_distance(distance,sptSetExplored);
        sptSetExplored[u]=true;

        for(int v=0;v<V;v++){
            if(!sptSetExplored[v]&&graph[u][v]&&distance[u]!=INT_MAX&&distance[u]+graph[u][v]<distance[v]){
                distance[v]=distance[u]+graph[u][v];
            }
        }
    }

    printSolution(distance);
}

int min_distance(int distance[],bool sptSetExplored[]){
    int minimum=INT_MAX;
    int min_index;

    for(int v=0;v<V;v++){
        if(sptSetExplored[v]==false&&distance[v]<=minimum){
            minimum=distance[v];
            min_index=v;
        }
    }
    return min_index;
}

void printSolution(int distance[]){
    cout<<"Vertex \t\tShortest distance from source\n";
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<distance[i]<<"\n";
    }
}
