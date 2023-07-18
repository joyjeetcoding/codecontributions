#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

void primMST()
{
    int selected[MAX_VERTICES];
    int i, j, k;
    int numEdges = 0;
    int totalWeight = 0;

    for (i = 0; i < numVertices; i++)
        selected[i] = false;

    selected[0] = true;

    printf("Edge : Weight\n");

    while (numEdges < numVertices - 1)
    {
        int min = INF;
        int x = 0, y = 0;

        for (i = 0; i < numVertices; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < numVertices; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        totalWeight += graph[x][y];
        selected[y] = true;
        numEdges++;
    }

    printf("Total weight of the minimum spanning tree: %d\n", totalWeight);
}

int main()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();

    return 0;
}