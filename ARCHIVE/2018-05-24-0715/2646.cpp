#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, m;
int adj[30];
char arr1[55];
char arr2[55];
int aux;

int dfs (int st) {
	// printf ("  %d\n", st);
	for (int i = 0; i <= 'z'-'a'; i++)
		if ((adj[st] & 1<<i) && !(aux & (1<<i))) {
			aux |= (1<<i);
			adj[st] |= dfs (i);
			// aux ^= (1<<i);
		}

	return adj[st];
}

int main ()
{
	char a, b;
	scanf ("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf (" %c %c", &a, &b);
		adj[a-'a'] |= (1<<(b-'a'));
	}

	for (int i = 'a'-'a'; i <= 'z'-'a'; i++) {
		aux = 0;
		// printf ("%d\n", i);
		dfs (i);
	}


	bool ans = false;
	for (int i = 0; i < n; i++) {
		scanf ("%s %s", arr1, arr2);
		int a = strlen(arr1);
		int b = strlen(arr2);
		if (a == b) {
			ans = true;
			for (int i = 0; i < a; i++) {
				if (arr1[i] != arr2[i] && !(adj[arr1[i]-'a'] & (1<<(arr2[i]-'a')))) {
					ans = false;
					break;
				}
			}
			printf ("%s\n", ans ? "yes" : "no");
		} else {
			printf ("no\n");
		}
	}

	return 0;
}
