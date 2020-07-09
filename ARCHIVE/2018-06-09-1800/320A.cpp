#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

char str[20];

int main ()
{
	scanf ("%s", str);
	for (int i = 0; str[i] != '\0';) {
		if (str[i] == '1') {
			i++;
			if (str[i] == '4')
				i++;
			if (str[i] == '4')
				i++;
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";


	return 0;
}
