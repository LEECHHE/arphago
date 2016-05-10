#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int psum[200005];
int main(){
	int t; scanf("%d",&t);
	for( int cs = 1 ; cs <= t ; ++cs ){
		int n; scanf("%d",&n);
		vector<int> a(n);
		memset(psum,10000,sizeof(psum));
		for( int i = 0 ; i < n ; ++i ){
			scanf("%d",&a[i]);
		}		
		for( int i = 0 ; i < n ; ++i ){
			for( int j = 0 ; j < n ; ++j ){
				int k = a[i]+a[j];
				if( k > 100000 || k < -100000 ) continue;
				psum[k+100000] = min(psum[k+100000],max(i,j));
			//	printf("has %d+%d = %d\n",a[i],a[j],k);
			}
		}
		int ret = 0;
		for( int i = 0 ; i < n ; ++i ){
			for( int j = 0 ; j < i ; ++j ){
				int k = a[i]-a[j];
				if( k < -100000 || k > 100000 ) continue;
				if( psum[k+100000] < i ){
			//		printf("find %d-%d =  %d\n",a[i],a[j],k);
					++ret;
					break;
				}
			}
		}
		printf("Case #%d\n%d\n",cs,ret);
	}
	return 0;
}
