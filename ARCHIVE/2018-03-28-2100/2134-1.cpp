#include <bits/stdc++.h>
using namespace std;

int n;
pair <int, string> students[110];
int x;
char str[25];

bool ord (pair <int, string> varA, pair <int, string> varB) {
	if (varA.first < varB.first)
		return true;
	else if (varA.first > varB.first)
		return false;
	else if (varA.second > varB.second)
		return true;
	else
		return false;
}

int main ()
{
	int j = 1;
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf ("%s %d", str, &x);
			students[i] = make_pair(x, str);
		}
		sort (students, students+n, ord);
		printf ("Instancia %d\n", j++);
		cout << students[0].second << "\n\n";
	}

	return 0;
}
