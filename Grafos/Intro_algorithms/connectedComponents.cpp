#include <bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> g {
	{3, {}},
	{4, {6}},
	{6, {4,5,7,8}},
	{8, {6}},
	{7, {6}},
	{5, {6}},
	{1, {2}},
	{2, {1}},
};

// marking the vertices visited in a set
set<int> vis;

// counting the number of connected components in a arbitraty graph 
bool connectedComponents(int start) {

	vis.insert(start);
	for(auto v : g[start]) if (not vis.count(v)) {
		connectedComponents(v);
	}

	return true;

}

int main(){
	
	int count = 0;
	for(int i = 1; i < 9; ++i) {
		if(connectedComponents(i))
			++count;
	}

	cout << count << endl;
	return 0;
}

