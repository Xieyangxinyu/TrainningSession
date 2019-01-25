/* Topic: Tricky swaps
 * Example: UVa 1611 - Crane
 */
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define P pair<int,int>

const int maxn = 10000 + 5;
int num[maxn], tag[maxn];

void swap_(int s, int e, int l){
    for (int i = 0; i < l; i ++) {
        swap(num[s + i], num[e + i]);
        swap(tag[num[s + i]], tag[num[e + i]]);
    }
}

int main(){
    int n, cases; scanf("%d", &cases);
    
    while(cases --){
        scanf("%d\n", &n);
        
        for (int i = 0; i < n; i ++) {
            scanf("%d", &num[i]);
            num[i] --;
            tag[num[i]] = i;
        }
        queue<P> q;
        for (int i = 0; i < n; i ++) {
            if (num[i] != i) {
                if (2 * tag[i] < n + i){
                    q.push(P(i + 1, 2 * tag[i] - i));
                    swap_(i, tag[i], tag[i] - i);
                }
                else {
                    q.push(P(2 * tag[i] - n + 1, n));
                    swap_(2 * tag[i] - n, tag[i], n - tag[i]);
                    i --;
                }
            }
        }
        printf("%d\n", (int) q.size());
        while (q.size()) {
            printf("%d %d\n", q.front().first, q.front().second);
            q.pop();
        }
    }
    return 0;
}
