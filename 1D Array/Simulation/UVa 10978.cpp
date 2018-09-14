#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 55
string arr[maxn];
int ope[maxn], pos[maxn];
bool out[maxn];
int main(){
    int n;
    while (scanf("%d\n", &n) != EOF && n) {
        memset(out, 0, sizeof(out));
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
            string temp; cin >> temp;
            ope[i] = temp.size();
        }
        // Originally I thought this is a linked-list problem, but it turned out that the simulation is not so.
        for(int i = 0,j = 0 ; i < n ; ++i){
            for(int k = ope[i] ; ; j = (j + 1) % n)
                if(!out[j] && --k <= 0)
                    break;
            pos[j] = i; out[j] = true;
        }
        cout << arr[pos[0]];
        for (int i = 1; i < n; i ++)
            cout << " " << arr[pos[i]];
        cout << endl;
    }
}
