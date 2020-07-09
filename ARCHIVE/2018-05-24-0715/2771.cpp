#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 310;

int arr1[MANX];
int arr2[MANX];
int arr3[MANX];
int aux[MANX][MAXN];


int n, k;
int x;
vector<int> vec;

int main ()
{
	while (scanf ("%d %d", &n, &k) != EOF) {
		memset (arr1, 0, sizeof (arr1));
		memset (arr2, 0, sizeof (arr1));
		memset (arr3, 0, sizeof (arr1));
		vec.clear();
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			vec.pb (x);
			arr1[x]++;
		}
		for (int z : vec) {
			for (int i = 0; i <= 100; i++) {
				if (arr1[i])
					arr2[z+i] = arr1[i]+1;
			}
			arr1[z]--;
		}


	}

	return 0;
}
