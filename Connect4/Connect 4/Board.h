/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: jungal01
 *
 * Created on January 18, 2018, 10:32 AM
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
    unsigned char eval();
    bool full();
    std::vector<std::vector<unsigned char> > data; 
    unsigned char boardhash();
};

#endif /* BOARD_H */

