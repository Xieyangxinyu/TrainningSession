/* Topic: Union Find Disjoint Sets
 * Example: UVa 599 The Forrest for the Trees
 * Use rnk to distinguish trees and acorns
 */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define maxn 30
int par[maxn], rnk[maxn];

void init(){
    for (int i = 0; i < maxn; i ++) {
        par[i] = i; rnk[i] = 0;
    }
}

int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]) par[x] = y;
    else{
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x] ++;
    }
}

int main(){
    int t; scanf("%d\n", &t);
    while (t --) {
        init();
        char s[10];
        while (~scanf("%s\n", s) && s[0] != '*') {
            int a = s[1] - 'A', b = s[3] - 'A';
            unite(a, b);
        }
        char c = getchar();
        int tree = 0, acorn = 0;
        while (c != '\n') {
            if(c != ','){
                int temp = c - 'A';
                if(par[temp] == temp){
                    if(!rnk[temp]) acorn ++;
                    else tree ++;
                }
            }
            c = getchar();
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
    return 0;
}
