#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;

int x;
int st, en;
int n, t;
int now, ans, ant;
int arr[MAXN];
vector<int> vec;
int total;

void aprox ()
{
	st = 0;
	en = (vec.size()/2);
	now = 0;
	total = 0;
	for (int xx : vec)
		total += xx;
	for (int i = st; i < en; i++)
		now += vec[i];
	ans = abs(total-now-now);
	do {
		st++; en++;
		ant = ans;
		now += vec[en-1];
		now -= vec[st-1];
		ans = abs(total-now-now);
	} while (ans < ant);
	if (st && ant < ans) {
		st--; en--;
		ans = ant;
	}
	// printf (":::(%d, %d) >>> %d\n", st, en, ans);
}

int exchan ()
{
	vector<int> rose, hugo;
	int tRose = 0, tHugo = 0, s = vec.size()/2, d;
	for (int i = 0; i < vec.size(); i++)
		if (i >= st && i < en) {
			// printf ("r: %d %d\n", i, vec[i]);
			rose.push_back (vec[i]);
			tRose += vec[i];
		} else {
			// printf ("h: %d %d\n", i, vec[i]);
			hugo.push_back (vec[i]);
			tHugo += vec[i];
		}
	// sort (hugo.begin (), hugo.end ());
	// sort (rose.begin (), rose.end ());
	//printf ("SIZE: r(%d) h(%d) vec(%d)\n", rose.size(), hugo.size (), vec.size ());
	// printf ("antes: %d\n", ans);
	ans = abs (tRose-tHugo);
	// printf ("depois: %d\n", ans);
	int i, j;
	while (i != s && j != s) {
		for (i = 0; i < s; i++)
			for (j = 0; j < s; j++) {
				d = rose[i] - hugo[j];
				// printf ("%d %d %d %d\n", rose[i], hugo[j], abs (tRose-tHugo-(2*d)), ans);
				if (abs (tRose-tHugo-(2*d)) < ans) {
					swap (rose[i], hugo[j]);
					tRose = tRose - hugo[j] + rose[i];
					tHugo = tHugo - rose[i] + hugo[j];
					i = 0;
					ans = abs (tRose-tHugo);
					break;
				}
			}
		printf ("%d %d\n", i, j);
	}
}

int main ()
{
	scanf ("%d", &t);
	for (int ii = 0; ii < t; ii++) {
		vec.clear ();
		scanf ("%d", &n);
		total = 0;
		for (int i = 0; i < 105; i++)
			arr[i] = 0;
		for (int i = 0; i < 2*n; i++) {
			scanf ("%d", &x);
			vec.push_back (x);
		}
		if (n < 2) {
			if (n == 0)
				printf ("0\n");
			else
				printf ("%d\n", abs (vec[0]-vec[1]));
		} else {
			sort (vec.begin (), vec.end ());
			// Aproxima a resposta pelos
			// st e en:
			// aprox ();
			// Chega a diferenca minima:
			st = 0;
			en = vec.size()/2;
			exchan ();
			printf ("%d\n", ans);
		}
	}

	return 0;
}
