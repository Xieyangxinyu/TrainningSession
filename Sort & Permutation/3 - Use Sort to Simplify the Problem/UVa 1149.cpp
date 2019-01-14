/* Topic: Use Sort to Simplify the Problem
 * Example: UVa 1149 - Bin Packing
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 100000 + 5
int bin[maxn];

int main(){
    int T; scanf("%d", &T);
    while (T --) {
        int n; scanf("%d", &n);
        int l; scanf("%d", &l);
        for (int i = 0; i < n; i ++)
            scanf("%d", &bin[i]);
        sort(bin, bin + n);
        int start = 0, end = n - 1, res = 0;
        while (start < end) {
            if (bin[start] + bin[end] > l) {
                end --; res ++;
            }else{
                end --; start ++; res ++;
            }
        }
        if (start == end) res ++;
        printf("%d\n", res);
        if (T) printf("\n");
    }
    return 0;
}
