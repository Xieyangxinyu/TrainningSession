/* Topic: Queue
 * Example: UVa 12207 - This is Your Queue
 * Use deque and map to simulate the process
 */
#include <cstdio>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long
int main(){
    ll p, c, t = 0;
    while(scanf("%lld%lld\n", &p, &c) != EOF && (p || c)){
        printf("Case %lld:\n", ++t);
        map<ll, ll> m;
        map<ll, bool> out;
        ll size = min(p, c);
        deque<ll> q;
        for(ll i = 1; i <= size; i ++) q.push_back(i);
        for(ll i = 0; i < c; i ++){
            char x = getchar();
            if(x == 'N'){
                scanf("\n");
                ll cur = q.front();
                while(m.count(cur) && m[cur] > 0 && !out[cur]){
                    m[cur] --;
                    q.pop_front();
                    cur = q.front();
                }
                if(out.count(cur) && out[cur]) out[cur] = false;
                printf("%lld\n", cur); q.pop_front(); q.push_back(cur);
            }else if(x == 'E'){
                ll cur;
                scanf("%lld\n", &cur);
                if(!m.count(cur))m[cur] = 1;
                else m[cur] ++;
                out[cur] = true;
                q.push_front(cur);
            }
        }
    }
    return 0;
}
