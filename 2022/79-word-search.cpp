// Set Matrix Zeroes
// https://leetcode.com/problems/word-search/

#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#if 0
struct StackElem {
    int r;
    int c;
    int s;
    char prev;
};

class Solution {
   public:
    bool search(std::vector<std::vector<char>>& board, std::string& word, int r,
                int c) {
        std::stack<StackElem> stack;
        stack.push({r, c, 0, 0});
        while (!stack.empty()) {
            StackElem top = stack.top();
            stack.pop();

            if (board[top.r][top.c] != word[top.s]) {
                continue;
            }

            if (top.s == word.length() - 1) {
                return true;
            }

            if (top.r - 1 >= 0) {
                if (board[top.r - 1][top.c] != top.prev) {
                    if (board[top.r - 1][top.c] == word[top.s + 1]) {
                        stack.push({top.r - 1, top.c, top.s + 1, word[top.s]});
                    }
                }
            }
            if (top.r + 1 < board.size()) {
                if (board[top.r + 1][top.c] != top.prev) {
                    if (board[top.r + 1][top.c] == word[top.s + 1]) {
                        stack.push({top.r + 1, top.c, top.s + 1, word[top.s]});
                    }
                }
            }
            if (top.c - 1 >= 0) {
                if (board[top.r][top.c - 1] != top.prev) {
                    if (board[top.r][top.c - 1] == word[top.s + 1]) {
                        stack.push({top.r, top.c - 1, top.s + 1, word[top.s]});
                    }
                }
            }
            if (top.c + 1 < board[0].size()) {
                if (board[top.r][top.c + 1] != top.prev) {
                    if (board[top.r][top.c + 1] == word[top.s + 1]) {
                        stack.push({top.r, top.c + 1, top.s + 1, word[top.s]});
                    }
                }
            }
        }
        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (search(board, word, r, c)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board;
    // board.push_back({'A', 'B', 'C', 'E'});
    // board.push_back({'S', 'F', 'C', 'S'});
    // board.push_back({'A', 'D', 'E', 'E'});
    // bool res = s.exist(board, "ABCB");
    board.push_back({'A'});
    bool res = s.exist(board, "B");
    std::cout << res << std::endl;
}
#endif

class Solution {
   public:
    bool search(std::vector<std::vector<char>>& board, std::string& word, int r,
                int c, int s, char prev) {
        if (board[r][c] == word[s]) {
            if (s == word.size() - 1) {
                return true;
            }

            bool r1 = false, r2 = false, r3 = false, r4 = false;
            if (r - 1 >= 0) {
                if (board[r - 1][c] != prev) {
                    r1 = search(board, word, r - 1, c, s + 1, word[s]);
                }
            }
            if (r + 1 < board.size()) {
                if (board[r + 1][c] != prev) {
                    r2 = search(board, word, r + 1, c, s + 1, word[s]);
                }
            }
            if (c - 1 >= 0) {
                if (board[r][c - 1] != prev) {
                    r3 = search(board, word, r, c - 1, s + 1, word[s]);
                }
            }
            if (c + 1 < board[0].size()) {
                if (board[r][c + 1] != prev) {
                    r4 = search(board, word, r, c + 1, s + 1, word[s]);
                }
            }
            return r1 | r2 | r3 | r4;
        }
        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[r].size(); c++) {
                if (search(board, word, r, c, 0, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board;
    board.push_back({'A', 'B', 'C', 'E'});
    board.push_back({'S', 'F', 'E', 'S'});
    board.push_back({'A', 'D', 'E', 'E'});
    bool res = s.exist(board, "ABCESEEEFS");
    std::cout << res << std::endl;
}