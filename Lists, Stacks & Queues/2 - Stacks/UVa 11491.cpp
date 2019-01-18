/* Topic: Topic: Stack
 * Example: UVa 11491 - Erasing and Winning
 */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n,d;
    while(scanf("%d%d\n", &n, &d) && (n || d)){
        string num; getline(cin, num);
        stack<char> stack1;
        stack1.push(num[0]);
        for (int i = 1; i < n; i ++) {
            while (d && stack1.size() && stack1.top() < num[i]) {
                stack1.pop(); d --;
            }
            stack1.push(num[i]);
        }
        string ans = "";
        stack<char> stack2;
        while(stack1.size()) {
            if(d) d --;
            else stack2.push(stack1.top());
            stack1.pop();
        }
        while (stack2.size()) {
            ans += stack2.top();
            stack2.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
