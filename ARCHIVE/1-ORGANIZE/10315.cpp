#include <bits/stdc++.h>
using namespace std;

char arr[50];
vector<int> b, w;

int card_val (char c)
{
	int x;
	switch (c) {
		case 'T': x = 10;
				  break;
		case 'J': x = 11;
				  break;
		case 'Q': x = 12;
				  break;
		case 'K': x = 13;
				  break;
		case 'A': x = 14;
				  break;
		default: x = c-'0';
	}
	return x;
}

// 1 if black wins, 2 if white wins.
// 0 TIE.
int card_high ()
{
	for (int i = 0; i < 5; i++) {
		if (b[i] > w[i])
			return 1;
		else if (b[i] < w[i])
			return 2;
	}
	return 0;
}

pair <int, int> repB[6];
pair <int, int> repW[6];
int main ()
{
	while (scanf (" %[^\n]", arr) != EOF) {
		pair <bool, bool> suit = {true, true};
		pair <bool, bool> straight = {true, true};
		for (int i = 0; i < 6; i++) {
			repB[i].first = 0;
			repB[i].second = 0;
			repW[i].first = 0;
			repW[i].second = 0;
		}
		b.clear ();
		w.clear ();
		char c;
		int x;

		for (int i = 0; i < 13; i+=3) {
			b.push_back (card_val (arr[i]));
			if (i == 0)
				c = arr[i+1];
			else if (arr[i+1] != c)
				suit.first = false;
		}
		for (int i = 15; i <= 28; i+=3) {
			w.push_back (card_val (arr[i]));
			if (i == 15)
				c = arr[i+1];
			else if (arr[i+1] != c)
				suit.second = false;
		}
		sort (b.begin (), b.end (), greater<int>());
		sort (w.begin (), w.end (), greater<int>());

		// Count amount of repeted
		int actB = b[0];
		int actW = w[0];
		int qntB = 1;
		int qntW = 1;
		for (int i = 1; i < 5; i++) {
			if (b[i] == actB)
				qntB++;
			else {
				if (qntB == 2 && repB[qntB].first)
					repB[qntB].second = max (repB[qntB].second, actB);
				else
					repB[qntB].first = max (repB[qntB].first, actB);
				qntB = 1;
				actB = b[i];
			}
			if (w[i] == actW)
				qntW++;
			else {
				if (qntW == 2 && repW[qntW].first)
					repW[qntW].second = max (repW[qntW].second, actW);
				else
					repW[qntW].first = max (repW[qntW].first, actW);
				qntW = 1;
				actW = w[i];
			}
		}
		if (qntB == 2 && repB[qntB].first)
			repB[qntB].second = max (repB[qntB].second, actB);
		else
			repB[qntB].first = max (repB[qntB].first, actB);
		if (qntW == 2 && repW[qntW].first)
			repW[qntW].second = max (repW[qntW].second, actW);
		else
			repW[qntW].first = max (repW[qntW].first, actW);
		if (repB[5].first)
			repB[4].first = repB[5].first;
		if (repW[5].first)
			repW[4].first = repW[5].first;

		// Keep biggest pair (if two) on first
		if (repB[2].second && repB[2].second > repB[2].first)
			swap (repB[2].first, repB[2].second);
		if (repW[2].second && repW[2].second > repW[2].first)
			swap (repW[2].first, repW[2].second);

		for (int i = 0; i < 4; i++) {
			if (b[i] != b[i+1]+1)
				straight.first = false;
			if (w[i] != w[i+1]+1)
				straight.second = false;
		}


		/*printf ("stra: %d %d\n", straight.first, straight.second);
		printf ("suit: %d %d\n", suit.first, suit.second);
		printf ("repB:\n");
		for (int i = 1; i < 6; i++)
			printf ("%d %d, ", repB[i].first, repB[i].second);
		printf ("\nrepW:\n");
		for (int i = 1; i < 6; i++)
			printf ("%d %d, ", repW[i].first, repW[i].second);
		putchar ('\n');*/
		// Two Straight Flush
		if (suit.first && suit.second && straight.first && straight.second) {
			if (b[0] > w[0])
				printf ("Black wins.\n");
			else if (b[0] < w[0])
				printf ("White wins.\n");
			else
				printf ("Tie.\n");
		}
		// One Straight Flush
		else if (suit.first && straight.first)
			printf ("Black wins.\n");
		else if (suit.second && straight.second)
			printf ("White wins.\n");
		// Two Four of a kind
		else if (repB[4].first && repW[4].first) {
			if (b[2] > w[2])
				printf ("Black wins.\n");
			else if (b[2] < w[2])
				printf ("White wins.\n");
			else
				printf ("Tie.\n");
		}
		// One Four of a kind
		else if (repB[4].first)
			printf ("Black wins.\n");
		else if (repW[4].first)
			printf ("White wins.\n");
		// Two Full House
		else if (repB[3].first && repB[2].first && repW[3].first && repW[2].first) {
			if (repB[3].first > repW[3].first)
				printf ("Black wins.\n");
			else if (repB[3].first < repW[3].first)
				printf ("White wins.\n");
			else
				printf ("Tie.\n");
		}
		// One Full House
		else if (repB[3].first && repB[2].first)
			printf ("Black wins.\n");
		else if (repW[3].first && repW[2].first)
			printf ("White wins.\n");
		// Two Flush
		else if (suit.first && suit.second) {
			switch (card_high ()) {
				case 1:	printf ("Black wins.\n");
						break;
				case 2:	printf ("White wins.\n");
						break;
				case 0:	printf ("Tie.\n");
			}
		}
		// One Flush
		else if (suit.first)
			printf ("Black wins.\n");
		else if (suit.second)
			printf ("White wins.\n");
		// Two Straight
		else if (straight.first && straight.second) {
			if (b[0] > w[0])
				printf ("Black wins.\n");
			else if (b[0] < w[0])
				printf ("White wins.\n");
			else
				printf ("Tie.\n");
		}
		// One Straight
		else if (straight.first)
			printf ("Black wins.\n");
		else if (straight.second)
			printf ("White wins.\n");
		// Two 'Three of a Kind'
		else if (repB[3].first && repW[3].first) {
			if (repB[3].first > repW[3].first)
				printf ("Black wins.\n");
			else if (repB[3].first < repW[3].first)
				printf ("White wins.\n");
			else
				printf ("Tie.\n");
		}
		// One 'Three of a Kind'
		else if (repB[3].first)
			printf ("Black wins.\n");
		else if (repW[3].first)
			printf ("White wins.\n");
		// Two 'Two Pairs'
		else if (repB[2].first && repB[2].second && repW[2].first && repW[2].second) {
			if (repB[2].first > repW[2].first)
				printf ("Black wins.\n");
			else if (repB[2].first < repW[2].first)
				printf ("White wins.\n");
			else if (repB[2].second > repW[2].second)
				printf ("Black wins.\n");
			else if (repB[2].second < repW[2].second)
				printf ("White wins.\n");
			else {
				switch (card_high ()) {
					case 1:	printf ("Black wins.\n");
							break;
					case 2:	printf ("White wins.\n");
							break;
					case 0:	printf ("Tie.\n");
				}
			}
		}
		// One 'Two Pairs'
		else if (repB[2].first && repB[2].second)
			printf ("Black wins.\n");
		else if (repW[2].first && repB[2].second)
			printf ("White wins.\n");
		// Two 'One Pair'
		else if (repB[2].first && repW[2].first) {
			if (repB[2].first > repW[2].first)
				printf ("Black wins.\n");
			else if (repB[2].first < repW[2].first)
				printf ("White wins.\n");
			else {
				switch (card_high ()) {
					case 1:	printf ("Black wins.\n");
							break;
					case 2:	printf ("White wins.\n");
							break;
					case 0:	printf ("Tie.\n");
				}
			}
		}
		// One 'One Pair'
		else if (repB[2].first)
			printf ("Black wins.\n");
		else if (repW[2].first)
			printf ("White wins.\n");
		// High Card
		else {
			switch (card_high ()) {
				case 1:	printf ("Black wins.\n");
						break;
				case 2:	printf ("White wins.\n");
						break;
				case 0:	printf ("Tie.\n");
			}
		}
		// putchar ('\n');

	}

	return 0;
}
