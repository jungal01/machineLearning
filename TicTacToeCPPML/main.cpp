/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: leekentd
 *
 * Created on January 12, 2018, 1:37 PM
 */

#include <cstdlib>
#include "Board.h"
#include <iostream>

using namespace std;

int minimax(Board& board, char player) {
        int i,j,val;
        int gameVal = board.eval();
        //cout << "In minimax" << endl;

        if (abs(gameVal) == 1) {
            return gameVal;
        }

        if (board.full())
            return 0;

        if (player == Computer) {
            int maxVal = -2;

            for (i=0;i<3;i++) {
                for (j=0;j<3;j++) {
                    if (board.data[i][j] == Dummy) {
                        board.data[i][j] = Computer;
                        val = minimax(board, Human);
                        board.data[i][j] = Dummy;

                        if (val == 1)
                            return val;

                        if (val > maxVal) {
                            maxVal = val;
                        }
                    }

                }
            }

            return maxVal;
        } else { // Human Turn
            int minVal = 2;

            for (i=0;i<3;i++) {
                for (j=0;j<3;j++) {
                    if (board.data[i][j] == Dummy) {
                        board.data[i][j] = Human;
                        val = minimax(board, Computer);
                        board.data[i][j] = Dummy;

                        if (val == -1)
                            return val;

                        if (val < minVal) {
                            minVal = val;
                        }
                    }

                }
            }

            return minVal;
        }
    }



int main(int argc, char** argv) {

    Board board;
    
    minimax(board, Computer);
    minimax(board, Human);
    cout << "Done" << endl;
    return 0;
}

