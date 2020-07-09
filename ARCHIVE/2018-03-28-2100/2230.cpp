#include <cstdio>
#include <queue>

int c, r, st, mon, x, y, now;
int mat[51][51];
int arr[51];
std::queue <int> roads;
int main ()
{
	int cont = 0;
	while (scanf ("%d %d %d %d", &c, &r, &st, &mon), c) {
		for (int i = 0; i < r; i++) {
			scanf ("%d %d", &x, &y);
			mat[x][y] = 1;
			mat[y][x] = 1;
		}
		roads.push (st);
		int i = 0;
		while (!roads.empty() && arr[i] <= mon) {
			now = roads.front();
			roads.pop();
			for (i = 1; i <= c; i++)
				if (mat[now][i] && !arr[i]) {
					arr[i] = arr[now]+1;
					roads.push (i);
				}
		}
		printf ("Teste %d\n", ++cont);
		for (i = 1; i <= c; i++) {
			if (arr[i] && arr[i] <= mon && i != st)
				printf ("%d ", i);
			arr[i] = 0;
		}
		printf ("\n\n");
		for (i = 1; i <= c; i++)
			for (int j = 1; j <= c; j++)
				mat[i][j] = 0;
	}
	return 0;
}
