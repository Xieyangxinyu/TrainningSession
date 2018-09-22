/* Topic: Stack
 * Example: UVa 732 Anagrams by Stack
 * Use stack & backtracking
 */
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define maxn 100000 + 10

int n, m;
stack<char> s;

char a[maxn], b[maxn];
char ans[maxn * 2];

void find(int x, int y, int cnt){
    if(x >= n && y >= m){
        for(int i = 0; i < n * 2; i ++)
            if(i < n * 2 - 1)printf("%c ", ans[i]);
            else printf("%c\n", ans[i]);
        return;
    }
    else if(x > n || y > m)return;
    s.push(a[x]);
    ans[cnt] = 'i';
    find(x + 1, y, cnt + 1);
    s.pop();
    if(s.size() && b[y] == s.top()){
        ans[cnt] = 'o';
        int temp = s.top();
        s.pop();
        find(x, y + 1, cnt + 1);
        s.push(temp);
    }
}

int main(){
    while (~scanf("%s%s", a,b)) {
        printf("\[\n");
        n = strlen(a); m = strlen(b);
        if(n != m) {
            printf("\]\n");
            continue;
        }
        find(0, 0, 0);
        printf("\]\n");
    }
    return 0;
}
