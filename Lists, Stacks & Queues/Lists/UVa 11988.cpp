/* Topic: List
 * Example: UVa 11988 - Broken Keyboard ...
 * Do not use strlen() in loops; it is super time-consuming
 */
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 100000 + 10

struct listNode{
    char val;
    listNode * next;
};

char s[maxn];

int main(){
    while (~scanf("%s", s)) {
        listNode *head = new listNode, *cur = head, *back = cur;
        cur -> next = NULL;
        int n = strlen(s);
        for(int i = 0; i < n; i ++){
            if(s[i] == '[')cur = head;
            else if(s[i] == ']') cur = back;
            else{
                listNode *temp = new listNode;
                temp -> val = s[i];
                temp -> next = cur -> next;
                if(cur == back) back = temp;
                cur -> next = temp;
                cur = temp;
            }
        }
        while (head -> next) {
            listNode *temp = head;
            printf("%c", head -> next -> val);
            head = head -> next;
            delete temp;
        }
        printf("\n");
    }
}
