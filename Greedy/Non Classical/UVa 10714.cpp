/* Topic: Greedy
 * Example: UVa 10714 Ants
 * Non Classical Greedy Problem
 */
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 1000000 + 10
int N, M;
int c[maxn];


void solve(){
    int lb = 0, ub = 0;
    for (int i = 0; i < M; i ++) {
        lb = max(lb, min(c[i], N - c[i]));
        ub = max(ub, max(c[i], N - c[i]));
    }
    printf("%d %d\n", lb, ub);
}

int main(){
    int t; scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i ++)
            scanf("%d", &c[i]);
        solve();
    }
    return 0;
}
