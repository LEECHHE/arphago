#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int TC;
    int test_case;
    
    scanf("%d", &TC);	// cin 사용 가능
    for(test_case = 1; test_case <= TC; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오.
        int n; scanf("%d",&n);
        int b = 2;
        while(1){
            if( b > n ) break;
            int t = n;
            int e = t%b;
            bool success = true;
            t /= b;
            while(t){
                if( t%b != e ){
                    success = false;
                    break;
                }
                t /= b;
            }
            if( success ) break;
            ++b;
        }
        
        // 이 부분에서 정답을 출력하십시오.
        printf("Case #%d\n%d\n", test_case,b);	// cout 사용 가능
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}