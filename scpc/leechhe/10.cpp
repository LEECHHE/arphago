#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> intPair;
typedef long long ll;
vector<intPair> obs;
ll factorial[200001] = { 1};
ll facinv[200001]={1};
const int MOD = 1000000007;
ll dp[2001];
int n,m,k;
ll get_exp(ll x, ll y){
	if( y == 0 ) return 1;
	ll ret = get_exp(x,y>>1);
	ret = (ret*ret)%MOD;
	if( y & 1 ) ret = (ret*x) % MOD;
	return ret;
}
ll cnt(int x, int y){
	return (((factorial[x+y-2]*facinv[x-1])%MOD)*facinv[y-1])%MOD;
}
bool cmp(const intPair& a, const intPair& b){
	if( a.first == b.first ) return a.second < b.second;
	return a.first < b.first;
}
ll solve(int idx){
	ll& ret = dp[idx];
	if( ret != -1 ) return ret;
	int x = obs[idx].first;
	int y = obs[idx].second;

	ret = 0;
	for ( int i = 0 ; i < obs.size() ; ++i ){
		if( obs[i].second > y ) continue;
		if( obs[i].first == x && obs[i].second == y ) break;
		ret = (ret + (solve(i) * cnt(x-obs[i].first+1, y-obs[i].second+1)) )%MOD;
	}
	return ret = (cnt(x,y)-ret+MOD)%MOD;
}
int main(){
	int t; scanf("%d",&t);
	for( int i = 1 ; i <= 200000 ; ++i ){ 
		factorial[i] = (factorial[i-1]*i)%MOD;
		facinv[i] = get_exp(factorial[i],MOD-2);
	}
	for( int cs = 1 ; cs <= t ; ++cs ){
		scanf("%d%d%d",&n,&m,&k);
		memset(dp,-1,sizeof(dp));
		obs = vector<intPair>();
		for( int i = 0 ; i < k ; ++i ){
			int a,b; 
			scanf("%d%d",&a,&b);
			if ( a < 1 || a > n || b < 1 || b > m ) continue;
			obs.push_back(intPair(a,b));
		}
		sort(obs.begin(), obs.end(), cmp);
		obs.push_back(intPair(n,m));
		printf("Case #%d\n%lld\n",cs,solve(obs.size()-1));
	}
	return 0;
}
