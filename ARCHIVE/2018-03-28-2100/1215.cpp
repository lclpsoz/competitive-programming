#include <bits/stdc++.h>
using namespace std;

int i, j;
char lin[300], str1[300];
string str2;
set <string> dict;

int main ()
{
	while (scanf (" %[^\n]", lin) != EOF) {
		i = 0;
		while (lin[i] != '\0') {
			j = 0;
			while ((lin[i] >= 'a' && lin[i] <= 'z') || (lin[i] >= 'A' && lin[i] <= 'Z'))
				str1[j++] = tolower (lin[i++]);
			str1[j] = '\0';
			str2 = str1;
			if (j)
				dict.insert (str2);
			while (lin[i] != '\0' && !((lin[i] >= 'a' && lin[i] <= 'z') || (lin[i] >= 'A' && lin[i] <= 'Z')))
				i++;
		}
	}
	for (set<string>::iterator p = dict.begin(); p != dict.end(); p++)
		cout << *p << '\n';

	return 0;
}
