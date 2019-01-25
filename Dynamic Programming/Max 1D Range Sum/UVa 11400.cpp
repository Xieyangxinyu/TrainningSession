/* Topic: Max 1D Range Sum 
 * Example: UVa 11400 - Lighting System Design
 */

#include <cstdio>
#include <algorithm>
using namespace std;

int const maxn = 1000 + 5;

struct lamp{
    int v,k,c,l;
    bool operator < (const lamp &A) const{
        return v < A.v;
    }
}lamps[maxn];

int cost[maxn], num[maxn];

int main(){
    int n;
    while (scanf("%d\n", &n) && n) {
        for (int i = 0; i < n; i ++)
            scanf("%d%d%d%d", &lamps[i].v, &lamps[i].k, &lamps[i].c, &lamps[i].l);
        sort(lamps, lamps + n);
        cost[0] = lamps[0].k + lamps[0].c * lamps[0].l;
        num[0] = lamps[0].l;
        for (int i = 0; i < n; i ++){
            num[i] = num[i - 1] + lamps[i].l;
            cost[i] = lamps[i].k + num[i] * lamps[i].c;
            for (int j = 0; j < i; j ++)
                cost[i] = min(cost[i], cost[j] + lamps[i].k + (num[i] - num[j]) * lamps[i].c);
        }
        printf("%d\n", cost[n - 1]);
    }
    return 0;
}
