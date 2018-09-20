/* Topic: Multi-fields sorting
 * Example: UVa 10258 - Contest Scoreboard
 * Make sure you understand what the problem is asking before you start, it could be quite confusing
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 100 + 10
struct contestant {
    bool correct[15], attend;
    int time, wastedtime[15], prob, p;
}per[maxn];

static bool comp(const contestant a, const contestant b){
    return a.prob > b.prob ||
        (a.prob == b.prob && a.time < b.time) ||
        (a.prob == b.prob && a.time == b.time && a.attend > b.attend)||
        (a.prob == b.prob && a.time == b.time && a.attend == b.attend && a.p < b.p);
}
int main(){
    int t;scanf("%d\n\n", & t);
    while (t --) {
        char line[50];
        memset(per, 0, sizeof(per));
        while(gets(line) && strlen(line)){
            int p, prob, time; char ac;
            sscanf ( line, "%d%d%d %c", &p, &prob, &time, &ac);
            per[p].attend = 1;per[p].p = p;
            if(ac == 'C' && !per[p].correct[prob]){
                per[p].correct[prob] = 1;
                per[p].time += time + per[p].wastedtime[prob];
                per[p].prob ++;
            }else if(ac == 'I') per[p].wastedtime[prob] += 20;
        }
        sort(per + 1, per + 101, comp);
        for(int i = 1; i <= 100; i ++){
            if(!per[i].attend)break;
            printf("%d %d %d\n", per[i].p, per[i].prob, per[i].time);
        }
        if (t) printf("\n");
    }
}
