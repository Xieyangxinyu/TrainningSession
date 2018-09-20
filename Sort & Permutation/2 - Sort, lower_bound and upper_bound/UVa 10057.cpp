/* Topic: Sort, upper_bound, lower_bound
 * Example: UVa 10057 - A mid-summer night ...
 * upper_bound returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
 * lower_bound returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define maxn 1000000 + 10
int A[maxn], n;

int main(){
    while (scanf("%d", &n) != EOF) {
        double sum = 0;
        for(int i = 0; i < n; i ++) scanf("%d", & A[i]);
        sort(A, A + n);
        int pos = (n - 1) >> 1;
        printf("%d %d %d\n", A[pos], upper_bound(A, A + n, A[n >> 1]) - lower_bound(A, A + n, A[pos]), A[n >> 1] - A[pos] + 1);
    }
    return 0;
}
