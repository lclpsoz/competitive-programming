#include <bits/stdc++.h>
using namespace std;

char c;
list<char> lst;
list<char>::iterator pos;
bool lado;
int main ()
{
	c = getchar ();
	while (c != EOF) {
		lado = true;
		while (c != '\n') {
			if (c == '[') {
				lado = false;
				pos = lst.begin ();
			}
			else if (c == ']')
				lado = true;
			else {
				if (lado)
					lst.push_back (c);
				else
					lst.insert (pos, c);
			}
			c = getchar ();
		}
		for (auto q = lst.begin (); q != lst.end(); q++)
			putchar (*q);
		lst.clear();
		if (c == '\n')
			putchar ('\n');
		c = getchar();
	}
	return 0;
}
