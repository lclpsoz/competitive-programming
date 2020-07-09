#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int tsts, n;
map<string, pair<int, double>> mp;
queue<string> q;
char arr[100];
double val, maxi;
int qnt;

int main ()
{
	scanf ("%d", &tsts);
	while (tsts--) {
		mp.clear ();
		scanf ("%d", &n);
		getchar ();
		while (n--) {
			scanf ("%[^\n]", arr);
			getchar ();
			scanf ("%lf", &val);
			getchar ();
			mp[arr] = {0, val};
		}
		scanf ("%lf ", &maxi);
		while (scanf ("%[^\n] %d" , arr, &qnt), qnt) {
			getchar ();
			if (mp.count (arr) == 0)
				q.push (arr);
			else
				mp[arr].x += qnt;
		}
		double ans = 0.0;
		for (auto p : mp)
			ans += p.y.x*p.y.y;
		while (!q.empty()) {
			printf ("NAO LISTADO: ");
			cout << q.front() << '\n';
			q.pop();
		}
		printf ("Peso total: %0.2lf kg\n", ans);
		printf ("Numero de trenos: %0.0lf\n\n", ceil (ans/maxi));
	}

	return 0;
}
