#include <bits/stdc++.h>
using namespace std;

// Implementing a graph like and adjacency list
unordered_map<int, list<int>> g {
	{0, {8,1,5}},
	{1, {0}},
	{5, {0,8}},
	{8, {0,5}},
	{2, {3,4}},
	{3, {2,4}},
	{4, {3,2}},
};

set<int> vis;

int connectedComponents(int start, int count) {

	stack<int> st;
	st.push(start);
	vis.insert(start);
	while(not st.empty()) {
		count++;
		int crt = st.top();
		st.pop();
		
		for(auto v : g[crt]) if(not vis.count(v))
			st.push(v);	
	}

	return count;
}

int main(){
	
	int maxComp = 0;
	for(int i=0; i < 9; ++i)
		maxComp = max(maxComp, connectedComponents(i,0));

	cout << maxComp << endl;
	return 0;
}

