#include <bits/stdc++.h>
using namespace std;

#define sec second
typedef pair<int,pair<int,int>> piii;

int x;
int n, m;
priority_queue<piii, vector<piii>, greater<piii>> cashiers;
queue<int> clients;
piii aux;

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		cashiers.push ({0, {i, x}});
	}
	for (int i = 0; i < m; i++) {
		scanf ("%d", &x);
		clients.push (x);
	}
	while (!clients.empty ()) {
		aux = cashiers.top ();
		cashiers.pop ();
		aux.first += clients.front () * aux.sec.sec;
		cashiers.push (aux);
		clients.pop ();
	}

	while (!cashiers.empty ()) {
		aux = cashiers.top ();
		cashiers.pop ();
	}
	printf ("%d\n", aux.first);


	return 0;
}
