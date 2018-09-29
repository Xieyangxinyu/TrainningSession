/* Topic: Multiset
 * Example: UVa 978 Lemmings Battle!
 * Note that set/multiset is implemented by red-black tree in C++
 * Hence, set/multiset in C++ is ordered
 * Learn to construct the operator in multiset
 */
#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

struct cmp {
    bool operator () (const int a, const int b) const{
        return a > b;
    }
};
int main(){
    int n; scanf("%d", &n);
    while (n --) {
        int b, sg, sb;
        scanf("%d%d%d", &b, &sg, &sb);
        multiset<int, cmp> green;
        multiset<int, cmp> blue;
        for(int i = 0; i < sg; i ++){
            int temp; scanf("%d", &temp);
            green.insert(temp);
        }
        for(int i = 0; i < sb; i ++){
            int temp; scanf("%d", &temp);
            blue.insert(temp);
        }
        while (green.size() && blue.size()) {
            int battle[b];
            memset(battle, 0, sizeof(battle));
            for(int i = 0; i < b; i ++)
                if(green.size() && blue.size()){
                    auto itr = green.begin();
                    battle[i] = *itr;
                    green.erase(itr);
                    itr = blue.begin();
                    battle[i] -= *itr;
                    blue.erase(itr);
                }else break;
            for(int i = 0; i < b; i ++)
                if(battle[i] > 0) green.insert(battle[i]);
                else if(battle[i] < 0) blue.insert(0 - battle[i]);
        }
        if(green.size()) {
            printf("green wins\n");
            for (auto itr = green.begin(); itr != green.end(); itr ++)
                printf("%d\n", *itr);
        }
        else if(blue.size()){
            printf("blue wins\n");
            for (auto itr = blue.begin(); itr != blue.end(); itr ++)
                printf("%d\n", *itr);
        }
        else printf("green and blue died\n");
        if(n) printf("\n");
    }
    return 0;
}
