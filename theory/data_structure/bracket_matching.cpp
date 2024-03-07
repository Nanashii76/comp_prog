#include <iostream>
#include <vector>
#include <stack>

std::vector<int> stringToDigit(char *s1) {

    std::vector<int> ans;

    for(int i = 0; s1[i] != '\0'; ++i) {
        switch(s1[i]) {
            case '{':
                ans.emplace_back(1);
                break;
            case '}':
                ans.emplace_back(2);
                break;
            case '(':
                ans.emplace_back(3);
                break;
            case ')':
                ans.emplace_back(4);
                break;
            case '[':
                ans.emplace_back(5);
                break;
            case ']':
                ans.emplace_back(6);
                break;
            default:
                break;
       }
    }

    return ans;

}

bool valid(std::vector<int> &brackets) {

    std::stack<int> st;
    int N = (int)brackets.size();

    for(int i = 0; i < N; ++i) {
        if(st.empty()) {
            if(brackets[i] % 2 != 0)
                st.push(brackets[i]);
            else
                return false;
        }
        else if (st.top() == brackets[i] - 1 && brackets[i] % 2 == 0)
            st.pop();
        else if (brackets[i] % 2 != 0)
            st.push(brackets[i]);
        else
            return false;
    }

    return st.empty();

}

int main(void) {

    std::vector<int> brackets;
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; ++i) {
        char s[300];
        std::cin >> s;
        brackets = stringToDigit(s);
        if(valid(brackets))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
}
