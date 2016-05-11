#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int abs(int a){ return a < 0 ? -a : a; }
int seq[100005];
int dist[100005];
int solve1(int idx){
	if( dist[idx] == 0 ) return 0;
	return dist[idx] = min(seq[idx],solve1(idx+1)+1);
}
int solve2(int idx){
	if ( dist[idx] == 0 ) return 0;
	return dist[idx] = min(dist[idx],solve2(idx-1)+1);
}
int main(){
	int t; scanf("%d",&t);
	for( int cs = 1 ; cs <= t ; ++cs ){
		int n; scanf("%d",&n);
		memset(seq, 0, sizeof(seq));
		for( int i = 1 ; i <= n ; ++i ){
			scanf("%d",&seq[i]);
		}
		memcpy(dist,seq,sizeof(seq));
		solve1(1);
		solve2(n);
		int ret = 0;
		for( int i = 1 ; i <= n ; ++i ){
			ret = max(ret, dist[i]);
		}
		printf("Case #%d\n%d\n",cs,ret);
	}
	return 0;
}
