#include <cstdio>
#include <cmath>
using namespace std;

const double PI = 3.14159265;
const int scores[] = { 6, 13, 13, 4, 4, 18, 18, 1, 1, 20, 20, 5, 5, 12, 12, 9, 9, 14, 14, 11, 11, 8, 8, 16, 16, 7, 7, 19, 19, 3, 3, 17, 17, 2, 2, 15, 15, 10, 10, 6 };

int main(void) {
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        int a, b, c, d, e;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

        int aa = a * a;
        int bb = b * b;
        int cc = c * c;
        int dd = d * d;
        int ee = e * e;

        int n;
        scanf("%d", &n);

        int my_score = 0;

        for (int di = 0; di < n; di++) {
            int x, y;
            scanf("%d %d", &x, &y);

            double theta_rad = atan((double)y / x);
            if (x >= 0 && y >= 0);
            else if (x >= 0 && y < 0) theta_rad = 2 * PI + theta_rad;
            else if (x < 0 && y >= 0) theta_rad = PI + theta_rad;
            else theta_rad = PI + theta_rad;
            double theta_deg = theta_rad * 180.0 / PI;
            int si = (int)(theta_deg / 9.0);
            int rr = x * x + y * y;
            if (rr < aa) my_score += 50; // BULL
            else if (rr > ee) my_score += 0; // OUTBOARD
            else if (bb < rr && rr < cc) my_score += 3 * scores[si]; // TRIPLE
            else if (dd < rr && rr < ee) my_score += 2 * scores[si]; // DOUBLE
            else my_score += scores[si]; // SINGLE
        }

        printf("Case #%d\n", ti);
        printf("%d\n", my_score);
    }
    return 0;
}