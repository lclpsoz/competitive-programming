#include <bits/stdc++.h>
using namespace std;

stack <int> resistors;
int aux, x, size;
char str[350], c;

int main ()
{
	while (scanf("%s", &str) != EOF) {
		size = strlen (str);
		for (i = 0; i < size; i++) {
			switch (str[i]) {
				case '-': resistors.push (-1);
						  break;
				case '|': resistors.push (-2);
						  break;
				case '(': resistors.push (-3);
						  break;
				default:  sscanf(&str[i], "%d", &x);
						  if (resistors.top () == -1) {
							  resistors.pop ();
							  x += resistors.top();
							  resistors.push (x);
						  }
						  else if (resistors.top () == -2) {
							  resistors.pop ();
							  aux = x;
							  x *= resistors.top ();
							  x /= (resistors.top () + aux);
						  }
			}

		}
		printf("%d\n", resistors.top());
	}
	return 0;
}
