#include <bits/stdc++.h>
using namespace std;

int n, ans, lst, first;
char str[1010];

bool div_two () {
	if (first > lst)
		return false;

	bool car = false;
	bool ret = false;
	int i = first;
	while (i <= lst) {
		if (str[i] != '0' && !car) {
			ret = true;
			if ((str[i]-'0') % 2 == 1)
				car = true;
			str[i] = ((str[i]-'0')/2)+'0';
		}
		else if (car) {
			if ((str[i]-'0')%2 == 0)
				car = false;
			str[i] = ((str[i]-'0')/2)+'0';
			str[i] += 5;
		}
		i++;
	}
	if (str[first] == '0')
		first++;
	return ret;
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%s", str);
		lst = strlen (str)-1;
		ans = first = 0;
		if ((str[lst] -'0') % 2 == 1)
			ans++;
		while (div_two ()) {
			//printf ("%s %d\n", str, ans);
			if ((str[lst] -'0') % 2 == 1)
				ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
