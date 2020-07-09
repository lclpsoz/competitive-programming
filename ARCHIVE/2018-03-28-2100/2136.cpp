#include <bits/stdc++.h>
using namespace std;

set <string> alfaY, alfaN;
char arr[1000];
bool amigo_bool;
string str;
pair<string, int> amigo;

int main ()
{
	amigo.second = 0;
	while (scanf ("%s", arr), strcmp (arr, "FIM")) {
		str = arr;
		scanf ("%s", arr);
		amigo_bool = false;
		if (arr[0] == 'Y')
			amigo_bool = true;
		if (amigo_bool && str.size() > amigo.second) {
			amigo.second = str.size ();
			amigo.first = str;
		}
		if (amigo_bool)
			alfaY.insert (str);
		else
			alfaN.insert (str);
	}
	for (auto p = alfaY.begin(); p != alfaY.end(); p++)
		cout << *p << '\n';
	for (auto p = alfaN.begin(); p != alfaN.end(); p++)
		cout << *p << '\n';
	putchar ('\n');
	printf ("Amigo do Habay:\n");
	cout << amigo.first << '\n';

	return 0;
}
