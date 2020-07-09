#include <bits/stdc++.h>
using namespace std;

int n;
int x;
list<int> vec;
long long ans;

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d", &x);
		vec.push_back (x);
	}

	vec.sort();

	int a = vec.front();
	int b = vec.back();
	int qntA, qntB;
	qntA = qntB = 0;
	ans = -1;
	if (a == b) {
		ans = ((long long)(vec.size())*(long long)(vec.size()-1))/2;
		vec.clear ();
	}
	while (!vec.empty() && vec.front() == a) {
		vec.pop_front();
		qntA++;
	}
	while (!vec.empty() && vec.back() == b) {
		vec.pop_back();
		qntB++;
	}
	if (ans == -1) {
		ans = (long long)qntA * qntB;
	}

	printf ("%d %lld\n", abs(a-b), ans);

	return 0;
}
