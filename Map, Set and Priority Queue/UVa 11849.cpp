/* Topic: Set
 * Example: UVa 11849 - CD
 */
#include <cstdio>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
int main(){
    int n, m;
    while (scanf("%d%d", &n, &m) && (n || m)) {
        int ans = 0;
        set<ll> s;
        for (int i = 0; i < n; i ++) {
            ll temp; scanf("%lld", &temp);
            s.insert(temp);
        }
        for (int i = 0; i < m; i ++) {
            ll temp; scanf("%lld", &temp);
            if(s.count(temp))ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
