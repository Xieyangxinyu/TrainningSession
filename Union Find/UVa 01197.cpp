/* Topic: Union Find - Count the size of a set
 * Example: UVa 01197 The Suspects
 */
#include <cstdio>
using namespace std;

int n, m;
#define maxn 30000 + 10

int par[maxn], rnk[maxn];

void init(){
    for(int i = 0; i < n; i ++){
        par[i] = i; rnk[i] = 1;
    }
}

int find(int x){
    return x == par[x] ? x : x = find(par[x]);
}

bool same(int x, int y){
    return find(x) == find(y);
}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y)return;
    if(rnk[x] < rnk[y]){
        par[x] = y; rnk[y] += rnk[x];
    }else{
        par[y] = x; rnk[x] += rnk[y];
    }
}

int main(){
    while (scanf("%d%d", &n, &m) && n) {
        init();
        while (m --) {
            int u, a, b;
            scanf("%d", &u);
            for(int i = 0; i < u; i ++){
                if(!i)scanf("%d", &a);
                else {
                    scanf("%d", &b); unite(a, b);
                }
            }
        }
        printf("%d\n", rnk[find(0)]);
    }
    return 0;
}
