#include <bits/stdc++.h>
using namespace std;

int g, a, m, c;
int mat1[605][105]; // CURSOS x QNT ATIVIDADES
int mat2[105][2005];// ATIVIDADES X QNT MATERIAS
int mat3[2005][105];// MATERIAS x CAMPIS
int ans[605][105];

int main ()
{
	scanf ("%d %d %d %d", &g, &a, &m, &c);

	for (int i = 0; i < g; i++)
		for (int j = 0; j < a; j++)
			scanf ("%d", &mat1[i][j]);

	for (int i = 0; i < a; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &mat2[i][j]);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < c; j++) {
			scanf ("%d", &mat1[i][j]);
			ans[i]
		}




	return 0;
}
