#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

char str[110];

int main ()
{
	scanf ("%s", str);
	int up = 0;
	int down = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] >= 'a') down++;
		else up++;

	if (down >= up) {
		for (int i = 0; str[i] != '\0'; i++)
			putchar (tolower (str[i]));
	} else {
		for (int i = 0; str[i] != '\0'; i++)
			putchar (toupper (str[i]));
	}
	putchar ('\n');

	return 0;
}
