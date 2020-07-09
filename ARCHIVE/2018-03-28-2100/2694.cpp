#include <cstdio>
using namespace std;

int main () {
	int n, i, a, b, c;
	char str[20];
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		scanf ("%s", str);
		for (int j = 0; j < 14; j++) {
			if (str[j] < '0' || str[j] > '9')
				str[j] = ' ';
		}
		sscanf (str, " %d %d %d", &a, &b, &c);
		printf ("%d\n", a+b+c);
	}
	return 0;
}
