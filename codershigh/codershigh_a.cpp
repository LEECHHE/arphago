#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c, d, e, f, g, h;
        scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
        a += e; b += f; c += g; d += h;
        a = max(a, 1);
        b = max(b, 1);
        c = max(c, 0);
        printf("%d\n", 1 * a + 5 * b + 2 * c + 2 * d);
    }
    return 0;
}