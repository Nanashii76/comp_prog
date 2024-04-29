#include <bits/stdc++.h>
using namespace std;

// In this problem he get a list of pairs of connections, so we'll convert
// to a unordered map graph
unordered_map<char,list<char>> g;

// to avoid cycles, we'll store the values visited in a set, because we're 
// working with characters
set<char> visited;

bool hashPath(char start, char end) {

	if(start == end)
		return true;

	for(auto x : g[start]) if (not visited.count(start)) {
		visited.insert(x);
		if(hashPath(x,end))
			return true;
	}

	return false;
}


int main(){

	list<pair<int,int>> edges {
		{'i','j'},
		{'k','i'},
		{'m','k'},
		{'k','l'},
		{'o','n'},
	};


	for(const auto& x : edges) {
		g[x.first].emplace_back(x.second);
		g[x.second].emplace_back(x.first);
	}

	cout << (hashPath('i','o') ? "true" : "false") << endl;
	return 0;

}
