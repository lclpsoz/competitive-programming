#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> livros;

int main ()
{
	int n, x, ans = 0;
	while (scanf ("%d", &n) != EOF) {
		ans = 0;
		livros.clear ();
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			int j;
			sort (livros.begin(), livros.end());
			for (j = 0; j < livros.size(); j++)
				if (livros[j].second == x)
					break;
			if (j == livros.size()) {
				ans++;
				if (livros.size() == 4)
					livros.pop_back();
				livros.push_back ({i*-1, x});
			} else
				livros[j].first = i*-1;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
