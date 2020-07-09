#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int main ()
{
	int n, t;
	char str[55];
	scanf ("%d %d", &n, &t);
	scanf ("%s", str);

	for (int i = 0; i < t; i++)
		for (int j = 0; str[j] != '\0'; j++)
			if (str[j] == 'B' && str[j+1] == 'G') {
				swap (str[j], str[j+1]);
				j++;
			}

	printf ("%s\n", str);

	return 0;
}
