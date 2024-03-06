#include <iostream>
#include <vector>


void display(std::vector<std::vector<bool>> board){

    for(const auto& levels : board) {
        for(const auto& knights : levels) {
            if(knights)
                std::cout << "K" << " ";
            else
                std::cout << "0" << " ";
        }
        std::cout << std::endl;
    }

}


bool isSafe(std::vector<std::vector<bool>> &board, int row, int colum) {
    // upper cases
    if(row - 2 >= 0 && colum + 1 < board.size() && board[row - 2][colum + 1])
        return false;
    
    if(row - 1 >= 0 && colum + 2 < board.size() && board[row - 1][colum + 2])
        return false;
        
    if(row - 2 >= 0 && colum - 1 >= 0 && board[row - 2][colum - 1])
        return false;

    if(row - 1 >= 0 && colum - 2 >= 0 && board[row - 1][colum - 2])
        return false;

    // down cases
    if(row + 1 < board.size() && colum + 2 < board.size() && board[row + 1][colum + 2])
        return false;
    
    if(row + 2 < board.size() && colum + 1 < board.size() && board[row + 2][colum + 1])
        return false;
    
    if(row + 2 < board.size() && colum - 1 >= 0 && board[row + 2][colum - 1])
        return false;
    
    if(row + 1 < board.size() && colum - 2 >= 0 && board[row + 1][colum - 2])
        return false;

    return true;
}


int n_knights(std::vector<std::vector<bool>> board, int r) {

    // base condition
    if(r == board.size()) {
        display(board);
        std::cout << std::endl;
        return 1;
    }

    int count = 0;
    // place a knight and check for every row and colum
    for(int col = 0; col < board.size(); ++col) {
        //place a knight if is safe
        if(isSafe(board,r,col)) {
            board[r][col] = 1;
            count += n_knights(board,r+1);
            board[r][col] = 0; // backtracking
        }
    }

    return count;

}



int main(void) {

    int n;
    std::cin >> n;

    std::vector<std::vector<bool>> board(n, std::vector<bool>(n,0));
    std::cout << "qtd de casos: " << n_knights(board,0) << std::endl;

}




