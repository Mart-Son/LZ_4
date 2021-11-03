#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void DFS(int v, int **M, int *Vis, int Size)
{
	int i;
	Vis[v]=1;printf("%3d", v+1);
	for(i=0;i<Size;i++)
		if((M[v][i]==1)&&(Vis[i]==0))
			DFS(i, M, Vis, Size);
}

void main()
{
	int **G=NULL, i=0, j=0, S=0, *Visited=NULL, N;
	char ReVis=0;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("Введите размерность матрицы смежности: ");
	scanf("%d", &S);
	while(S<=0)
	{
		printf("Некорректно введённое число! Введите целое положительное число: ");
		scanf("%d", &S);
	}
	G=(int**)malloc(S*sizeof(int));
	Visited=(int*)malloc(S*sizeof(int));
	for(i=0;i<S;i++)
		Visited[i]=0;
	for(i=0;i<S;i++)
	{
		G[i]=(int*)malloc(S*sizeof(int));
		for(j=0;j<S;j++)
		{
			G[i][j]=rand()%2;
			if(G[i][i]!=0)
				G[i][j]=0;
		}
	}
	for(i=0;i<S;i++)
	{
		printf("\n%4d|", i+1);
		for(j=0;j<S;j++)
			{
				G[j][i]=G[i][j];
				printf("%2d", G[i][j]);
			}
	}
	printf("\nС какой вершины начать обход в глубину? "); scanf("%d", &N);
	while (N<1 || N>S)
	{
		printf("Некорректно введённое число! Введите целое положительное число в пределах размера матрицы смежности: ");
		scanf("%d", &N);
	}
	printf("\n\nПорядок обхода графа в глубину: ");
	
	for(i=N-1;Visited[i]<1;i++)
	{
		if(ReVis==1 && i==N-1)
			break;
		if(i==S-1)
			i=0;
		DFS(i, G, Visited, S);
		ReVis=1;
	}
	printf("\n");
	free(Visited);
	free(G);
}