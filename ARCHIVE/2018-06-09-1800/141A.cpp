#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

char str[110];
int arr[30];

int main ()
{
	for (int i = 0; i < 2; i++) {
		scanf ("%s", str);
		for (int i = 0; str[i] != '\0'; i++)
			arr[str[i]-'A']++;
	}
	scanf ("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
		arr[str[i]-'A']--;

	for (int i = 0; i < 30; i++)
		if (arr[i] != 0) {
			printf ("NO\n"); return 0;
		}

	printf ("YES\n");

	return 0;
}
