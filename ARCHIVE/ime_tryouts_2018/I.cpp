#include <bits/stdc++.h>
using namespace std;

// ------------
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
	return (int)(((x%m) + m)%m);
}

// ------------

const int MAXP = 1010;

int sz[3];
struct point{
	int x, y;
	
	point operator - (point b){
		return {x - b.x, y - b.y};
	}
	
} pol[3][MAXP];
ll sum[3];

ll cross(point a, point b){
	return a.x*1LL*b.y - a.y*1LL*b.x;
}

ll cross(point a, point b, point c){
	return cross(b - a, c - b);
}

string ans[] = {"Sheena", "Rose", "Maria"};

int main(){
	scanf("%d %d %d", &sz[0], &sz[1], &sz[2]);
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < sz[i]; j++){
			scanf("%d %d", &pol[i][j].x, &pol[i][j].y);
		}
		for(int j = 1; j + 1 < sz[i]; j++){
			sum[i] += abs(cross(pol[i][0], pol[i][j], pol[i][j + 1]));
		}
	}
	
	int n;
	scanf("%d", &n);
	while(n--){
		point p;
		scanf("%d %d", &p.x, &p.y);
		
		for(int i = 0; i < 4; i++){
			if(i == 3){
				printf("Outside\n");
				break;
			}
			
			ll cur = 0;
			for(int j = 0; j < sz[i]; j++){
				cur += abs(cross(p, pol[i][j], pol[i][(j + 1)%sz[i]]));
			}
			if(cur == sum[i]){
				printf("%s\n", ans[i].c_str());
				break;
			}
		}
	}
	

	return 0;
}