/* Topic: Priority Queue
 * Example: UVa 1203 Argus
 * Learn to construct the operator in priority queue
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long

struct node{
    int q, t, p;//Query, Time, Period
};

struct cmp{
    bool operator () (const node a, const node b) const{ //return true if a has less priority
        return a.t > b.t || (a.t == b.t && a.q > b.q);
    }
};

int main(){
    priority_queue<node, vector<node>, cmp> pq;
    char s[10];
    while(scanf("%s", s) && s[0] != '#'){
        int a,b; scanf("%d %d\n", &a, &b);
        node *temp = new node;
        temp -> q = a; temp -> t = temp -> p = b;
        pq.push(*temp);
    }
    int k; scanf("%d", &k);
    while (k --) {
        node temp = pq.top(); pq.pop();
        printf("%d\n", temp.q);
        temp.t += temp.p;
        pq.push(temp);
    }
    return 0;
}
