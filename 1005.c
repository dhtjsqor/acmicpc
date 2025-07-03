#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 4
#define max(a,b) a>b ? a:b
int *check;
int *adjacent;
typedef struct _vertex_t{
    struct _vertex_t **edges;
    int id;
    int num_edges;
    int capacity;
}vertex_t;

typedef struct _graph_t{
    vertex_t *vertices;
}graph_t;

void graph_create(graph_t **G,int N){
    *G = (graph_t*)malloc(sizeof(graph_t));
    (*G)->vertices = (vertex_t*)malloc(sizeof(vertex_t) * N);
    for(int i=0;i<N;i++){
        (*G)->vertices[i].id=i;
        (*G)->vertices[i].num_edges=0;
        (*G)->vertices[i].capacity = CAPACITY;
        (*G)->vertices[i].edges = (vertex_t**)malloc(sizeof(vertex_t*) * CAPACITY);
    }
}

void graph_destroy(graph_t **G,int N){
    for(int i=0;i<N;i++){
        free((*G)->vertices[i].edges);
    }
    free((*G)->vertices);
    free(*G);
}

void graph_add_edge(graph_t *G,int u,int v){
    vertex_t *from =&G->vertices[u];
    if(from->num_edges >= from ->capacity){
        from->capacity*=2;
        from->edges = (vertex_t **)realloc(from->edges,from->capacity * sizeof(vertex_t *));
    }
    from->edges[from->num_edges++] = &G->vertices[v];
}

int dfs(graph_t *G, int target){
    if(check[target]!= -1) return check[target];
    int time = 0;
    vertex_t *v = &G->vertices[target];
    for (int i = 0; i < v->num_edges; i++) {
        int prev = v->edges[i]->id;
        time = max(time, dfs(G, prev));
    }
    return check[target] = time + adjacent[target];
}

int main(void){
    graph_t *G = NULL;
    int i,T,N,K,x,y,w;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&K);
        adjacent = (int*)malloc(sizeof(int)*N);
        check = (int*)malloc(sizeof(int)*N);
        for(i=0;i<N;i++) check[i]=-1;
        graph_create(&G,N);
        for(i=0;i<N;i++){
            scanf("%d",&adjacent[i]);
        }
        for(;K>0;K--){
            scanf("%d %d",&x,&y);
            graph_add_edge(G,y-1,x-1);
        }
        scanf("%d",&w);
        printf("%d\n",dfs(G,w-1));
        graph_destroy(&G,N);
        free(adjacent);
        free(check);
    }
}