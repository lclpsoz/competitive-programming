#include<bits/stdc++.h>
using namespace std;

// ----------------
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

// ----------------

ll get(int n){
	ll ret = n;
	while(n){
		int d = n%10;
		ret = ret*10 + d;
		n /= 10;
	}
	return ret;
}

ll get_odd(int n, int x){
	ll ret = n*10 + x;
	while(n){
		int d = n%10;
		ret = ret*10 + d;
		n /= 10;
	}
	return ret;
}

int main () {
	int q;
	scanf("%d", &q);
	while(q--){
		ll a, b;
		scanf("%lld %lld", &a, &b);
		
		ll qtd = 0, x = 1e9, y = -1e9;
		
		// de tamanho par
		
		// calcula o primeiro
		int l = 1, r = 9999;
		while(l < r){
			int mid = (l + r)/2;
			if(get(mid) >= a) r = mid;
			else l = mid + 1;
		}
		
		int par_x = l;
		
		if(get(par_x) <= b){
			// calcula o ultimo
			l = 1, r = 9999;
			while(l < r){
				int mid = (l + r + 1)/2;
				if(get(mid) <= b) l = mid;
				else r = mid - 1;
			}
			
			int par_y = l;
			
			qtd = par_y - par_x + 1, x = get(par_x), y = get(par_y);
		}
		
		
		// de tamanho impar
		
		// calcula o primeiro
		l = 0, r = 9999;
		while(l < r){
			int mid = (l + r)/2;
			
			bool ok = false;
			for(int i = 0; i < 10; i++){
				if(get_odd(mid, i) >= a){
					r = mid;
					ok = true;
					break;
				}
			}
			if(!ok) l = mid + 1;
		}
		
		int impar_x = l;
		
		
		if(get_odd(impar_x, 0) <= b){
			// calcula o ultimo
			l = 0, r = 9999;
			while(l < r){
				int mid = (l + r + 1)/2;
				
				bool ok = false;
				for(int i = 0; i < 10; i++){
					if(get_odd(mid, i) <= b){
						l = mid;
						ok = true;
						break;
					}
				}
				if(!ok) r = mid - 1;
			}
			
			int impar_y = l;
			
			int dx = -1, dy = -1;
			
			for(int i = 0; i < 10; i++){
				if(get_odd(impar_x, i) >= a){
					dx = i;
					break;
				}
			}
			
			for(int i = 9; i >= 0; i--){
				if(get_odd(impar_y, i) <= b){
					dy = i;
					break;
				}
			}
			
			if(dx != -1 && dy != -1){
				x = min(x, get_odd(impar_x, dx));
				y = max(y, get_odd(impar_y, dy));
				
				impar_x = impar_x*10 + dx;
				impar_y = impar_y*10 + dy;
				
				qtd += impar_y - impar_x + 1;
			}
		}
		
		if(qtd == 0) printf("0 -1 -1\n");
		else printf("%lld %lld %lld\n", qtd, x, y);
		
	}
	
	return 0;
}
