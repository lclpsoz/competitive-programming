#include <bits/stdc++.h>
using namespace std;

int i;
int n, ans;
set <string> x, y;
char arr[40];
string str;

int main ()
{
	while (scanf ("%d", &n), n) {
		ans = 2; //Invertible.
		for (i = 0; i < n; i++) {
			scanf (" %s -> ", arr);
			str = arr;
			if (x.find(str) == x.end())
				x.insert (str);
			else
				ans = 0; //Not a function.
			scanf ("%s", arr);
			str = arr;
			if (ans && y.find(str) == y.end())
				y.insert (str);
			else if (ans)
				ans = 1; //Not invertible.
		}
		switch (ans) {
			case 0: printf ("Not a function.\n");
					break;
			case 1: printf ("Not invertible.\n");
					break;
			case 2: printf ("Invertible.\n");
					break;
		}
		x.clear();
		y.clear();
	}
	return 0;
}
