/* Topic: Ad Hoc - Edge Cases
 * Example: UVa 12545 - Bits Equalizer
 */
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int cases; scanf("%d\n", &cases);
    for(int c = 1; c <= cases; c++){
        int res = 0;
        string S, T;
        getline(cin, S);
        getline(cin, T);
        int size = (int) S.size(), zero = 0, one = 0, ques = 0;
        for (int i = 0; i < size; i ++)
            if (S[i] != T[i]) {
                if (S[i] == '0')
                    zero ++;
                else if(S[i] == '1')
                    one ++;
                else if(T[i] == '1') ques ++;
                else res ++;
            }
        
        int minus = min(zero, one);
        zero -= minus; one -= minus;
        res += minus + zero;
        minus = min(ques, one);
        one -= minus; ques -= minus;
        res += minus * 2;
        if (one) res = -1;
        else res += ques;
        
        printf("Case %d: %d\n", c, res);
    }
    return 0;
}
