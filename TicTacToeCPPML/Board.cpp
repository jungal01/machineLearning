/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.cpp
 * Author: leekentd
 * 
 * Created on January 12, 2018, 1:37 PM
 */

#include "Board.h"
#include <stdlib.h>

Board::Board() {
    int i;
    
    for (i=0;i<3;i++)
        data.push_back(vector<char>(3));
}

Board::Board(const Board& orig) {
    data = orig.data;
}

Board::~Board() {
}

int Board::eval() {


    int i, j;

    int diag1Sum = 0;
    int diag2Sum = 0;

    for (i = 0; i < 3; i++) {
        int rowSum = 0;
        int colSum = 0;
        diag1Sum += data[i][i];
        diag2Sum += data[i][2 - i];

        for (j = 0; j < 3; j++) {
            rowSum += data[i][j];
            colSum += data[j][i];
        }

        if (abs(rowSum) == 3)
            return rowSum / 3;

        if (abs(colSum) == 3)
            return colSum / 3;
    }

    if (abs(diag1Sum) == 3)
        return diag1Sum / 3;

    if (abs(diag2Sum) == 3)
        return diag2Sum / 3;

    return 0;
}

bool Board::full() {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (data[i][j] == Dummy)
                return false;
        }
    }

    return true;
}