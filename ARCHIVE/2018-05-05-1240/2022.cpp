#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
typedef pair<int, pair<double, string>> pa;

char arr[MAXN];
char nome[MAXN];
int q, x;
double cost;
vector<pa> vec;

int main ()
{
	while (scanf ("%s %d", nome, &q) != EOF) {
		while (q--) {
			getchar ();
			scanf ("%[^\n]", arr);
			scanf ("%lf %d", &cost, &x);
			vec.push_back ({-x, {cost, arr}});
		}
		sort (vec.begin(), vec.end());
		printf ("Lista de %s\n", nome);
		for (pa p : vec) {
			for (char c : p.second.second)
				putchar (c);
			printf (" - R$%0.2lf\n", p.second.first);
		}
		putchar ('\n');
		vec.clear ();
	}

	return 0;
}
