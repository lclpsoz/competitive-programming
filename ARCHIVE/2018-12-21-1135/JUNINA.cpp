#include "stdio.h"
using namespace std;

const int N = 22;

int n;
int adj[N];

bool eval (int msk) {
	for (int i = 0; i < n; i++)
		if ((msk&(1<<i)) and (adj[i] & msk))
			return false;
	return true;
}

int main () {
	int teste = 1;
	while (scanf ("%d", &n), n) {
		for (int i = 0; i < n; i++)
				adj[i] = 0;
			
		for (int i = 0; i < n; i++) {
			int u;
			while (scanf ("%d", &u), u) {
				--u;
				adj[u] = adj[u] | (1<<i);
				adj[i] = adj[i] | (1<<u);
			}
		}
		
		int mx = 1<<n;
		int ans = 0;
		for (int msk = 1; msk < mx; msk++)
			if (__builtin_popcount (msk) > ans and eval (msk))
				ans = __builtin_popcount (msk);
		printf ("Teste %d\n", teste++);
		printf ("%d\n\n", ans);
	}

	return 0;
}
