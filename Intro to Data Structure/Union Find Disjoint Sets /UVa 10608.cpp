/* Topic: Union Find Disjoint Sets
 * Example: UVa 10608 - Friends
 * Find the set with the largest element
 */

#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 30000 + 10
int par[maxn], rnk[maxn], n;

void init(){
    for(int i = 1; i <= n; i ++){
        par[i] = i; rnk[i] = 1;
    }
}

int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}

int unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return 0;
    if(rnk[x] < rnk[y]){
        par[x] = y; rnk[y] += rnk[x];
        return rnk[y];
    }
    par[y] = x; rnk[x] += rnk[y];
    return rnk[x];
}

int main(){
    int t; scanf("%d", &t);
    while (t --) {
        int m, a, b, ans = 1;
        scanf("%d%d", &n, &m);
        init();
        for (int i = 0; i < m; i ++) {
            scanf("%d%d", &a, &b);
            ans = max(ans, unite(a, b));
        }
        printf("%d\n", ans);
    }
    return 0;
}
