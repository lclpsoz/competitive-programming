#include <bits/stdc++.h>
using namespace std;

int main (){

	int note = 0, ans = 0;
	char c;

	c = getchar();
	while (c != '*'){

		switch (c){

			case '/':
				if (note == 64) ans++;
				note = 0;
				break;

			case 'W': note += 64; break;
			case 'H': note += 32; break;
			case 'Q': note += 16; break;
			case 'E': note += 8; break;
			case 'S': note += 4; break;
			case 'T': note += 2; break;
			case 'X': note += 1; break;

			case '\n':
				printf("%d\n", ans);
				ans = 0;
				break;

		}

		c = getchar();

	}

	return 0;
}
