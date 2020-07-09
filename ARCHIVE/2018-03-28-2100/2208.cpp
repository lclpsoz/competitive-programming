#include <bits/stdc++.h>
using namespace std;

int main ()
{
	string frst = "0";
	string sec = "1";
	string fib = "10";

	for (int i = 2; i < 20; i++) {
		fib = sec + frst;
		cout << fib << '\n';
		frst = sec;
		sec = fib;
	}

	return 0;
}
