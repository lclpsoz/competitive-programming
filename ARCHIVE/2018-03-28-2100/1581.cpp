#include <bits/stdc++.h>
using namespace std;

int t, n;
string str, bef;
bool ans;
int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		ans = true;
		scanf ("%d", &n);
		cin >> bef;
		for (int j = 1; j < n; j++) {
			cin >> str;
			if (str != bef)
				ans = false;
			bef = str;
		}
		if (ans)
			for (char c : str) putchar (c);
		else
			printf ("ingles");
		putchar ('\n');
	}

	return 0;
}
