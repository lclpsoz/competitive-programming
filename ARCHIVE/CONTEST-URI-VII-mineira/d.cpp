#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int arr[5];

int main ()
{
	for (int i = 0; i < 4; i++) {
		scanf ("%d", &arr[i]);
		if (arr[i] == 1)
			printf ("%d\n", i+1);
	}


	return 0;
}
