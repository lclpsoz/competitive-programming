#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

char str[300];

bool test (int i) {
	if (str[i] == 'W' &&
			str[i+1] == 'U' &&
			str[i+2] == 'B')
		return true;
	return false;
}

int main ()
{
	scanf ("%s", str);
	int word = 0;
	for (int i = 0; str[i] != '\0';i++) {
		if (test (i)) {
			i+=2;
			if (word == 1) word = 2;
		}
		else {
			if (word == 0) word = 1;
			if (word == 2) {
				putchar (' ');
				word = 1;
			}
			putchar (str[i]);
		}
	}
	putchar ('\n');

	return 0;
}
