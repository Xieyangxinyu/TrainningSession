/* Topic: Queue
 * Example: UVa 10172 - The Lonesome Cargo Distributor
 * Use queue to simulate the process
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int unload(stack<int> &truck, queue<int> &station, int destination, int stationCap, int &rem){
    int time = 0;
    while (truck.size()) {
        int t = truck.top();
        while (t == destination) {
            time ++; rem --;
            truck.pop();
            if(truck.size())
                t = truck.top();
            else break;
        }
        if(truck.size() && station.size() < stationCap){
            time ++;
            truck.pop();
            station.push(t);
        }else break;
    }
    return time;
}

int load(stack<int> &truck, queue<int> &station, int truckcap){
    int time = 0;
    while (station.size() && truck.size() < truckcap) {
        time ++;
        int t = station.front();
        station.pop();
        truck.push(t);
    }
    return time;
}

int main(){
    int t; scanf("%d", &t);
    while (t --) {
        int n, s, q, rem = 0, time = 0;
        scanf("%d%d%d", &n, &s, &q);
        vector<queue<int> > station;
        for(int i = 0; i < n; i ++){
            queue<int> tq;
            int size, des;
            scanf("%d", &size);
            while (size --) {
                scanf("%d", &des);
                tq.push(des);
                rem ++;
            }
            station.push_back(tq);
        }
        //start the journey
        int from = 0;
        stack<int> truck;
        while (rem) {
            from %= n;
            
            //unload
            time += unload(truck, station[from], from + 1, q, rem);
            
            //load
            time += load(truck, station[from], s);
            
            //travel
            if(rem) {
                from ++;
                time += 2;
            }
        }
        printf("%d\n", time);
    }
    return 0;
}
