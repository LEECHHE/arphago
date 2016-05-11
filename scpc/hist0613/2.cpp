#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n;
		scanf("%d", &n);

		vector<int> scores(n);
		for (int i = 0; i < n; i++) 
			scanf("%d", &scores[i]);

		sort(scores.begin(), scores.end());

		int top_score = 0;
		for (int i = 0; i < n; i++) {
			if (scores[i] + n - i > top_score) 
				top_score = scores[i] + n - i;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (scores[i] + n >= top_score)
				++ans;
		}

		printf("Case #%d\n", ti);
		printf("%d\n", ans);
	}

	return 0;
}