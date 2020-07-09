#include <bits/stdc++.h>
using namespace std;

int n, m;
set<set<int>> st;
set<int> aux;

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d", &m);
		aux.clear();
		while (m-- > 1) {
			int x;
			scanf ("%d", &x);
			aux.insert (x);
		}
		//for (int x : aux)
		//	printf ("%d ", x);
		putchar ('\n');
		st.insert (aux);
	}
	printf ("%ld\n", st.size());
	
	return 0;
}
