#include <bits/stdc++.h>
using namespace std;

const int MAXN = 33;

int t, n, k;

int func (vector<int> vec, int exp)
{
	vector<int> arr[MAXN];
	// printf ("%ld %d\n", vec.size(), vec[0]);
	int maxi = 0;
	for (int x : vec)
		for (int i = 0; i < exp && x >= 1<<i; i++) {
			if (x & (1<<i)) {
				arr[i].push_back (x & ((1<<(i+1)) - 1));
				maxi = max (i, maxi);
			}
		}
	int choosen = -1;
	for (int i = maxi; i >= 0; i--) {
		if (arr[i].size() >= k) {
			choosen = i;
			break;
		}
	}
	if (choosen == -1) return 0;
	return (1<<choosen | func (arr[choosen], choosen));
}

int main ()
{
	vector<int> vec;
	int x;

	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &n, &k);
		vec.clear();
		while (n--) {
			scanf ("%d", &x);
			vec.push_back (x);
		}
		/*if (choosen > -1) {
			vec = arr[choosen];
			sort (vec.begin(), vec.end(), greater<int>());
			for (int i = 0; i < vec.size()-k+1; i++) {
				aux = vec[i];
				for (int j = 1; j < k; j++)
					aux &= vec[j];
				ans = max (aux, ans);
			}
		}*/
		printf ("%d\n", func (vec, 32));;
	}

	return 0;
}
