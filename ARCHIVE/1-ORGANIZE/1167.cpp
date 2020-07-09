#include <bits/stdc++.h>
using namespace std;

int n, jmp;
int i;
list < pair <string, int> > names;
char arr[35];

int main ()
{
	while (scanf ("%d", &n), n) {
		for (i = 0; i < n; i++) {
			scanf ("%s %d", arr, &jmp);
			names.push_front ({arr, jmp});
		}
		auto pos = names.end ();
		pos--;
		jmp = pos->second;
		if (names.size() > 1) {
			if (jmp & 1) {
				pos--;
			}
			else
				pos++;
			if (pos == names.end())
				pos = names.begin();
			jmp--;
		}
		while (names.size () > 1) {
			//printf (" %d %lu\n", jmp, names.size());
			// Inverted logic bacause when the element is removed is jmp--
			if (jmp % 2) {
				for (i = 0; i < jmp; i++) {
					pos++;
					if (pos == names.end())
						pos = names.begin();
					//cout << pos->first << '\n';
				}
			}
			else {
				for (i = 0; i < jmp; i++) {
					if (pos == names.begin())
						pos = names.end();
					pos--;
					//cout << "- " << pos->first << '\n';
				}
			}
			auto aux = pos;
			//cout << "   " << pos->first << '\n';
			jmp = pos->second;
			aux = pos;
			aux++;
			if (pos == names.begin() && jmp & 1) {
				aux = names.end();
				aux--;
			}
			else if (aux == names.end() && !(jmp&1))
				aux = names.begin();
			else if (jmp & 1) {
				aux--;
				aux--;
			}
			names.erase (pos);
			pos = aux;
			jmp--;
		}
		pos = names.begin();
		printf ("Vencedor(a): ");
		cout << pos->first << '\n';
		names.clear();
	}
	return 0;
}
