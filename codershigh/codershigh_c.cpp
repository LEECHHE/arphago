#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    int x;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x == i) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1000000007 << endl;
    return 0;
}