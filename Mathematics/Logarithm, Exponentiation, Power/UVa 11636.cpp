/* Topic: Topic: Exponentiation
 * Example: UVa 11636 - Hello World!
 */
#include <cstdio>

using namespace std;

int main(){
    int n, cases = 1;
    while(~scanf("%d\n", &n) && n > 0){
        int i = 1, res = 0;
        while (i < n) {
            i <<= 1;
            res ++;
        }
        printf("Case %d: %d\n", cases ++, res);
    }
    return 0;
}
