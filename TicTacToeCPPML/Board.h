/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: leekentd
 *
 * Created on January 12, 2018, 1:37 PM
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>

using namespace std;

const char Human = -1;
const char Computer = 1;
const char Dummy = 0;

class Board {
public:
    Board();
    Board(const Board& orig);
    virtual ~Board();
    int eval();
    bool full();
    std::vector<std::vector<char> > data; 
};

#endif /* BOARD_H */

