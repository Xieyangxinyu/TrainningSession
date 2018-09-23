/* Topic: Map / TreeMap
 * Example: UVa 11572 - Unique Snowflakes
 * Use TreeMap to record the occurrence index of a certain snowflake
 */
#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    while (t --) {
        map<int, int> match;
        int n, ans = 0, last = 0; scanf("%d", & n);
        for(int i = 1; i <= n; i ++) {
            int t; scanf("%d", &t);
            if(!match.count(t))match[t] = i;
            else {
                last = max(last, match[t]);
                match[t] = i;
            }
            ans = max(ans, i - last);
        }
        printf("%d\n", ans);
    }
    return 0;
}
