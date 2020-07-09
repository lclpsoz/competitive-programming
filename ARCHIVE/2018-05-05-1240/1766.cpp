#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, pair<double, string>>> p;

int t;
int n, m;
string str;
char arr[110];
int w, age;
double h;
vector<p> vec;

int main ()
{
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d %d", &n, &m);
		while (n--) {
			scanf ("%s %d %d %lf", arr, &w, &age, &h);
			vec.push_back ({-w, {age, {h, arr}}});
			sort (vec.begin (), vec.end());
		}
		printf ("CENARIO {%d}\n", i);
		for (int j = 1; j <= m; j++) {
			printf ("%d - ", j);
			cout << vec[j-1].second.second.second << '\n';
		}
		vec.clear();
	}

	return 0;
}
