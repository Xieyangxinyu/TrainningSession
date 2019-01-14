/* Topic: Dynamic Programming - DAG
 * Example: UVa 437 - The Tower of Babylon
 * Do not use dp[length][width] for memoization, since variables length and width can be arbitrarily large
 * Instead, use dp[index][k] where index indicates which block it is referencing and k indicates which edge is put as the height
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i ++)
#define maxn 30 + 2
int block[maxn][3];
int dp[maxn][3];
int n, res;

void square(int* sq, int idx, int k){
    int cnt = 0;
    rep(i, 0, 3)
        if (i != k)
            sq[cnt ++] = block[idx][i];
}

bool comp(int idx_1, int k_1, int idx_2, int k_2){
    int first[2], second[2];
    square(first, idx_1, k_1);
    square(second, idx_2, k_2);
    return (first[0] < second[0] && first[1] < second[1]) || (first[1] < second[0] && first[0] < second[1]);
}

int _dp(int idx, int k){
    if (dp[idx][k]) return dp[idx][k];
    dp[idx][k] = block[idx][k];
    rep(i, 0, n)
        rep(j, 0, 3)
            if (comp(idx, k, i, j))
                dp[idx][k] = max(dp[idx][k], _dp(i, j) + block[idx][k]);
            else break;
    return dp[idx][k];
}

int main(){
    int t = 1;
    while (~scanf("%d", &n) && n) {
        memset(dp, 0, sizeof(dp));
        res = 0;
        rep(i, 0, n){
            rep(j, 0, 3)
                scanf("%d", &block[i][j]);
            sort(block[i], block[i] + 3);
        }
        rep(i, 0, n)
            rep(j, 0, 3)
                res = max(res, _dp(i,j));
        printf("Case %d: maximum height = %d\n", t ++, res);
    }
    return 0;
}
