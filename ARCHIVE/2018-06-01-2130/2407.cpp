#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

typedef vector<int> row;
typedef vector<row> matriz;

int mat[1010][1010];
int n;
bool verif[1000010];

int func () {
	int row_val = -1;
	int aux = 0;
	for (int i = 0; i < n; i++) {
		aux = 0;
		for (int j = 0; j < n; j++)
			aux += mat[i][j];
		if (row_val == -1) row_val = aux;
		else if (row_val != aux) return 0;
	}

	int col_val = -1;
	for (int i = 0; i < n; i++) {
		aux = 0;
		for (int j = 0; j < n; j++)
			aux += mat[j][i];
		if (col_val == -1) col_val = aux;
		else if (col_val != aux) return 0;
	}
	if (col_val != row_val) return 0;
	int dia_val = 0;
	for (int i = 0; i < n; i++)
		dia_val += mat[i][i];
	if (dia_val != row_val) return 0;
	return dia_val;
}

int main ()
{
	int x;
	bool ans = true;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &x);
			if (verif[x]) {
				ans = false;
				break;
			}
			verif[x] = true;
			mat[i][j] = x;
		}
	}

	if (ans)
		printf ("%d\n", func ());
	else
		printf ("0\n");

	return 0;
}
