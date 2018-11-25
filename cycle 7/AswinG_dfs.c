#include <stdio.h>

int adjmat[100][100], n, visited[100] = {0};

void dfs(int v)
{
	int i;
	visited[v] = 1;
	printf("v%d\t", v + 1);
	for (i = 0; i < n; i++)
	{
		if (adjmat[v][i] && !visited[i])
			dfs(i);
	}
}
void main()
{
	int i, j;
	printf("Enter the no of nodes : ");
	scanf("%d", &n);
	printf("Enter adjecency matrix of the graph\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &adjmat[i][j]);
	dfs(0);
	printf("\n");
}
