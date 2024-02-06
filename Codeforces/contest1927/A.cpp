#include <bits/stdc++.h>

using namespace std;

int how_many(string c, int index) {

    int count = 0, start = 0, end = 0;

    for(int i = 0; i < index; ++i) {

        if(c[i] == 'B' && count == 0) {
            count++;
            start = i;
        } 

        if(c[i] == 'B' && count != 0)
            end = i;

    }

    return end-start+1;

}


int main(void){

    int n, index;
    string c;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> index >> c;
        cout << how_many(c, index) << endl;
    }

}