#include <bits/stdc++.h>
using namespace std;

unordered_map<char,list<char>> g {
	{'a', {'b','c'}},
	{'b', {'d'}},
	{'c', {'e'}},
	{'d', {'f'}},
	{'e', {}},
	{'f', {}},
};

// Iplementing a dfs in a directed acycle graph with hashtable
void dfs(char key) {

	stack<char> st;
	st.push(key);

	while(not st.empty()) {
		char act = st.top();
		st.pop();
		
		cout << act << " ";

		for(auto x : g[act])
			st.push(x);
	}
}

// Implementing a bfs in a directed acycle graph with hashtable 
void bfs(char key) {

	queue<char> q;
	q.push(key);

	while(not q.empty()) {
		char act = q.front();
		q.pop();

		cout << act << " ";

		for(auto x : g[act])
			q.push(x);
	
	}
}

int main() {

	dfs('a');
	cout << endl;
	
	bfs('a');
	return 0;
}

