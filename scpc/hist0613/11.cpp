#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        int n;
        scanf("%d", &n);

        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        int k;
        scanf("%d", &k);

        int ans = 0;
        for (int i = 0; i + 1 <= n; i++) {
            if (arr[i + 1] - arr[i] > k) {
                ans = -1;
                break;
            }
        }
        if (ans == -1) {
            printf("Case #%d\n", ti);
            printf("-1\n");
            continue;
        }

        int curr = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] > curr + k) {
                curr = arr[i - 1];
                ++ans;
            }
        }
        ++ans;

        printf("Case #%d\n", ti);
        printf("%d\n", ans);
    }
    return 0;
}