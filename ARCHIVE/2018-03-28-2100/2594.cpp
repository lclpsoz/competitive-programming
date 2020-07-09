#include <cstdio>
#include <cstring>

int i;
int n;
char str[140], word[140], *p;

int main ()
{
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		str[0] = ' ';
		word[0] = ' ';
		scanf (" %[^\n] ", str+1);
		scanf (" %[^\n] ", word+1);
		strcat (str, " ");
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
