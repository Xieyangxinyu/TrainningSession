/*
 * Interestingly, with the data range of this problem, it is true that any even number that is greater than or equals to 4 can be expressed as the sum of two prime numbers, yet mathematically this has not yet been proved either true or false.
 * In this problem, we only count the number of permutations that can have a XOR result that is greater than or equals to 4
 * We use sum array to store the number of possible matchings on the right, thus the time complexity is O(1000000)
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define maxn 1000000 + 10

int arr[maxn];
int sum[maxn];
int main(){
    int t;scanf("%d", & t);
    while (t --) {
        memset(arr, 0, sizeof(arr));
        memset(sum, 0, sizeof(sum));
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            int x;scanf("%d", &x);
            arr[x]++;
        }
        for(int i = 1000000; i; i -= 2){
            sum[i] = sum[i + 2] + arr[i + 2];
            sum[i - 1] = sum[i + 1] + arr[i + 1];
        }
        long long ans = 0;
        for(int i = 2; i <= 1000000; i += 2){
            if((i ^ (i + 2)) > 2)ans += arr[i] * sum[i];
            else ans += arr[i] * sum[i + 2];
        }
        for(int i = 1; i <= 1000000; i += 2)
            if((i ^ (i + 2)) > 2)ans += arr[i] * sum[i];
            else ans += arr[i] * sum[i + 2];
        printf("%lld\n", ans);
    }
    return 0;
}
