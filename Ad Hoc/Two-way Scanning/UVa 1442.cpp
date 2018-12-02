/* Topic: Ad Hoc
 * Example: UVa 1442 Cav
 * Two Way Scanning
 * O(n)
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1000000 + 10
int n;
int p[maxn], s[maxn], h[maxn];

void init(){
    for (int i = 0; i < n; i ++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i ++) scanf("%d", &s[i]);
}

int solve(){
    int begin = s[0], res = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] < begin) begin = s[i];
        if (p[i] > begin) begin = p[i];
        h[i] = begin;
    }
    begin = s[n - 1];
    for (int i = n - 1; i >= 0; i --) {
        if (s[i] < begin) begin = s[i];
        if (p[i] > begin) begin = p[i];
        h[i] = min(begin, h[i]);
        res += h[i] - p[i];
    }
    return res;
}

int main(){
    int t;scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        init();
        printf("%d\n", solve());
    }
    return 0;
}
