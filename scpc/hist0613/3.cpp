#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n, k;
		scanf("%d %d", &n, &k);

		vector<int> scores(n);
		for (int i = 0; i < n; i++) 
			scanf("%d", &scores[i]);

		sort(scores.rbegin(), scores.rend());

		int ans = 0;
		for (int i = 0; i < k; i++)
			ans += scores[i];

		printf("Case #%d\n", ti);
		printf("%d\n", ans);
	}

	return 0;
}