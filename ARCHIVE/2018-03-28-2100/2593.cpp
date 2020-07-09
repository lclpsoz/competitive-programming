#include <bits/stdc++.h>
using namespace std;

int i;
char str[10010];
int m;
char word[55], *p;

int main () {
	str[0] = ' ';
	scanf ("%[^\n]", str+1);
	strcat (str, " ");
	scanf ("%d", &m);
	for (i = 0; i < m; i++) {
		word[0] = ' ';
		scanf ("%s", word+1);
		strcat (word, " ");
		p = strstr (str, word);
		if (p == NULL)
			printf ("-1");
		else {
			printf ("%ld", p-str);
			p = strstr (p+1, word);
			while (p != NULL) {
			printf (" %ld", p-str);
				p = strstr (p+1, word);
			}
		}
		printf ("\n");
	}
	return 0;
}
