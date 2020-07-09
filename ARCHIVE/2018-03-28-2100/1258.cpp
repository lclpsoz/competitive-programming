#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair< pair<int, int>, string> tps;

int i;
int n;
//Use binary operations to save each monster in each sector
tps shirts[55];
string name, color, size;

int main ()
{
	int a, b;
	bool test = false;
	while (scanf ("%d ", &n), n) {
		if (test)
			putchar ('\n');
		for (int j = 0; j < n; j++) {
			getline (cin, name);
			cin >> color >> size;
			getchar ();
			if (color[0] == 'b')
				a = 0;
			else
				a = 1;
			switch (size[0]) {
				case 'P': b = 0;
						  break;
				case 'M': b = 1;
						  break;
				case 'G': b = 2;
			}
			shirts[j] = (make_pair(make_pair(a, b), name));
		}
		sort (shirts, shirts+n);
		for (i = 0; i < n; i++) {
			if (!shirts[i].first.first)
				printf ("branco ");
			else
				printf ("vermelho ");
			switch (shirts[i].first.second) {
				case 0: putchar ('P');
						break;
				case 1: putchar ('M');
						break;
				case 2: putchar ('G');
						break;
			}
			cout << " " << shirts[i].second << '\n';
		}
		test = true;
	}
	return 0;
}
