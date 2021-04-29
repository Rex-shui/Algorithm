#include "algorithm.h"
#include "tools.h"

#define VTXNUM 20

typedef struct BFSVTX{
        char vtx;
        struct BFSVTX* adj[VTXNUM];
        int idx;
        int color;
}BFSVTX;

typedef struct BFSGraph{
        BFSVTX *vtx[VTXNUM];
        int arcs[VTXNUM][VTXNUM];
        int arcnum;
        int vtxnum;
}BFSGraph;


BFSGraph *init()
{
	BFSGraph *BFS = (BFSGraph *)malloc(sizeof(BFSGraph));

        for(int i=0; i<VTXNUM; i++){
                BFSVTX *vtx = (BFSVTX *)malloc(sizeof(BFSVTX));
                memset(vtx, 0, sizeof(BFSVTX));

                vtx->vtx = 'a'+i;

                BFS->vtx[i] = vtx;
                BFS->vtxnum++;
        }

        for(int i=0; i<VTXNUM; i++)
        {
                for(int j=i+1; j<VTXNUM; j++)
                {
                        int flag = getRand(2);
                        BFS->arcs[i][j] = flag;
                        BFS->arcs[j][i] = flag;
                        BFS->arcnum++;
                }
        }

        for(int i=0; i<VTXNUM; i++)
        {
                for(int j=0; j<VTXNUM; j++)
                {
                        if(BFS->arcs[i][j] == 1){
                                BFS->vtx[i]->adj[BFS->vtx[i]->idx] = BFS->vtx[j];
                                BFS->vtx[i]->idx++;
                        }
                }
        }

	return BFS;
}

/*
 * 1、出队（队中节点都为灰）
 * 2、检测该节点的邻接点，为白入队
 * 2、标记该节点为黑，重复1、2
 * */
void BreathFirstSearch(BFSGraph *BFS)
{
        Queue *Q = Q_get();

        int s = getRand(VTXNUM);

        BFSVTX *start = BFS->vtx[s];
        start->color = 1;

        ENQUEUE(Q, (void *)start);

        while(!Q_isEmpty(Q))
        {
                BFSVTX *u = (BFSVTX *)DEQUEUE(Q);
                for(int i=0; i<u->idx; i++)
                {
                        if(u->adj[i]->color == 0)
                        {
                                u->adj[i]->color = 1;
                                ENQUEUE(Q, (void *)u->adj[i]);
                        }
                }
                u->color = 2;
                printf("%c-->", u->vtx);
        }
        printf("\n");

}

void BFS_print()
{
	BFSGraph *BFS = init();

	printf("arcs:\n");
        for(int i=0; i<VTXNUM; i++)
        {
                for(int j=0; j<VTXNUM; j++)
                {
                        printf("%-4d", BFS->arcs[i][j]);
                }
                printf("\n");
        }

        printf("Adjacency Points:\n");
        for(int i=0; i<VTXNUM; i++)
        {
                printf("%c-->", BFS->vtx[i]->vtx);
                for(int j=0; j<BFS->vtx[i]->idx; j++)
                {
                        printf("%c-->", BFS->vtx[i]->adj[j]->vtx);
                }
                printf("\n");
        }

	printf("BFS:\n");
	BreathFirstSearch(BFS);
}
