#include <bits/stdc++.h>
using namespace std;
 
/*
SOURCE: ICPC South American Regionals 2019
ONLINE JUDGE: URI Online Judge
LINK: https://www.urionlinejudge.com.br/judge/pt/problems/view/2973
STATUS: Not submitted
*/
 
 
int timeIsEnough(int * arr, int arraySize, int numOfPersons, int eatRate, int maxTime) {
  long long int cap = maxTime * 1LL * eatRate, eat = 0;  
  int playersDown = 0, index = 0;
 
  while (index < arraySize && playersDown < numOfPersons) {
    eat += arr[index];
 
    if (eat > cap) {
      eat = 0;
      playersDown++;
    }
    else {
      index++;  
    }
  }
 
  return (index >= arraySize && playersDown < numOfPersons) ? 1 : 0;
}
 
int main() {
	int numOfSacks, numOfPersons, eatRate, answer, sacks[101000];
	long long int minimumTime, maximumTime, pivot;
    cin >> numOfSacks >> numOfPersons >> eatRate;
 
    for (int i = 0; i < numOfSacks; i++)
        cin >> sacks[i];
 
    minimumTime = 1;
    maximumTime = 1e9 + 100;
 
    while (minimumTime < maximumTime) {
 
        pivot = (minimumTime + maximumTime) / 2;
 
        // Time was enough. Let's decrement time...
        if (timeIsEnough(sacks, numOfSacks, numOfPersons, eatRate, pivot)) {
            maximumTime = pivot;
        }
 
        // Time was not enough. Increment time
        else {
            minimumTime = pivot + 1;
        }
    }
 
    cout << minimumTime << endl;
}