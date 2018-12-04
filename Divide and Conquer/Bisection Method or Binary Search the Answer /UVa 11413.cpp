/* Topic: Binary Search
 * Example: UVa 11413 Fill the Containers
 * Binary search the answer + simulation
 */
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 1000 + 10
#define INF 1000000000000 + 10
#define ll long long
int N, M;
int c[maxn];

bool C(ll x){
    int num = 1; ll cap = x;
    for (int i = 0; i < N; i ++)
        if(cap - c[i] >= 0)
            cap -= c[i];
        else{
            cap = x - c[i];
            if (cap < 0) return true;
            num ++;
        }
    return num > M;
}

void solve(){
    ll lb = 0, ub = INF;
    for (int i = 0; i < 100; i ++) {
        ll mid = (lb + ub) / 2;
        if (C(mid)) lb = mid;
        else ub = mid;
    }
    printf("%lld\n", ub);
}

int main(){
    while (scanf("%d%d", &N, &M) != EOF) {
        for (int i = 0; i < N; i ++)
            scanf("%d", &c[i]);
        solve();
    }
    return 0;
}
