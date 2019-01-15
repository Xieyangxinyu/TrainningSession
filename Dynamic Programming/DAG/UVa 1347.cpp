/* Topic: Dynamic Programming - DAG
 * Example: UVa 1347 - Tour
 * Think of this problem as letting two people travelling in non-overlapping routines
 * dp[i][j] where i is the position of the person who is at the front and j is the position of the other person who is currently behind
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 1000 + 5
double points[maxn][2];
double dp[maxn][maxn];

double dis(int a, int b){
    return sqrt(pow(points[a][0] - points[b][0], 2) + pow(points[a][1] - points[b][1], 2));
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i ++)
            scanf("%lf%lf", &points[i][0], &points[i][1]);
        memset(dp, 127, sizeof(dp));
        double res = dp[0][0];
        dp[1][0] = dis(0, 1);
        for (int i = 2; i < n; i ++)
            for (int j = 0; j < i - 1; j ++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + dis(i - 1, i));
                dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + dis(j, i));
            }
        for (int i = 0; i < n - 1; i ++)
            res = min(res, dp[n - 1][i] + dis(i, n - 1));
        printf("%.2lf\n", res);
    }
}
