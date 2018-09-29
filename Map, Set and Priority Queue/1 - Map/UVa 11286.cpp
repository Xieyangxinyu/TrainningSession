/* Topic: Map / TreeMap
 * Example: UVa 11286 - Conformity
 * Use TreeMap for counting
 */
#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int t;
    while (scanf("%d", &t) && t) {
        map<string, int> match;
        int course[5], pop = 0;
        for(int i = 0; i < t; i ++){
            for(int j = 0; j < 5; j ++)scanf("%d", &course[j]);
            sort(course, course + 5);
            string key = "";
            for(int j = 0; j < 5; j ++) key += to_string(course[j]);
            if(!match.count(key))match[key] = 1;
            else match[key] ++;
            if(pop < match[key]) pop = match[key];
        }
        int ans = 0;
        for (auto i = match.begin(); i != match.end(); i ++) {
            if(pop == i -> second) ans += pop;
        }
        printf("%d\n", ans);
    }
    return 0;
}
