#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}

int main ()
{
	int a, b;
	stack<int> vals;
	while (scanf ("%d %d", &a, &b) != EOF) {
		vals.push (mdc (a, b));
		if (vals.top() > 5)
			printf ("Noel\n");
		else
			printf ("Gnomos\n");
	}
	while (!vals.empty()) {
		printf ("%d ", vals.top());
		vals.pop();
	}
	putchar ('\n');

	return 0;
}
