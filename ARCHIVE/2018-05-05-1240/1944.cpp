#include <bits/stdc++.h>
using namespace std;

int n;
stack<string> st;
string str;
char arr[10], arr_inv[10];

int main ()
{
	int ans;
	while (scanf ("%d", &n) != EOF) {
		if (n == 0) break;
		ans = 0;
		while (n--) {
			scanf (" %[^\n]", arr);
			for (int i = 3,j = 0; i >= 0; i--, j+=2)
				arr_inv[i] = arr[j];
			for (int i = 0; i < 4; i++)
				arr[i] = arr_inv[3-i];
			arr[4] = '\0';
			if (st.empty())
				st.push ("FACE");
			// cout << st.top() << " " << arr_inv << '\n';
			if (st.top() == arr_inv) {
				st.pop();
				ans++;
			}
			else
				st.push (arr);

		}
		printf ("%d\n", ans);
		while (!st.empty()) st.pop();
	}

	return 0;
}
