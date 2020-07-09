#include <bits/stdc++.h>
using namespace std;

int t;

int main ()
{
	scanf ("%d", &t);
	char raw[3], ready[3];
	char fixed[4][3];
	vector<pair<char, char>> ordered;
	while (t--) {
		for (int i = 0; i < 4; i++) {
			scanf ("%s", raw);
			switch (raw[0]) {
				case 'T':
					ready[1] = 'J';
					break;
				case 'J':
					ready[1] = 'K';
					break;
				case 'Q':
					ready[1] = 'L';
					break;
				case 'K':
					ready[1] = 'M';
					break;
				default:
					ready[1] = 'A'+(raw[0]-'0');
			}
			switch (raw[1]) {
				case 'H':
					ready[0] = 'A';
					break;
				case 'C':
					ready[0] = 'B';
					break;
				case 'D':
					ready[0] = 'C';
					break;
				case 'S':
					ready[0] = 'D';
					break;
			}
			ready[2] = '\0';
			strcmp (fixed[i], ready);
			ordered.push_back ({ready[0], ready[1]});
		}
		sort (ordered.begin(), ordered.end());
		if (ordered[0].first == ordered[1].first) {
		} else {
		}
	}

	return 0;
}
