#include <bits/stdc++.h>
using namespace std;

int n, aux3;
vector < tuple <string, string, int> > stu;
string aux1, aux2;

bool ord (tuple <string, string, int> a, tuple <string, string, int> b)
{
	if (get<2>(a) < get<2>(b))
		return true;
	else if (get<2>(a) > get <2>(b))
		return false;
	else if (get<1>(a) < get<1>(b))
		return true;
	else if (get<1>(a) > get<1>(b))
		return false;
	else if (get<0>(a) <= get<0>(b))
		return true;
	else
		return false;
}

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			cin >> aux1;
			cin >> aux2;
			scanf ("%d", &aux3);
			stu.push_back (make_tuple (aux1, aux2, aux3));
		}
		sort (stu.begin (), stu.end (), ord);
		for (int i = 0; i < stu.size(); i++)
			cout << get<0>(stu[i]) << '\n';
			//cout << get<0>(stu[i]) << " " << get<1>(stu[i]) << " " << get<2>(stu[i]) << '\n';
		stu.clear ();
	}

	return 0;
}
