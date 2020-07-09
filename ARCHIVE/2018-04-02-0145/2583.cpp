#include <bits/stdc++.h>
using namespace std;

const int M = 1e4;

int t, n;
char arr1[M], arr2[M];
set<string> st;

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		while (n--) {
			scanf ("%s %s", arr1, arr2);
			string str = arr1;
			if (strcmp (arr2, "chirrin") == 0)
				st.insert (str);
			else if (strcmp (arr2, "chirrion") == 0)
				st.erase (str);
		}
		printf ("TOTAL\n");
		for (string str : st)
			cout << str << '\n';
		st.clear ();
	}

	return 0;
}
