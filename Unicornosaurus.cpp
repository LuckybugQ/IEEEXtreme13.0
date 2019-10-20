#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const ll inf=1e18;
const int maxn=1e5+10;
const int maxm=100+10;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

struct node{
    int l,r;
    ll val;

    friend bool operator<(node a,node b){
        if(a.r==b.r) return a.l<b.l;
        return a.r<b.r;
    }

}a[maxn];

ll tree[maxn<<2];

void pushup(int rt)
{
    tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}

void build(int l,int r,int rt)
{
    if(l==r){
        tree[rt]=inf;
        return ;
    }

    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int pos,ll c,int l,int r,int rt)
{
    if(l==r){
        tree[rt]=min(tree[rt],c);
        return ;
    }

    int m=(l+r)>>1;
    if(pos<=m) update(pos,c,lson);
    if(pos> m) update(pos,c,rson);
    pushup(rt);
}

ll query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R){
         return tree[rt];
    }

    int m=(l+r)>>1;
    ll ret=inf;
    if(L<=m) ret=min(ret,query(L,R,lson));
    if(R> m) ret=min(ret,query(L,R,rson));
    return ret;
}

int main()
{
    int N,M,S;
    cin>>M>>N>>S;
    
    int L = S;
	int R = 0;
    for(int i=1;i<=M;i++){
    	int l,r;
    	cin>>l>>r;
    	if(l<L) L=l;
    	if(r>R) R=r;
	}
	//cout<<L<<" "<<R<<endl;
    for(int i=1;i<=N;i++){
        cin>>a[i].l>>a[i].r>>a[i].val;
        a[i].l+=2,a[i].r+=2;
    }
    L+=2,R+=2;
    sort(a+1,a+1+N);
    build(1,maxn,1);
    update(L-1,0,1,maxn,1);
    for(int i=1;i<=N;i++){
        ll cnt=query(a[i].l-1,a[i].r,1,maxn,1);
        cnt+=a[i].val;
        update(a[i].r,cnt,1,maxn,1);
    }
    ll ans=query(R,a[N].r,1,maxn,1);
    if(ans<inf) cout<<ans<<endl;
    else cout<<"-1"<<endl;
}