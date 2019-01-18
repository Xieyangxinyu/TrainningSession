/* Topic: Topic: Use Sort to Simplify the Problem
 * Example: UVa 11039 - Building designing
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int floor = 500000 + 1;

int num[floor], tag[floor];
bool pos[floor];

bool comp(const int & a, const int & b){
    return num[a] < num[b];
}

int main(){
    int n, cases; scanf("%d", &cases);
    
    while(cases --){
        scanf("%d\n", &n);
        
        for (int i = 0; i < n; i ++) {
            scanf("%d", &num[i]);
            if (num[i] >= 0) pos[i] = 1;
            else { pos[i] = 0; num[i] = - num[i]; }
            tag[i] = i;
        }
        
        sort(tag, tag + n, comp);
        
        int res = 0;
        if (n > 0) {
            res = 1;
            int past = pos[tag[0]];
            for (int i = 1; i < n; i ++)
                if (past ^ pos[tag[i]]) {
                    past = pos[tag[i]]; res ++;
                }
        }
        printf("%d\n", res);
    }
    return 0;
}
