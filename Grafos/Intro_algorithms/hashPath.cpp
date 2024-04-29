#include <bits/stdc++.h>
using namespace std;

unordered_map<char,list<char>> g {
	{'f', {'g','i'}},
	{'g', {'h'}},
	{'h', {}},
	{'i', {'g','k'}},
	{'j', {'i'}},
	{'k', {}},
};

bool hashPath(char pointA, char pointB) {

	// base case	
	if(pointA == pointB)
		return true;

	for(auto x : g[pointA]) {
		if(hashPath(x,pointB))
			return true;
	}

	return false;
}

int main(){

	cout << (hashPath('f','k') ? "true" : "false") << endl;
	return 0;

}
