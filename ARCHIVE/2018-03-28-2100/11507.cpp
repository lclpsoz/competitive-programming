#include <bits/stdc++.h>
using namespace std;

int i;
int n;
char sig, c;
pair <int, int> ans; //In first: 0 is xy plane, 1 is xz plane. In second:
/**
 * + will grow
 * - will decrease
 * In xy (0):
 * +x 0
 * +y 1
 * -x 2
 * -y 3
 * In xz (1):
 * +x 0
 * +z 1
 * -x 2
 * -z 3
**/

int main ()
{
	while (scanf("%d", &n), n) {
		ans.first = ans.second = 0;
		for (int i = 0; i < n-1; i++) {
			scanf(" %c%c", &sig, &c);
			switch (c) {
				case 'y': if (ans.first == 0 || ans.second == 0 || ans.second == 2) {
							  ans.first = 0;
							  if (sig == '+') {
								  ans.second++;
								  if (ans.second == 4)
									  ans.second = 0;
							  }
							  else {
								  ans.second--;
								  if (ans.second == -1)
								  ans.second = 3;
							  }
						  }
						  break;
				case 'z': if (ans.first == 1 || ans.second == 0 || ans.second == 2) {
							  ans.first = 1;
							  if (sig == '+') {
								  ans.second++;
								  if (ans.second == 4)
									  ans.second = 0;
							  }
							  else {
								  ans.second--;
								  if (ans.second == -1)
								  ans.second = 3;
							  }
						  }
						  break;
			}
		}
		if (ans.second < 2)
			printf ("+");
		else
			printf ("-");

		if (ans.second % 2 == 0)
			printf ("x\n");
		else if (ans.first == 0)
			printf ("y\n");
		else
			printf ("z\n");
	}

	return 0;
}
