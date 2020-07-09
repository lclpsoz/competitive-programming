#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e6+10;

int t, n;
int arr[MAXN];
long long unsigned ans;
deque<int> aux;

int main ()
{
	int N, K, S;
	scanf ("%d", &t);
	while (t--) {
		ans = 0;
		scanf ("%d %d %d", &N, &K, &S);
		arr[0] = S;
		for (int i = 1; i < N; ++i)
			arr[i] = (1LL*arr[i-1]*1103515245 + 12345) % (2147483648LL);

		aux.pb (K-1);
		for (int i = K-2; i >= 0; i--)
			if (arr[i] > arr[aux.back()])
				aux.pb (i);

		for (int i = K; i < N; i++) {
			ans += arr[aux.back()];
			if (!aux.empty() && aux.back() == i-K)
				aux.pop_back ();
			while (!aux.empty() && arr[i] >= arr[aux.front()])
				aux.pop_front();
			aux.push_front (i);
		}
		ans += arr[aux.back()];
		while (!aux.empty()) aux.pop_back();
		printf ("%llu\n", ans);
	}

	return 0;
}
