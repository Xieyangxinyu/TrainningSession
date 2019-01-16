/* Topic: Dynamic Programming - 0-1 Knapsack
 * Example: UVa 12563 - Jin Ge Jin Qu hao
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int cases; scanf("%d", &cases);
    for(int c = 1; c <= cases; c++){
        int n, t;
        scanf("%d%d", &n, &t);
        int dp[t + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i ++) {
            int song; scanf("%d", &song);
            for (int j = t; j > song; j--)
                dp[j] = max(dp[j], dp[j - song] + (dp[j - song] > 0));
            if(song < t) dp[song] = max(dp[song], 1);
        }
        int res = 0, ans = 0;
        for (int i = t - 1; i; i --)
            if (dp[i] > res) {
                res = dp[i];
                ans = i;
            }
        printf("Case %d: %d %d\n", c, res + 1, ans  + 678);
    }
    return 0;
}
