#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int i, j;
char str[MAXN], ans[MAXN];

int main (){

	while (scanf("%s", str) != EOF){

		for (i = j = 0; str[i] != '\0'; i++){

			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*' || str[i] == '#'){

				ans[j++] = str[i];
				continue;

			}
			else if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';

			if (str[i] >= 'A' & str[i] <= 'Z'){

				switch ((int) ((str[i]-'A') / 3)){

					case 0: ans[j++] = '2'; break;
					case 1: ans[j++] = '3'; break;
					case 2: ans[j++] = '4'; break;
					case 3: ans[j++] = '5'; break;
					case 4: ans[j++] = '6'; break;

				}
				if ((str[i]-'A') / 3 >= 5){

					if ((str[i]-'A') < 19) ans[j++] = '7';
					else if ((str[i]-'A') < 22) ans[j++] = '8';
					else ans[j++] = '9';

				}
			}
		}

		ans[j] = '\0';
		printf("%s\n", ans);
	}

	return 0;
}
