#include <iostream>
#include <vector>

bool isSafe(const std::vector<std::vector<bool>>& board, int r, int c) {
    int max = board.size();

    // check vertical row
    for(int i = 0; i < r; ++i) {
        if(board[i][c])
            return false;
    }

    // check diagonal left
    for(int i = 1; r - i >= 0 && c - i >= 0; ++i) {
        if(board[r-i][c-i])
            return false;
    }

    // check diagonal right
    for(int i = 1; r - i >= 0 && c + i < max; ++i) {
        if(board[r-i][c+i])
            return false;
    }

    return true;
}



void displayBoard(std::vector<std::vector<bool>> board) {

    for(const auto& row : board) {
        for(const auto& colum : row) {
            if(colum)
                std::cout << "Q" << " ";
            else
                std::cout << "0" << " ";
        }
        std::cout << std::endl;
    }

}


int nQueens(std::vector<std::vector<bool>> board, int r) {

    // base case 
    // when we arrive at the final of the board
    if(r == board.size()) {
        displayBoard(board);
        std::cout << std::endl;
        return 1;
    }

    int count = 0;
    // place queen and checking for every row and colum
    for(int col = 0; col < board.size(); ++col) {
        // place the queen if it's safe
        if(isSafe(board,r,col)) {
            board[r][col] = 1;
            count += nQueens(board, r+1);
            board[r][col] = 0; // backtracking
        }
    }

    return count;

}


int main(void) {

    int n;
    std::cin >> n;

    std::vector<std::vector<bool>> board(n,std::vector<bool>(n,0));
    std::cout << "Quantidade de configuracoes: " << nQueens(board,0) << std::endl;


}




