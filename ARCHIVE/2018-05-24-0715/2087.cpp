#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e6;

int adj[MAXN][28]; // pos 0 is to know if a word ands in there
int lst;

bool ins (char *arr, int i = 0, int p = 0) {
	// printf ("%d %d %c\n", i, p, arr[i]);
	if (arr[i] == '\0') {
		bool ret = (adj[p][0] != 0);
		adj[p][0] = -1;
		return ret;
	}
	else if (arr[i] != '\0') {
		if (adj[p][arr[i]-'a'+1] == 0)
			adj[p][arr[i]-'a'+1] = ++lst;
		if (adj[p][0] == 0) adj[p][0] = 1;
		else if (adj[p][0] == -1) return true;
		ins (arr, i+1, adj[p][arr[i]-'a'+1]);
	}
}

int main ()
{
	int n;
	char arr[105];
	bool ans;
	while (scanf ("%d", &n), n) {
		memset (adj, 0, sizeof (adj));
		lst = 0;
		ans = false;
		for (int i = 0; i < n; i++) {
			arr[0] = '\0';
			getchar ();
			scanf ("%[^\n]", arr);
			if (!ans)
				ans = ins (arr);
			// printf ("%d\n", ans == true);
		}
		printf ("%s\n", ans ? "Conjunto Ruim" : "Conjunto Bom");
	}

	return 0;
}
