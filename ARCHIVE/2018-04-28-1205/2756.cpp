#include <bits/stdc++.h>
using namespace std;

#define pt putchar 

void sp (int n)
{
	while (n--)
		putchar (' ');
}

int main ()
{
	sp (7); putchar ('A'); putchar ('\n');
	sp (6); putchar ('B'); pt (' '); pt ('B'); pt ('\n');
	sp (5); putchar ('C'); sp (3); pt ('C'); pt ('\n');
	sp (4); putchar ('D'); sp (5); pt ('D'); pt ('\n');
	sp (3); putchar ('E'); sp (7); pt ('E'); pt ('\n');
	sp (4); putchar ('D'); sp (5); pt ('D'); pt ('\n');
	sp (5); putchar ('C'); sp (3); pt ('C'); pt ('\n');
	sp (6); putchar ('B'); pt (' '); pt ('B'); pt ('\n');
	sp (7); putchar ('A'); putchar ('\n');

	return 0;
}
