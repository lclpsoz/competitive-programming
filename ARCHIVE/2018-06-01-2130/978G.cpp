#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 105;

int n, m;
bool STexams[MAXN];
vector<pii> exams[MAXN];
int study[MAXN];
set<pii> s;
int ans[MAXN];

int main ()
{
	int st, en, c;
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf ("%d %d %d", &st, &en, &c);
		exams[st].pb ({en, i});
		study[en] = c;
		STexams[en] = true; // Tem prova
	}

	bool test = true;
	for (int i = 1; i <= n; i++) {
		for (pii p : exams[i])
			s.insert (p);
		if (STexams[i]) {
			// printf ("%d\n", study[i]);
			if (study[i]) {
				test = false;
				break;
			}
			ans[i] = m+1;
		}
		else if (s.size()) {
			auto it = s.begin();
			// printf ("|%d\n", (*it).x);
			ans[i] = (*it).y;
			study[(*it).x]--;
			if (study[(*it).x] == 0) s.erase (it);
		}
		else
			ans[i] = 0;
	}

	if (!test)
		printf ("-1");
	else
		for (int i = 1; i <= n; i++)
			printf ("%d ", ans[i]);
	putchar ('\n');

	return 0;
}
