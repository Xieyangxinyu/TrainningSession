/* Topic: Prev Permutaion & Next Permutation
 * Example: UVa 1209 Wordfish
 */
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int minimum_absolute_distance(char * p, int n){
    int ans = abs(p[1] - p[0]);
    for(int i = 2; i < n; i ++)
        ans = min(ans, abs(p[i] - p[i - 1]));
    return ans;
}
int main(){
    char p[25], q[25], res[25];
    while (scanf("%s", p) != EOF && strlen(p)) {
        memcpy(q, p, sizeof(p));
        memcpy(res, p, sizeof(p));
        int n = strlen(p), maxi = minimum_absolute_distance(p, n);
        for(int i = 0; i < 10; i ++){
            if(prev_permutation(p, p + n)){
                int temp = minimum_absolute_distance(p, n);
                if(maxi <= temp){
                    maxi = temp; memcpy(res, p, sizeof(p));
                }
            }else break;
        }
        for(int i = 0; i < 10; i ++){
            if(next_permutation(q, q + n)){
                int temp = minimum_absolute_distance(q, n);
                if(maxi < temp){
                    maxi = temp; memcpy(res, q, sizeof(q));
                }
            }else break;
        }
        printf("%s%d\n", res, maxi);
    }
    return 0;
}
