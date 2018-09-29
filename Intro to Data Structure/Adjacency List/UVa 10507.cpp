/* Topic: Adjacency Matrix
 * Example: UVa 10507 Waking up brain
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool connect[30][30];
int map[30];
bool vis[30];

int main(){
    int n, m;
    while (scanf("%d", &n) ==  1) {
        memset(connect, 0, sizeof(connect));
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        scanf("%d\n", &m);
        char s[10];
        scanf("%s", s);
        queue<int> q;
        for(int i = 0; i < 3; i ++){
            int temp = s[i] - 'A';
            map[temp] = 3; vis[temp] = 1;
            q.push(temp);
        }
        n -= 3;
        for(int i = 0; i < m; i ++){
            scanf("%s", s);
            int a = s[0] - 'A', b = s[1] - 'A';
            connect[a][b] = connect[b][a] = 1;
        }
        int ans = 0;
        while (q.size()) {
            int t = q.size(); ans ++;
            while (t --) {
                int p = q.front(); q.pop();
                for(int i = 0; i < 26; i ++)
                    if(connect[p][i]){
                        map[i] ++;
                        if(map[i] >= 3 && !vis[i]){
                            n --;
                            q.push(i);
                            vis[i] = 1;
                        }
                    }
            }
        }
        if(!n)printf("WAKE UP IN, %d, YEARS\n", ans - 1);
        else printf("THIS BRAIN NEVER WAKES UP\n");
    }
    return 0;
}
