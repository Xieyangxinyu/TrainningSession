/* Topic: Greedy
 * Example: UVa 410 Station Balance
 * Use Sort to simplify the problem
 * Be careful with the output format
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double _abs(double x){
    return x < 0 ? -x : x;
}

int main(){
    int n, m, t = 0;
    while (scanf("%d%d", &n, &m) != EOF) {
        printf("Set #%d\n", ++ t);
        int a[n * 2];
        double sum = 0;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i ++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sum /= (double)n;
        sort(a, a + n * 2);
        double ans = 0;
        for(int i = 0; i < n; i ++){
            printf(" %d:", i);
            if(a[i]) printf(" %d", a[i]);
            if(a[n * 2 - 1 - i])printf(" %d", a[n * 2 - 1 - i]);
            ans += _abs(a[i] + a[n * 2 - 1 - i] - sum);
            printf("\n");
        }
        printf("IMBALANCE = %.5f\n\n", ans);
    }
}
