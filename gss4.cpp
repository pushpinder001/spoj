#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstdio>
#define M 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii > vii;
ll ST[4*sz];
ll a[sz];
void build(ll tl,ll tr,ll p){
	if(tl==tr)
	{
		ST[p]=a[tl];
		return ;
	}
	ll tm=(tl+tr)/2;
	build(tl,tm,2*p);
	build(tm+1,tr,2*p+1);
	ST[p]=ST[2*p]+ST[2*p+1];
}
ll query(ll tl,ll tr,ll l,ll r,ll p){
	if(tr<l||tl>r)
		return 0;
	if(tl>=l&&tr<=r)
		return ST[p];
	ll tm=(tl+tr)/2;
	return query(tl,tm,l,r,2*p)+query(tm+1,tr,l,r,2*p+1);
}
void update(int tl,int tr,int l,int r,int p)
{
	if(l>tr||r<tl)
		return ;
	if((tr-tl+1LL)==ST[p])
		return;
	if(tl==tr)
	{
		ST[p]=sqrt(ST[p]);
		return ;
	}
	ll tm=(tl+tr)/2;
	update(tl,tm,l,r,2*p);
	update(tm+1,tr,l,r,2*p+1);
	ST[p]=ST[2*p]+ST[2*p+1];
}
int main(){
	ll n,m,ii,x,y,t=1;
	while(scanf("%lld" , &n) == 1){
		if(t>1)
			printf("\n");
		printf("Case #%lld:\n",t);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		cin>>m;
		build(1,n,1);
		for(int i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&ii,&x,&y);
			if (x > y) swap(x,y);
			if(ii==0)
			{
				update(1,n,x,y,1);
			}
			else
			{
				printf("%lld\n",query(1,n,x,y,1));
			}
		}
		t++;
	}
	return 0;
}
