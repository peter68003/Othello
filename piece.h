/**
Name: Po-Yi, Lin (Peter)
Email: pl757117@ohio.edu
*/
#include <iostream>
#include <array>
#include "colors.h"
using namespace std;
#ifndef PIECE_H
#define PIECE_H

class piece{
    public:
    piece();
    bool is_white() const;
    bool is_black() const;
    bool is_empty() const;
    void set_white() {s_color = 'O';}
    void set_black() {s_color = 'X';}
    void set_empty() {s_color = ' ';}
    void flip();
    void output_color() const;
    char get_color() const {return s_color;}
    private:
    char s_color;
    char white;
    char black;
    char empty;
};
#endif