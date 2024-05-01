#include<bits/stdc++.h>
using namespace std;

struct Coord {
    int row;
    int col;
    Coord(int r, int c) : row(r), col(c) {}
};

void countingRooms(vector<vector<char>> &g, int startRow, int startCol) {
    stack<Coord> stk;
    stk.push(Coord(startRow, startCol));

    while (!stk.empty()) {
        Coord current = stk.top();
        stk.pop();

        int r = current.row;
        int c = current.col;

        // Verifica se a posição atual é válida e não visitada
        if (r >= 0 and r < (int)g.size() and c >= 0 and c < (int)g[0].size() and g[r][c] == '.') {
            g[r][c] = '#'; // Marca como visitada

            // Empilha os vizinhos não visitados
            stk.push(Coord(r + 1, c)); // Down
            stk.push(Coord(r - 1, c)); // Up
            stk.push(Coord(r, c + 1)); // Right
            stk.push(Coord(r, c - 1)); // Left
        }
    }
}

int main() {

    int n, m; cin >> n >> m;
    int count = 0;
    vector<vector<char>> g(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.') {
                countingRooms(g, i, j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
