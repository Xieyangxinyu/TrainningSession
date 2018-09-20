/* Topic: Use Sort to Simplify the Problem
 * Example: UVa 11824 - A Minimum Land Price
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long
#define maxn 45
#define inf 5000000
int A[maxn];

static bool comp(const int a, const int b){
    return a > b;
}

int main(){
    int t; scanf("%d", &t);
    while (t --) {
        int cnt = 0;
        while (scanf("%d", &A[cnt]) && A[cnt]) cnt ++;
        sort(A, A + cnt, comp);
        ll sum = 0;
        for(int i = 0; i < cnt; i ++){
            sum += 2 * pow((ll)A[i] , (ll)i + 1);
            if(sum > inf) break;
        }
        if(sum > inf) printf("Too expensive\n");
        else printf("%lld\n", sum);
    }
    return 0;
}
