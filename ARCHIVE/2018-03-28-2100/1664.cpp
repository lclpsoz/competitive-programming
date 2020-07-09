#include <bits/stdc++.h>
using namespace std;

int games, words;
char str[50];
set <string> grupo;


int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

int main ()
{
	while (scanf ("%s", str) != EOF) {
		string aux = str;
		for (int i = 0; i < aux.size(); i++) {
			if (tolower(aux[i]) >= 'a' && tolower(aux[i]) <= 'z')
				aux[i] = tolower(aux[i]);
			else
				aux.erase(i, 1);
		}
		if (strcmp (str, "BULLSHIT") == 0) {
			words += grupo.size();
			grupo.clear();
			games++;
			putchar ('\n');
		}
		else if (aux.size()){
			cout << aux << '\n';
			grupo.insert (aux);
		}
	}
	printf ("%d %d\n", words, games);
	int d = mdc (games, words);
	printf ("%d / %d\n", words/d, games/d);

	return 0;
}
