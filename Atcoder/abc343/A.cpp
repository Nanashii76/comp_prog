#include <bits/stdc++.h>
using namespace std;


int main(){
   
    int a,b;
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    cin >> a >> b;

    v.erase(v.begin()+(a+b));

    int randomIndex = rand() % v.size();

    cout << v[randomIndex] << endl;

}