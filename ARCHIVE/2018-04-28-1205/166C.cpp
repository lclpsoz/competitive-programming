#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, k;
deque<int> vec;
bool test;

int main ()
{
	scanf ("%d %d", &n, &k);
	int x;
	test = true;
	while (n--) {
		scanf ("%d", &x);
		vec.push_back (x);
		if (x == k) test = false;
	}

	int ans = 0;
	if (test) {
		vec.push_back (k);
		ans++;
	}

	sort (vec.begin(), vec.end());

	int i = ((vec.size()+1)/2)-1;
	int s = vec.size();

	while (vec[i] < k) {
		/*for (int z : vec)
			printf ("%d ", z);
		putchar ('\n');*/
		vec.push_back (1e9);
		s++;
		i = ((s+1)/2)-1;
		ans++;
	}
	while (vec[i] > k) {
		vec.push_front (1);
		s++;
		i = ((s+1)/2)-1;
		ans++;
	}

	printf ("%d\n", ans);

	return 0;
}
