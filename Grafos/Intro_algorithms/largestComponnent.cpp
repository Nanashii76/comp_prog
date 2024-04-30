#include <bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> g = {
    {0, {8,1,5}},
    {1, {0}},
    {5, {0,8}},
    {8, {0,5}},
    {2, {3,4}},
    {3, {2,4}},
    {4, {3,2}},
};

set<int> vis;

// Iterative solution and the first thing i've thought
int largestComponnent(int start, int count) {

    vis.insert(start);
    stack<int> st;
    st.push(start);

    while(not st.empty()) {
        int v = st.top();
        st.pop();

        for(auto x : g[v]) if (not vis.count(x)) {
            ++count;
            vis.insert(x);
            st.push(x);
        }
    }

    return count;

}

// other solution with recursion
int largestComponnent2(int start) {

    if(vis.count(start)) return 0;
    vis.insert(start);

    int count = 1;
    for(auto v : g[start])
        count += largestComponnent2(v);

    return count;
}

int main(){

    int maxComp = numeric_limits<int>::min();
    for(const auto& vertice : g) {
        if(not vis.count(vertice.first)) {
            int comp = largestComponnent2(vertice.first);
            maxComp = max(maxComp, comp);
        }
    }

    cout << maxComp << endl;

    return 0;
}
