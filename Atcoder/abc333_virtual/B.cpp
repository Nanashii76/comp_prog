#include <bits/stdc++.h>
using namespace std;

int dist_dic(string t){

    int dist = 0;

    if(t[0] == 'A') {
        switch(t[1]) {
            case 'B':
                dist += 1;
                break;
            case 'C':
                dist += 2;
                break;
            case 'D':
                dist += 2;
                break;
            case 'E':
                dist += 1;
                break;
            default:
                break;
            }
        } else if (t[0] == 'B') {
            switch(t[1]) {
            case 'A':
                dist += 1;
                break;
            case 'C':
                dist += 1;
                break;
            case 'D':
                dist += 2;
                break;
            case 'E':
                dist += 2;
                break;
            default:
                break;
            }
        } else if (t[0] == 'C') {
            switch(t[1]) {
            case 'A':
                dist += 2;
                break;
            case 'B':
                dist += 1;
                break;
            case 'D':
                dist += 1;
                break;
            case 'E':
                dist += 2;
                break;
            default:
                break;
            }
        } else if (t[0] == 'D') {
            switch(t[1]) {
            case 'A':
                dist += 2;
                break;
            case 'B':
                dist += 2;
                break;
            case 'C':
                dist += 1;
                break;
            case 'E':
                dist += 1;
                break;
            default:
                break;
            }
        } else {
            switch(t[1]) {
            case 'A':
                dist += 1;
                break;
            case 'B':
                dist += 2;
                break;
            case 'C':
                dist += 2;
                break;
            case 'D':
                dist += 1;
                break;
            default:
                break;
            }
        }

        return dist;
}    

int main(){

    string s1,s2;
    cin >> s1 >> s2;

    int distS1 = dist_dic(s1), distS2 = dist_dic(s2);

    if(distS1 == distS2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}