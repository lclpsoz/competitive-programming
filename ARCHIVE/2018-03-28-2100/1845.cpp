#include <bits/stdc++.h>
using namespace std;

char c, arr[] = "zjpsvbxfZJPSVBXF", str[2], aux;
bool test;

int main ()
{
	str[1] = '\0';
	c = getchar();
	while (c != EOF) {
		// Found
		str[0] = c;
		if (strstr (arr, str) != NULL) {
			aux = c;
			while (strstr (arr, str) != NULL) {
				c = getchar();
				str[0] = c;
			}
			if (aux >= 'A' && aux <= 'Z')
				putchar ('F');
			else
				putchar ('f');
		}
		else {
			putchar (c);
			c = getchar();
		}
	}
	return 0;
}
