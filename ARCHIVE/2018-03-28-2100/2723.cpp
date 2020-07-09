#include <bits/stdc++.h>
using namespace std;

int t, n, car;
vector<int> vec;

bool back_track (int *pos, int *x)
{
	//printf ("%d %d %d\n", *pos, *x, vec[*pos]);
	bool ans = false;
	if (vec[*pos] == 0)
		return true;
	*pos += 1;
	if (abs(*x-vec[(*pos)-1]) <= 5) {
		*x -= vec[*pos-1];
		ans = back_track (pos, x);
	}
	if (!ans && abs(*x+vec[*pos-1]) <= 5) {
		*x += vec[*pos-1];
		ans = back_track (pos, x);
	}
	return ans;
}

int main ()
{
	bool ans;
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d", &n);
		int x = 0;
		for (int j = 0; j < n; j++) {
			scanf ("%d", &x);
			vec.push_back(x);
		}
		vec.push_back(0);
		int pos = 0;
		x = 0;
		ans = back_track (&pos, &x);
		vec.clear();
		ans ? printf ("Feliz Natal!\n") : printf ("Ho Ho Ho!\n");
	}
	return 0;
}
