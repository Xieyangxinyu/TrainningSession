/* Topic: Map / TreeMap
 * Example: UVa 10226 - Hardwood Species
 * Use TreeMap for simulation
 * Pay attention to input/output
 */
#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
int main(){
    int t; scanf("%d\n\n", & t);
    while (t --) {
        map<string, int> match;
        string line; int total = 0;
        while (getline(cin, line) && line.size()) {
            if(match.count(line))match[line] ++;
            else match[line] = 1;
            total ++;
        }
        for(auto i = match.begin(); i != match.end(); i ++){
            cout << i -> first;
            printf(" %.4f\n", (100.0 * i -> second / total));
        }
        if(t) printf("\n");
    }
    return 0;
}
