/* Topic: Ad Hoc - Edge Cases
 * Example: UVa 1610 - Party Games
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 1000 + 5
string names[maxn];

int main(){
    int n;
    while (scanf("%d\n", &n) && n) {
        for (int i = 0; i < n; i ++)
        getline(cin, names[i]);
        sort(names, names + n);
        string first = names[(n >> 1) - 1], second = names[n >> 1];
        for (unsigned long i = 0; i < first.size(); i ++)
            if (first[i] == second[i] || first[i] == 'Z' || (i == second.size() - 1 && first[i] + 1 == second[i]))
                continue;
            else if(i < first.size() - 1){
                first[i] += 1;
                first = first.substr(0, i + 1);
                break;
            }
        cout << first << "\n";
    }
    return 0;
}
