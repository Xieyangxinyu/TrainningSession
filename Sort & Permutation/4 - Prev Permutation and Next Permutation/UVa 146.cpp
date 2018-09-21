/* Topic: Next Permutation
 * Example: UVa 146 - ID Codes
 */
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    char a[55];
    while (scanf("%s", a) && a[0] != '#') {
        int n = strlen(a);
        if(next_permutation(a, a + n)){
            for(int i = 0; i < n; i ++)printf("%c", a[i]);
        }else printf("No Successor");
        printf("\n");
    }
    return 0;
}
