#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	if( a < b ){
		ll t = b;
		b = a;
		a = t;
	}
	while(b){
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	int t; scanf("%d",&t);
	for( int cs = 1 ; cs <= t ; ++cs ){
		int m; scanf("%d",&m);
		ll b,c; scanf("%lld%lld",&b,&c);
		ll g = c-b;
		b = c;
		for( int i = 2 ; i < m ; ++i ){
			scanf("%lld",&c);
			g = gcd(g,c-b);
			b = c;
		}
		ll ret = 1;
//		printf("Common gcd : %lld\n",g);
		vector<int> f;
		for ( int factor = 2; g > 1 ; ++factor ){
			if( g % factor ) continue;
			int cnt = 0;
			while(g%factor == 0){
				++cnt;
				g /= factor;
			}
			f.push_back(cnt);
		}
		for( int i = 0 ; i < f.size() ; ++i ){
			ret *= f[i]+1;
		}
		printf("Case #%d\n%lld\n",cs,ret);
	}
	return 0;	
}
