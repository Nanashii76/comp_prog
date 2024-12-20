// 1385 - D. a-Good String

#include <bits/stdc++.h>
using namespace std;

int makeGoodString(string &s, char c) {
    int n = s.size();
    
    if (n == 1) {
        return (s[0] != c);  
    }

    int half = n / 2;
    string left = s.substr(0, half);
    string right = s.substr(half);

    int leftChanges = 0;
    for (char ch : left) {
        if (ch != c) {
            leftChanges++;
        }
    }

    int rightChanges = makeGoodString(right, c + 1);

    int option1 = leftChanges + rightChanges;

    int rightLeftChanges = 0;
    for (char ch : right) {
        if (ch != c) {
            rightLeftChanges++;
        }
    }

    int leftRightChanges = makeGoodString(left, c + 1);

    int option2 = rightLeftChanges + leftRightChanges;

    return min(option1, option2);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int result = makeGoodString(s, 'a');  
        cout << result << endl;
    }

    return 0;
}
