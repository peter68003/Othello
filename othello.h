/**
Name: Po-Yi, Lin (Peter)
Email: pl757117@ohio.edu
*/
#include <iostream>
#include <cctype>
#include "game.h"
#include "piece.h"
#include "colors.h"
using namespace main_savitch_14;

class Othello: public game{
    public:
    Othello();
    bool is_legal(const string &move) const;
    void display_status() const;
    void restart();
    void make_move(const string &move);
    game* clone() const;
    void compute_moves(queue<string>& moves) const;
    int evaluate() const;
    void pass();
    int get_c_passes() const;
    int get_h_passes() const;
    bool is_game_over() const;
    who winning() const;
    private:
    piece board[8][8];
    int H_passes;
    int C_passes;
};