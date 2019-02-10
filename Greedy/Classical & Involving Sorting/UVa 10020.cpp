/* Topic: Greedy
 * Example: UVa 10020 - Minimal coverage
 * Interval Cover
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define P pair<int, int>

bool comp(const P &a, const P &b){
    return a.first < b.first;
}

const int maxn = 100000 + 10;
P interval[maxn];
int ans[maxn];

int main(){
    int t; scanf("%d", &t);
    while (t --) {
        int M; scanf("%d", &M);
        int l, r, cnt = 0;
        while (~scanf("%d %d", &l, &r) && (l || r)) {
            interval[cnt].first = l; interval[cnt ++].second = r;
        }
        sort(interval, interval + cnt, comp);
        bool has_ans = false; int cnt_ans = 0, start = 0, end = 0;
        for (int i = 0; i < cnt; i ++) {
            if (interval[i].second < 0)
                continue;
            if (interval[i].first <= start){
                if (interval[i].second > end) {
                    end = interval[i].second; ans[cnt_ans] = i;
                }
            }
            else if(interval[i].first > end)
                break;
            else if(interval[i].first > start){
                if (has_ans) break;
                start = end; i --; cnt_ans ++;
            }
            if (end >= M)
                has_ans = true;
        }
        if (! has_ans) printf("0\n");
        else{
            printf("%d\n", cnt_ans + 1);
            for (int i = 0; i < cnt_ans + 1; i ++)
                printf("%d %d\n", interval[ans[i]].first, interval[ans[i]].second);
        }
        if (t) printf("\n");
    }
    return 0;
}
