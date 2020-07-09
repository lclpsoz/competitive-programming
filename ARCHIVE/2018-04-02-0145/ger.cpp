#include <bits/stdc++.h>
using namespace std;

int main ()
{
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++)
			if (rand()%2)
				putchar ('1');
			else
				putchar ('0');
		putchar ('\n');
	}

	return 0;
}
