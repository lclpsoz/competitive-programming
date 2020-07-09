#include<bits/stdc++.h>
#define fi first
#define se second
#define ls rt*2
#define rs rt*2+1
#define pb push_back
#define sc(x) scanf("%d",&x)
#define scc(x,y) scanf("%d%d",&x,&y)
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pln(x) printf("%d\n",x) 
#define CLR(x,y) memset((x),y,sizeof(x))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
//#define debug
using namespace std;
 
typedef long long LL;
typedef pair<int,int> PI;
 
const int inf=0x3f3f3f3f; 
const LL INF=0x3f3f3f3f3f3f3f3f;
//const LL mod=
const int maxn=1e5+5;
char str[maxn];
int len[30],ans[30],tem[30],l,r,n;
void deal(){
	CLR(len,0);
	bool f=1;
	int cnt=1;
	rep(i,1,n-1){
		if(str[i]!=str[i-1]){
			if(f)
				l=cnt,f=0;
			len[str[i-1]-'a']=max(len[str[i-1]-'a'],cnt);
			cnt=0;
		}
		cnt++;
	}
	len[str[n-1]-'a']=max(len[str[n-1]-'a'],cnt);
	r=cnt;
	if(f)
		l=r;
}
int main()
{
	int N;
	sc(N);
	scanf("%s",str);
	n=strlen(str);
	deal();
	rep(i,0,25)
		ans[i]=len[i];
	rep(i,2,N){
		scanf("%s",str);
		n=strlen(str);
		deal();
		rep(i,0,25)
			tem[i]=ans[i]?1:0;
		if(str[0]==str[n-1]){
			int ch=str[0]-'a';
			if(l==n)
				tem[ch]=(ans[ch]+1)*n+ans[ch];
			else
				tem[ch]+=l+r;
		}
		else{
			tem[str[0]-'a']+=l;
			tem[str[n-1]-'a']+=r;
		}
		rep(i,0,25)
			ans[i]=max(tem[i],len[i]);
	}
	int Max=0;
	rep(i,0,25)
		Max=max(Max,ans[i]);
	pln(Max);
}
