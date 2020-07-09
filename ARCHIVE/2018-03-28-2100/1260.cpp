#include <bits/stdc++.h>
using namespace std;

int i;
int n, total;
map <string, int> trees;
char c, arr[40];
string str;

int main ()
{
	scanf ("%d ", &n);
	for (i = 0; i < n; i++) {
		total = 0;
		c = getchar();
		while (c != '\n' && c != EOF) {
			scanf ("%[^\n]", arr+1);
			arr[0] = c;
			str = arr;
			trees[str]++;
			total++;
			getchar(); //First \n
			c = getchar();
		}
		for (map<string, int>::iterator x = trees.begin(); x != trees.end(); x++) {
			for (char y : x->first)
				putchar (y);
			printf (" %.4lf\n", ((double)x->second / total)*100);
		}
		if (i < n-1)
			putchar ('\n');
		trees.clear();
	}
	return 0;
}
