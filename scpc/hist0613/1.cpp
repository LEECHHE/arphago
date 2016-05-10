#include <cstdio>
using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n;
		scanf("%d", &n);

		unsigned int ans = 0, x;
		for (int i = 0; i < n; i++) {
			scanf("%u", &x);
			ans ^= x;
		}

		printf("Case #%d\n", ti);
		printf("%u\n", ans);
	}

	return 0;
}