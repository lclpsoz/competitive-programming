#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int N = 1e5+10;

int v, n, x;
bool arr[N];
char str[1000];

int main ()
{
	while (scanf ("%d %d", &v, &n), n || v) {
		memset (arr, 0, sizeof (arr));
		arr[0] = true;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			for (int j = v; j >= x; j--)
				if (arr[j-x]) {
					arr[j] = true;
					if (j == v) break;
				}
			if (arr[v]) break;
		}
		scanf ("%[^\n] ", str);
		printf ("%s\n", arr[v] ? "sim" : "nao");
	}

	return 0;
}
