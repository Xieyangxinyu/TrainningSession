/* Topic: Adjacency list
 * Example: UVa 10895 Matrix Transpose
 */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 20010
struct cell{
    int x, val;
    cell(int x, int val):x(x), val(val) {};
};

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        vector<cell> q[m + 1];
        for(int i = 1; i <= n; i ++){
            int r; scanf("%d\n", &r);
            int index[r];
            for(int j = 1; j <= r; j ++)
                scanf("%d", &index[j]);
            for(int j = 1; j <= r; j ++){
                int v; scanf("%d", &v);
                q[index[j]].push_back(cell{i, v});
            }
        }
        printf("%d %d\n", m, n);
        for(int i = 1; i <= m; i ++){
            printf("%d", q[i].size());
            for(int j = 0; j < q[i].size(); j ++)
                printf(" %d", q[i][j].x);
            printf("\n");
            for(int j = 0; j < q[i].size(); j ++)
                if(j < q[i].size() - 1)printf("%d ", q[i][j].val);
                else printf("%d", q[i][j].val);
            printf("\n");
        }
    }
    return 0;
}
