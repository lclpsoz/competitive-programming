#include "stdio.h"
#include "stack"
using namespace std;

int n;
stack<int> pi, mini;
char str[20];

int main () {
	scanf ("%d", &n);
	while (n--) {
		scanf ("%s", str);
		if (str[1] == 'U') {
			int x;
			scanf ("%d", &x);
			pi.push (x);
			if (mini.empty() or x <= mini.top())
				mini.push (x);
		} else if (str[1] == 'O') {
			if (pi.empty())
				printf ("EMPTY\n");
			else {
				if (mini.top() == pi.top())
					mini.pop();
				pi.pop();
			}
		} else {
			if (!mini.empty())
				printf ("%d\n", mini.top());
			else
				printf ("EMPTY\n");
		}
	}

	return 0;
}
