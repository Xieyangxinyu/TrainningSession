/* Topic: Multiple Arrays
 * Example: UVa 11608 - No Problem
 */
#include <cstdio>
using namespace std;

int main(){
    int t = 0, n;
    int in[13], out[13];
    while (scanf("%d", &n) && n >= 0) {
        printf("Case %d:\n", ++ t);
        for(int i = 0; i < 12; i ++)scanf("%d", &in[i]);
        for(int i = 0; i < 12; i ++)scanf("%d", &out[i]);
        for(int i = 0; i < 12; i ++){
            if(n >= out[i]){
                n -= out[i]; printf("No problem! :D\n");
            }else
                printf("No problem. :(\n");
            n += in[i];
        }
    }
    return 0;
}
