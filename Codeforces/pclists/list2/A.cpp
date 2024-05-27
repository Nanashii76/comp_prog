#include <bits/stdc++.h>
using namespace std;

int solve(queue<int> q, int f, int p) {

    int count = 0;

    if(f == 1) {
        while(not q.empty()) {
            int v = q.front();
            q.pop();
            if(v > p) {
                v -= 2;
                q.push(v);
                count += 10;
            } else
                count += 5;
                
        }
    } 
    
    else if (f == 2) {
        bool fis = false;
        while(not q.empty()) {
            int v = q.front();
            q.pop();
            if(not fis and v > p) {
                v -= 2;
                q.push(v);
                count += 10;
                fis = true;
            } else if (not fis and v <= p) {
                fis = true;
                count += 5;
            } else {
                count += 1;
                fis = false;
            }
        }
    } 
    
    else if(f == 3) {
        for(int i = 1; not q.empty(); ++i) {
            int v = q.front();
            q.pop();
            if((i%3) == 1 and v > p) {
                v -= 2;
                q.push(v);
                count += 10;
            } else if((i%3)==1 and v <= p) 
                count += 5;
            else
                count += 1;
        }
    }

    return count;

}

int main(){

    int n, f, p; cin >> n >> f >> p;
    queue<int> q;
    while(n--) {
        int aux; cin >> aux;
        q.push(aux);
    }

    cout << solve(q,f,p) << endl;
    return 0;

}