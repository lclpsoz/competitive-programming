#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, m, c;
int mat[1005][1005];

int main ()
{
	scanf ("%d %d %d", &n, &m, &c);
	bool ans = true;
	bool check;
	int file = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &mat[i][j]);

	int d1, d2;
	d1 = d2 = 1e5;
	file = -1;
	check = false; // Nao possuia alunos
	for (int i = 0; i < m; i++) {
		d1 = d2 = 1e5;
		for (int j = 0; j < n; j++) {
			// printf ("%d %d\n", j, i);
			if (mat[j][i] != 0) {
				if (check && file == i-1) {
					ans = false; // Fileiras seguidas
					break;
				} else {
					file = i;
					check = true;
				}
				// printf ("<<\n");
				if (mat[j][i] == 1) {
					// printf ("|d1: %d\n", d1);
					if (d1 <= c) {
						ans = false;
						break;
					}
					d1 = 0;
				} else if (mat[j][i] == 2) {
					if (d2 <= c) {
						ans = false;
						break;
					}
					d2 = 0;
				}
				// printf ("<<<\n");
				d1++;
				d2++;
			}
		}
		if (!ans) break;
		if (file < i)
			check = false; // Nao possuia cadeiras
	}

	printf ("%s\n", ans ? "S" : "N");

	return 0;
}
