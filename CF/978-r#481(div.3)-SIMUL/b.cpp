#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n;
char str[150];

int main ()
{
	scanf ("%d", &n);
	scanf ("%s", str);

	int aux, ans;
	aux = ans = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'x')
			aux++;
		else {
			if (aux >= 3)
				ans += aux-2;
			aux = 0;
		}
	}
	if (aux >= 3) ans += aux-2;

	printf ("%d\n", ans);

	return 0;
}
