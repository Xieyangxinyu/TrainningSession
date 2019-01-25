/* Topic: Max 1D Range Sum
 * Example: UVa 11584 - Partitioning by Palindromes
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n; scanf("%d\n", &n);
    while (n --) {
        string line;
        getline(cin, line);
        int size = (int)line.size();
        bool palindrome[size][size];
        memset(palindrome, 0, sizeof(palindrome));
        for (int j = 0; j < size; j ++)
            for (int i = 0; i + j < size; i ++)
                palindrome[i][i + j] = (line[i] == line[i + j]) && (j < 2 || palindrome[i + 1][i + j - 1]);
        
        int dp[size];
        memset(dp, 127, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i < size; i ++)
            for (int j = 0; j <= i; j ++)
                if (palindrome[j][i]) dp[i] = min(dp[i], 1 + (j == 0 ? 0 : dp[j - 1]));
        printf("%d\n", dp[size - 1]);
    }
    return 0;
}
