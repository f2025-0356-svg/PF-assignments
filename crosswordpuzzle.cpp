#include <iostream>
using namespace std;

int rows = 5;
int cols = 5;


void inputPuzzle(char grid[5][5]) {
    cout << "Enter puzzle (use  dot (.) for empty): "   << endl;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
}


int countHorizontal(char grid[5][5]) {
    int count = 0;
    for(int i = 0; i < rows; i++) {
        int len = 0;
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] != '.') len++;
            else {
                if(len >= 3) count++;
                len = 0;
            }
        }
        if(len >= 3) count++;
    }
    return count;
}


int countVertical(char grid[5][5]) {
    int count = 0;
    for(int j = 0; j < cols; j++) {
        int len = 0;
        for(int i = 0; i < rows; i++) {
            if(grid[i][j] != '.') len++;
            else {
                if(len >= 3) count++;
                len = 0;
            }
        }
        if(len >= 3) count++;
    }
    return count;
}


void longestWord(char grid[5][5], char longest[]) {
    int maxLen = 0, len = 0;

    for(int i = 0; i < rows; i++) {
        len = 0;
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] != '.') {
                longest[len] = grid[i][j];
                len++;
            }
            else {
                if(len > maxLen) maxLen = len;
                len = 0;
            }
        }
        if(len > maxLen) maxLen = len;
    }
    longest[maxLen] = '\0';
}

int main() {
    char puzzle[5][5];
    char longest[25];

    inputPuzzle(puzzle);

    cout << "Horizontal words: " << countHorizontal(puzzle) << endl;
    cout << "Vertical words: " << countVertical(puzzle) << endl;

    longestWord(puzzle, longest);
    cout << "Longest word: " << longest << endl;

    return 0;
}
