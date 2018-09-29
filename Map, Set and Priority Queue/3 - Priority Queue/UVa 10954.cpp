/* Topic: Priority Queue
 * Example: UVa 10954 Add All
 * Classic Problem
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
int main(){
    int n;
    while (scanf("%d", &n) && n) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0; i < n; i ++){
            int temp; scanf("%d", &temp);
            pq.push(temp);
        }
        ll ans = 0;
        while (pq.size() > 1) {
            int p = pq.top(); pq.pop();
            int q = pq.top(); pq.pop();
            ans += p + q;
            pq.push(p + q);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
