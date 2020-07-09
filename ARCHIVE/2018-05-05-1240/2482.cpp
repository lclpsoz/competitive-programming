#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

map<string, string> mp;
char arr1[MAXN];
char arr2[MAXN];

int main ()
{
	int n;
	scanf ("%d ", &n);
	while (n--) {
		scanf ("%[^\n]", arr1);
		getchar ();
		scanf ("%[^\n]", arr2);
		getchar ();
		// printf ("%s %s\n", arr1, arr2);
		mp[arr1] = arr2;
	}

	scanf ("%d ", &n);
	while (n--) {
		scanf ("%[^\n]", arr1);
		getchar ();
		scanf ("%[^\n]", arr2);
		getchar ();
		printf ("%s\n", arr1);
		cout << mp[arr2] << "\n\n";
	}

	return 0;
}
