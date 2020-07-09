#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int ans;
bool arr[30];

int main ()
{
	char str[105];
	scanf ("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
		if (!arr[str[i]-'a']) {
			ans++;
			arr[str[i]-'a'] = true;
		}

	printf ("%s", ans&1 ? "IGNORE HIM\n" : "CHAT WITH HER!\n");

	return 0;
}
