#include <bits/stdc++.h>
using namespace std;

int i;
char arr[75];
bool ans = true;
bool aux = false;

void func (char c)
{
	if (tolower (arr[i]) != c && !aux)
		ans = false;
	aux = false;
}

int main ()
{
	while (scanf (" %[^\n]", arr) != EOF) {
		int pos = 1;
		aux = false;
		ans = true;
		for (i = 0; i < strlen (arr) && ans; i++) {
			//printf ("%c\n", arr[i]);
			switch (pos) {
				case 1:
					if (arr[i+1] == '-') {
						func ('c');
						pos++;
					}
					else if (i == 0)
						tolower (arr[0]) == 'c' ? aux = true : aux = false;
					break;
				case 2:
					if (arr[i+1] == '-') {
						func ('o');
						pos++;
					}
					else if (arr[i-1] == '-')
						tolower (arr[i]) == 'o' ? aux = true : aux = false;
					break;
				case 3:
					if (arr[i+1] == '-') {
						func ('b');
						pos++;
					}
					else if (arr[i-1] == '-')
						tolower (arr[i]) == 'b' ? aux = true : aux = false;
					break;
				case 4:
					if (arr[i+1] == '-') {
						func ('o');
						pos++;
					}
					else if (arr[i-1] == '-')
						tolower (arr[i]) == 'o' ? aux = true : aux = false;
					break;
				case 5:
					if (arr[i+1] == '\0') {
						func ('l');
						pos++;
					}
					else if (arr[i-1] == '-')
						tolower (arr[i]) == 'l' ? aux = true : aux = false;
					break;
			}
		}
		//printf ("%d %d\n", pos, i);
		if (pos < 6 || !ans)
			printf ("BUG\n");
		else
			printf ("GRACE HOPPER\n");
	}

	return 0;
}
