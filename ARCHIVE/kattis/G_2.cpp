#include "bits/stdc++.h"
using namespace std;

// -------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int) (((x%m) + m)%m);
}

// ------

const int N = 2e5 + 10;

int n;
char s[N];
vector<int> ans;
int bitIn[N], bitOut[N];

void add(int bit[], int pos, int val){
	for(int i = pos; i < N; i += (i & -i)){
		bit[i] += val;
	}
}

int sum(int bit[], int pos){
	int ret = 0;
	for(int i = pos; i >= 1; i -= (i & -i)){
		ret += bit[i];
	}
	return ret;
}

int sum(int bit[], int a, int b){
	return sum(bit, b) - sum(bit, a - 1);
}

void pre(){
	for(int i = 1; i < N; i++){
		add(bitOut, i, 1);
	}
}

void addToAns(int pos){
	ans.push_back(pos);
	
	add(bitIn, pos, 1);
	add(bitOut, pos, -1);
	
	printf("%d\n", pos);
}

int main () {
	scanf("%d", &n);
	scanf("%s", s + 1);
	
	pre();
	
	if(s[1] == 'L') addToAns(2);
	else addToAns(1);
	
	int qtdL = 0, qtdR = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == 'L') qtdL++;
		else qtdR++;
	}
	
	for(int i = 1; i < n; i++){
		int pos = ans.back();
		if(s[i] == 'L'){
			// left
			
			qtdL--;
			
			printf("pos = %d, qtdL = %d, qtdR = %d, s[i] = %c\n", pos, qtdL, qtdR, s[i]);
			
			// get the leftest qtd-th free position to the left of pos
			int l = 1, r = pos;
			while(l < r){
				int mid = (l + r)/2;
				if(sum(bitOut, mid, pos) < qtdR) r = mid;
				else l = mid + 1;
			}
			
			assert(l > 1);
			
			pos = l - 1;
			
			printf("pos = %d\n", pos);
			
			// get the leftest qtdL-th free position to the right of 1
			l = 0, r = pos - 1;
			while(l < r){
				int mid = (l + r + 1)/2;
				if(sum(bitIn, 1, mid) < qtdL) l = mid;
				else r = mid - 1;
			}
			
			pos = l + 1;
			
			addToAns(pos);
		}else{
			// right
			
			qtdR--;
			
			printf("pos = %d, qtdL = %d, qtdR = %d, s[i] = %c\n", pos, qtdL, qtdR, s[i]);
			
			// get the leftest qtdL-th free position to the right of pos
			int l = pos, r = n;
			while(l < r){
				int mid = (l + r + 1)/2;
				if(sum(bitOut, pos, mid) < qtdL) l = mid;
				else r = mid - 1;
			}
			
			assert(l < n);
			
			pos = l + 1;
			
			printf("pos = %d\n", pos);
			
			// get the leftest qtdR-th free position to the left of n
			l = pos + 1, r = n + 1;
			while(l < r){
				int mid = (l + r)/2;
				if(sum(bitIn, mid, n) < qtdR) r = mid;
				else l = mid + 1;
			}
			
			pos = l - 1;
			
			addToAns(pos);
		}
	}
	
	return 0;
}