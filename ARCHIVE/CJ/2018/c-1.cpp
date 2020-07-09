#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 30;

int t;
int a, n;
int x, y;
bool mat[MAXN][MAXN];
int maxi, aux;

int check (int x, int y)
{
	int r = 0;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (mat[x+i][y+j] == 0)
				r++;
	return r;
}

int main ()
{
	FILE *fp;
	fp = fopen ("time.out", "a+");
	int st = clock();
	scanf ("%d", &t);
	vector<pii> p20, p200, pNow;
	for (int j = 2; j < 5; j++)
		for (int k = 2; k < 4; k++) {
			// printf ("%d %d %d\n", j, k, check(j, k));
			p20.push_back ({j, k});
		}
	for (int j = 2; j < 20; j++)
		for (int k = 2; k < 10; k++)
			p200.push_back({j, k});

	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < MAXN; k++)
				mat[j][k] = false;
		/*for (int i = 1; i < 21; i++) {
			for (int j = 1; j < 11; j++)
				//fprinf (fp, "%d ", mat[i][j]);
			//fprinf (fp, "\n");
		}*/
		scanf ("%d", &a);
		if (a == 20)
			pNow = p20;
		else
			pNow = p200;
		pii choosen;
		x = y = 1;
		int maxi_bef = 9;
		while (x > 0 && y > 0) {
			maxi = -1;
			for (pii p : pNow) {
				aux = check (p.first, p.second);
				if (aux > maxi) {
					maxi = aux;
					choosen = p;
				}
				if (maxi == maxi_bef)
					break;
			}
			maxi_bef = maxi;
			printf ("%d %d\n", choosen.first, choosen.second);
			fflush (stdout);
			scanf ("%d %d", &x, &y);
			mat[x][y] = true;
			//fprinf (fp, "----------------------------------------\n");
			//fprinf (fp, "%d %d\n", x, y);
			/*for (int i = 1; i < 21; i++) {
				for (int j = 1; j < 11; j++)
					//fprinf (fp, "%d ", mat[i][j]);
				//fprinf (fp, "\n");
			}*/
		}
		if (x == -1 && y == -1)
			break;
	}
	//fprinf (fp, "-------------------------------------------------\n");
	/*for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 11; j++)
			//fprinf (fp, "%d ", mat[i][j]);
		//fprinf (fp, "\n");
	}
	fclose (fp);*/
	fprintf (fp, "%lf\n", (double)(clock()-st)/CLOCKS_PER_SEC);
	fclose (fp);

	return 0;
}
