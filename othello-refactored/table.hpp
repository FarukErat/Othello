#pragma once
#ifndef REVERSI
#define REVERSI

#include <ctime> // time()
#include <conio.h> // getche()

#include <string>
using std::stoi;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;

#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;

#include "os_dependent_functions.hpp"

#define BOARD_SIZE 8
// board has (BOARD_SIZE x BOARD_SIZE) elements
// 4 of them are initialized and no move can be made on them
// it makes (BOARD_SIZE * BOARD_SIZE - 4)
// moves are saved "row.column|" format
// so it is multiplied by 4
#define FILE_LENGTH (BOARD_SIZE * BOARD_SIZE - 4) * 4

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '-'
#define LEGAL '+'

// vectors of 8 directions
const int DIRS[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},
                         {0, -1},           {0, 1},
                         {1, -1}, {1, 0}, {1, 1} };

typedef enum {
    HUMAN,
    CPU
} Player;

typedef enum {
    NEW_GAME,
    LOAD_GAME
} GameMode;

struct Position {
public:
    int row, col;
};

class Table {
private:
    // variables
    vector<Position> moves;
    char board[BOARD_SIZE][BOARD_SIZE];
    bool hint = true;
    int moveCount = 0;
    char turn = BLACK;
    Player blackPlayer;
    Player whitePlayer;
    GameMode gameMode;

    // methods
    void printBoard();
    bool isOnBoard(Position p);
    void setBoard(Position p, char state);
    char getState(Position p);
    bool isOccupied(Position p);
    bool isEmpty(Position p);
    bool isLegal(Position p);
    void markLegalMoves();
    void switchTurn();
    bool hasTileToFlip();
    void flipTiles(Position p);
    Position getRandomMove();
    Position getMoveFromCPU(unsigned delayInMs);
    Position getMoveFromUser();
    void displaySettings();
    void displayEndGame();
    void saveMovesToFile(const char* fileName);
    void loadMovesFromFile(const char* fileName);
    Position getStoredMove(unsigned delayInMs);
    bool isStoredMovesValid();
    void newGame();
    void loadGame();

public:
    Table();
    void play();
};

void Table::printBoard() {
    clearScreen();
    int row, col;
    // print the column numbers
    cout << " ";
    for (row = 0; row < BOARD_SIZE; row++) {
        cout << " " << row + 1;
    }
    cout << "\n";
    // print rows
    for (row = 0; row < BOARD_SIZE; row++) {
        cout << row + 1 << " ";
        for (col = 0; col < BOARD_SIZE; col++) {
            // in case user does not want guidance
            // legal squares are hidden with EMPTY
            if (!hint) {
                if (board[row][col] == LEGAL) {
                    cout << EMPTY << " ";
                    continue;
                }
            }
            // printing the tiles
            cout << board[row][col] << " ";
        }
        cout << row + 1;
        cout << "\n";
    }
    // print the column numbers again
    cout << " ";
    for (row = 0; row < BOARD_SIZE; row++) {
        cout << " " << row + 1;
    }
    cout << "\n";
}

bool Table::isOnBoard(Position p) {
    return p.row >= 0 && p.row < BOARD_SIZE &&
        p.col >= 0 && p.col < BOARD_SIZE;
}

void Table::setBoard(Position p, char state) {
    if (isOnBoard(p)) {
        board[p.row][p.col] = state;
    }
    else {
        throw "Position not on board";
    }
}

char Table::getState(Position p) {
    if (isOnBoard(p)) {
        return board[p.row][p.col];
    }
    throw "Position not on board";
}

bool Table::isOccupied(Position p) {
    if (getState(p) == BLACK ||
        getState(p) == WHITE) {
        return true;
    }
    return false;
}

bool Table::isEmpty(Position p) {
    return !isOccupied(p);
}

bool Table::isLegal(Position p) {
    if (!isOnBoard(p)) {
        return false;
    }
    if (isOccupied(p)) {
        return false;
    }
    Position current(p);
    bool flip = false;
    for (auto dir : DIRS) {
        flip = false;
        for (int i = 1;; i++) {
            current.row = p.row + dir[0] * i;
            current.col = p.col + dir[1] * i;

            if (!isOnBoard(current)) {
                break;
            }
            if (isEmpty(current)) {
                break;
            }
            if (getState(current) != turn) {
                flip = true;
                continue;
            }

            // if the square is that of the current player
            // and at least one tile is flipped
            // then it is a legal move
            if (getState(current) == turn) {
                if (flip) {
                    return true;
                }
                else {
                    break;
                }
            }
        }
    }
    return false;
}

void Table::markLegalMoves() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (isOccupied({ row, col })) {
                continue;
            }
            if (isLegal({ row, col })) {
                setBoard({ row, col }, LEGAL);
            }
            else {
                setBoard({ row, col }, EMPTY);
            }
        }
    }
}

void Table::switchTurn() {
    if (turn == BLACK) {
        turn = WHITE;
    }
    else {
        turn = BLACK;
    }
    markLegalMoves();
}

bool Table::hasTileToFlip() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (getState({ row, col }) == LEGAL) {
                return true;
            }
        }
    }
    return false;
}

void Table::flipTiles(Position move) {
    if (!isOnBoard(move)) {
        return;
    }
    if (isOccupied(move)) {
        return;
    }
    Position current(move), toFlip;
    bool flip = false;
    for (auto dir : DIRS) {
        flip = false;
        for (int i = 1;; i++) {
            current.row = move.row + dir[0] * i;
            current.col = move.col + dir[1] * i;

            if (!isOnBoard(current)) {
                break;
            }
            if (isEmpty(current)) {
                break;
            }

            if (getState(current) != turn) {
                flip = true;
            }
            else {
                if (!flip) {
                    break;
                }

                // toFlip is assigned the numbers along the legal direction
                // to flip the tiles between current and move
                // [current]-<-<-<-[toFlip]-<-<-<-[move]
                toFlip.row = move.row;
                toFlip.col = move.col;

                // horizontal
                if (dir[0] == 0) {
                    while (toFlip.col != current.col) {
                        setBoard(toFlip, turn);
                        toFlip.col += dir[1];
                    }
                }
                // vertical
                else if (dir[1] == 0) {
                    while (toFlip.row != current.row) {
                        setBoard(toFlip, turn);
                        toFlip.row += dir[0];
                    }
                }
                // diagonal
                else {
                    while (toFlip.row != current.row && toFlip.col != current.col) {
                        setBoard(toFlip, turn);
                        toFlip.row += dir[0];
                        toFlip.col += dir[1];
                    }
                }
                break;
            }
        }
    }
}

Position Table::getRandomMove() {
    srand(time(NULL));

    vector<Position> legalMoves;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (getState({ row, col }) == LEGAL) {
                legalMoves.push_back({ row, col });
            }
        }
    }

    vector<Position> movesToCorners;
    for (int i = 0; i < legalMoves.size(); i++) {
        // upper left
        if (legalMoves[i].row == 0 && legalMoves[i].col == 0) {
            movesToCorners.push_back(legalMoves[i]);
            continue;
        }
        // upper right
        if (legalMoves[i].row == 0 && legalMoves[i].col == BOARD_SIZE - 1) {
            movesToCorners.push_back(legalMoves[i]);
            continue;
        }
        // lower right
        if (legalMoves[i].row == BOARD_SIZE - 1 && legalMoves[i].col == BOARD_SIZE - 1) {
            movesToCorners.push_back(legalMoves[i]);
            continue;
        }
        // lower left
        if (legalMoves[i].row == BOARD_SIZE - 1 && legalMoves[i].col == 0) {
            movesToCorners.push_back(legalMoves[i]);
        }
    }
    if (movesToCorners.size() != 0) {
        return movesToCorners[rand() % movesToCorners.size()];
    }

    // remove the moves on X squares
    for (int i = 0; i < legalMoves.size() && legalMoves.size() > 1; i++) {
        // upper left
        if (legalMoves[i].row == 1 && legalMoves[i].col == 1) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // upper right
        if (legalMoves[i].row == 1 && legalMoves[i].col == BOARD_SIZE - 2) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // lower right
        if (legalMoves[i].row == BOARD_SIZE - 2 && legalMoves[i].col == BOARD_SIZE - 2) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // lower left
        if (legalMoves[i].row == BOARD_SIZE - 2 && legalMoves[i].col == 1) {
            legalMoves.erase(legalMoves.begin() + i);
        }
    }

    // remove the moves on C squares
    for (int i = 0; i < legalMoves.size() && legalMoves.size() > 1; i++) {
        // upper left
        if (legalMoves[i].row == 0 && legalMoves[i].col == 1) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == 1 && legalMoves[i].col == 0) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // upper right
        if (legalMoves[i].row == 0 && legalMoves[i].col == BOARD_SIZE - 2) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == 1 && legalMoves[i].col == BOARD_SIZE - 1) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // lower right
        if (legalMoves[i].row == BOARD_SIZE - 1 && legalMoves[i].col == BOARD_SIZE - 2) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == BOARD_SIZE - 2 && legalMoves[i].col == BOARD_SIZE - 1) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // lower left
        if (legalMoves[i].row == BOARD_SIZE - 1 && legalMoves[i].col == 1) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == BOARD_SIZE - 2 && legalMoves[i].col == 0) {
            legalMoves.erase(legalMoves.begin() + i);
        }
    }

    // remove the moves on B squares
    for (int i = 0; i < legalMoves.size() && legalMoves.size() > 1; i++) {
        // upper left
        if (legalMoves[i].row == 0 && legalMoves[i].col == 3) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == 3 && legalMoves[i].col == 0) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // upper right
        if (legalMoves[i].row == 0 && legalMoves[i].col == BOARD_SIZE - 4) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == 3 && legalMoves[i].col == BOARD_SIZE - 1) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // lower right
        if (legalMoves[i].row == BOARD_SIZE - 1 && legalMoves[i].col == BOARD_SIZE - 4) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == BOARD_SIZE - 4 && legalMoves[i].col == BOARD_SIZE - 1) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        // lower left
        if (legalMoves[i].row == BOARD_SIZE - 1 && legalMoves[i].col == 3) {
            legalMoves.erase(legalMoves.begin() + i);
            continue;
        }
        if (legalMoves[i].row == BOARD_SIZE - 4 && legalMoves[i].col == 0) {
            legalMoves.erase(legalMoves.begin() + i);
        }
    }

    return legalMoves[rand() % legalMoves.size()];
}

Position Table::getMoveFromCPU(unsigned delayInMs) {
    Position c(getRandomMove());
    sleep(delayInMs / 2);
    cout << "row: " << c.row + 1 << "\n";
    cout << "col: " << c.col + 1 << "\n";
    sleep(delayInMs);
    return c;
}

Position Table::getMoveFromUser() {
    Position c;
    while (true) {
        cout << "row and col\n";
        cin >> c.row >> c.col;

        // to match the index of the array
        c.row--;
        c.col--;
        if (!isOnBoard(c)) {
            cout << "Invalid position\nEnter again\n\n";
            continue;
        }
        if (getState(c) == LEGAL) {
            return c;
        }

        cout << "\nInvalid position\nEnter again\n\n";
    }
}

void Table::displaySettings() {
    char choice;
    // game mode
    clearScreen();
    cout << "Game mode:\n1: New game\n2: Load game\nDefault: New game\n";
    choice = getche();
    switch (choice) {
    case '1':
        gameMode = NEW_GAME;
        break;
    case '2':
        gameMode = LOAD_GAME;
        cout << "\nEnter file name: ";
        {
            char fileName[100];
            cin >> fileName;
            fstream file;
            try {
                file.open(fileName);
            }
            catch (...) {
                cout << "\nError opening file";
                exit(1);
            }
            if (!file.is_open()) {
                cout << "\nError opening file";
                exit(1);
            }
            file.close();
            loadMovesFromFile(fileName);
            if (!isStoredMovesValid()) {
                cout << "\nFile is corrupted";
                exit(1);
            }
        }
        break;
    default:
        gameMode = NEW_GAME;
        break;
    }
    // hint
    clearScreen();
    cout << "\nHint:\n1. On\n2. Off\nDefault: On\n";
    choice = getche();
    switch (choice) {
    case '1':
        hint = true;
        break;
    case '2':
        hint = false;
        break;
    default:
        hint = true;
        break;
    }
    if (gameMode == LOAD_GAME) {
        return;
    }
    // black player
    clearScreen();
    cout << "\nBlack player:\n1. Human\n2. CPU\nDefault: CPU\n";
    choice = getche();
    switch (choice) {
    case '1':
        blackPlayer = HUMAN;
        break;
    case '2':
        blackPlayer = CPU;
        break;
    default:
        blackPlayer = CPU;
        break;
    }
    // white player
    clearScreen();
    cout << "\nWhite player:\n1. Human\n2. CPU\nDefault: CPU\n";
    choice = getche();
    switch (choice) {
    case '1':
        whitePlayer = HUMAN;
        break;
    case '2':
        whitePlayer = CPU;
        break;
    default:
        whitePlayer = CPU;
        break;
    }
}

void Table::displayEndGame() {
    int blacks = 0;
    int whites = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (getState({ row, col }) == BLACK) {
                blacks++;
            }
            if (getState({ row, col }) == WHITE) {
                whites++;
            }
        }
    }
    cout << "\nGAME OVER\n";
    if (blacks > whites) {
        cout << "Black wins\n";
    }
    else if (blacks < whites) {
        cout << "White wins\n";
    }
    else {
        cout << "Draw\n";
    }
    cout << "Black: " << blacks << "\n";
    cout << "White: " << whites << "\n";
}

void Table::saveMovesToFile(const char* fileName) {
    ofstream file;
    try {
        file.open(fileName);
    }
    catch (...) {
        cout << "Error opening file.\n";
        exit(1);
    }
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        exit(1);
    }
    for (int i = 0; i < moves.size(); i++) {
        file << moves[i].row << "," << moves[i].col << "|";
    }
    file.close();
}

void Table::loadMovesFromFile(const char* fileName) {
    ifstream file;
    char text[FILE_LENGTH];
    try {
        file.open(fileName);
    }
    catch (...) {
        cout << "Error opening file.\n";
        exit(1);
    } if (!file.is_open()) {
        cout << "Error opening file.\n";
        exit(1);
    }
    file.getline(text, FILE_LENGTH);
    file.close();
    Position c;
    char* ptr = strtok(text, ",");
    while (ptr != NULL) {
        c.row = stoi(ptr);
        ptr = strtok(NULL, "|");
        c.col = stoi(ptr);
        moves.push_back(c);
        ptr = strtok(NULL, ",");
    }
}

Position Table::getStoredMove(unsigned delayInMs) {
    Position p = moves[moveCount++];
    sleep(delayInMs / 2);
    cout << "row: " << p.row + 1 << "\n";
    cout << "col: " << p.col + 1 << "\n";
    sleep(delayInMs);
    return p;
}

bool Table::isStoredMovesValid() {
    if (moves.size() == 0) {
        return false;
    }
    Position move;
    while (true) {
        if (!hasTileToFlip()) {
            break;
        }
        move = moves[moveCount++];
        if (!isLegal(move)) {
            return false;
        }
        flipTiles(move);
        switchTurn();
        if (!hasTileToFlip()) {
            switchTurn();
        }
    }
    // revert changes
    moveCount = 0;
    turn = BLACK;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY;
        }
    }
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = BLACK;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = BLACK;
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = WHITE;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2] = WHITE;
    markLegalMoves();
    // Table* _ = new (this)Table();
    return true;
}

void Table::newGame() {
    Position move;
    // game loop
    while (true) {
        printBoard();
        if (!hasTileToFlip()) {
            break;
        }
        if (turn == BLACK) {
            cout << "Black\n";
            if (blackPlayer == HUMAN) {
                move = getMoveFromUser();
            }
            else {
                move = getMoveFromCPU(1000);
            }
        }
        else {
            cout << "White\n";
            if (whitePlayer == HUMAN) {
                move = getMoveFromUser();
            }
            else {
                move = getMoveFromCPU(1000);
            }
            cout << "\nWhite\n";
        }
        flipTiles(move);
        moves.push_back(move);
        switchTurn();
        if (!hasTileToFlip()) {
            switchTurn();
        }
    }
    displayEndGame();
    cout << "\n1. Save moves\n2. Exit\nDefault: Exit\n";
    char choice = getche();
    if (choice == '1') {
        char fileName[100];
        cout << "\nEnter file name\n";
        cin >> fileName;
        saveMovesToFile(fileName);
        cout << "\nMoves saved\n";
    }
}

void Table::loadGame() {
    Position move;
    // game loop
    while (true) {
        printBoard();
        if (!hasTileToFlip()) {
            break;
        }
        if (turn == BLACK) {
            cout << "Black\n";
        }
        else {
            cout << "White\n";
        }
        move = getStoredMove(1000);
        flipTiles(move);
        moves.push_back(move);
        switchTurn();
        if (!hasTileToFlip()) {
            switchTurn();
        }
    }
    displayEndGame();
}

Table::Table() {
    // check the size of the board
    if (BOARD_SIZE % 2 != 0 || BOARD_SIZE < 4) {
        throw "Size should be even and greater than 3";
    }
    // check the colors
    if (BLACK == WHITE ||
        BLACK == EMPTY ||
        BLACK == LEGAL ||
        WHITE == EMPTY ||
        WHITE == LEGAL ||
        EMPTY == LEGAL) {
        throw "One or more colors are the same";
    }
    // initialize the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY;
        }
    }
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = BLACK;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = BLACK;
    board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = WHITE;
    board[BOARD_SIZE / 2][BOARD_SIZE / 2] = WHITE;
    // mark legal moves
    markLegalMoves();
}

void Table::play() {
    displaySettings();
    switch (gameMode) {
    case NEW_GAME:
        newGame();
        break;
    case LOAD_GAME:
        loadGame();
        break;
    }
}

#endif // REVERSI
