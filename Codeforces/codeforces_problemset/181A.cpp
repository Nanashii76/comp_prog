#include <bits/stdc++.h>


void solve(){

    std::vector<std::pair<int,int>> vecp;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            if(vec[i][j] == '*')
                vecp.push_back(std::make_pair(i,j));        
        }   

    for(int i = 0; i < vecp.size(); ++i)
        std::cout << vecp[i].first << " " << vecp[i].second << " ";
    
}



int main(void) {
    
    int n,m; std::cin >> n >> m;

    std::vector<std::vector<char>> vec(n, std::vector<char>(m));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            char aux; std::cin >> aux;
            vec[i][j] = aux;        
        }
            
    solve();
}
