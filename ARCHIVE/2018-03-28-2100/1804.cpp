#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;
const int MAXM = 1e3;

int n, arr[MAXN], maxi, sq[MAXM];
char str[10];
int mod, st, endi, aux;

int main ()
{
	scanf ("%d", &n);
	mod = sqrt (n);
	scanf ("%d", &arr[0]);
	sq[0] = arr[0];
	//arr_s[0] = arr[0];
	for (int i = 1; i < n; i++) {
		scanf ("%d", &arr[i]);
		sq[i/mod] += arr[i];
	}
	while (scanf (" %[^\n] ", str) != EOF) {
		aux = 0;
		if (str[0] == '?') {
			sscanf (str+1, "%d", &maxi);
			st = 0;
			maxi-=2;
			aux = 0;
			while ((st+mod-1) <= maxi) {
				aux += sq[st/mod];
				st += mod;
			}
			while (st <= maxi)
				aux += arr[st++];
			printf ("%d\n", aux);
		}
		else {
			sscanf (str+1, "%d", &aux);
			aux--;
			sq[aux/mod] -= arr[aux];
			arr[aux] = 0;
		}
		/*for (int i = 0; i < 10; i++)
			printf ("%d ", arr[i]);
		printf ("\n");
		for (int i = 0; i <= mod; i++)
			printf ("%d ", sq[i]);
		puts ("");*/

	}
	return 0;
}
