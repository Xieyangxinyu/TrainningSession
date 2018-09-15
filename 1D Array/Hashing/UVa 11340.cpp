/* Topic: Array & Hashing
 * Example: UVa 11340 - Newspaper
 */
 
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define P pair<char, int>
#define hashsize 100 + 5
#define maxn 100  + 5

P state[maxn];
int head[hashsize], nxt[hashsize], cnt;
int hashnum(char x){
    return x % hashsize;
}

void insert(char key, int val){
    int h = hashnum(key);
    for(int u = head[h]; u; u = nxt[u])
        if(state[u].first == key) return;
    state[cnt] = P(key, val);
    nxt[cnt] = head[h];
    head[h] = cnt ++;
}

int inset(char key){
    int h = hashnum(key);
    for(int u = head[h]; u; u = nxt[u]){
        if(state[u].first == key) return state[u].second;
    }
    return 0;
}

int main(){
    int t; scanf("%d", &t);
    while (t --) {
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
        cnt = 1;
        int k, v; char c; scanf("%d\n", &k);
        for(int i = 0; i < k; i ++){
            scanf("%c%d\n",&c, &v);
            insert(c, v);
        }
        int m; scanf("%d\n", &m);
        long long ans = 0;
        for(int i = 0; i < m; i ++){
            c = getchar();
            while(c != '\n'){
                ans += inset(c);
                c = getchar();
            }
        }
        double out = (double)ans / 100;
        printf("%.2f$\n", out);
    }
}
