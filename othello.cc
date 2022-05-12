/**
Name: Po-Yi, Lin (Peter)
Email: pl757117@ohio.edu
*/
#include <iostream>
#include <cctype>
#include <string>
#include "othello.h"
#include "game.h"
using namespace main_savitch_14;

Othello::Othello(){
    for(int j = 0; j < 8; j++){
        for(int i = 0; i < 8; i++){
            board[j][i].set_empty();
        }
    }
    board[3][3].set_white();
    board[3][4].set_black();
    board[4][3].set_black();
    board[4][4].set_white();
    H_passes = 0;
    C_passes = 0;
    game::restart();
}

bool Othello::is_legal(const string &move) const{
    int row, col, tmp_c, tmp_r, tmp;
    bool legal = false;
    row = int(toupper(move.at(0)) - 'A');
    col = int(move.at(1) - '1');
    tmp = game::moves_completed();
    if(row < 0 || row > 7 || col < 0 || col > 7){
        cout << "Error: Your move must be inside of A1 - H8." << endl;
        return false;
    }

    if(board[col][row].is_black() || board[col][row].is_white()){
        return false;
    }
    if((tmp % 2) == 0){
        if(board[col-1][row].is_white() && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c -1][tmp_r].is_white()){
                tmp_c--;
                if(board[tmp_c -1][tmp_r].is_black()){
                    return true;
                } else if(board[tmp_c - 1][tmp_r].is_empty() || tmp_c == 0){
                    legal = false;
                }
            }
        }
        if(board[col][row+1].is_white() && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r + 1].is_white()){
                tmp_r++;
                if(board[tmp_c][tmp_r+1].is_black()){
                    return true;
                } else if(board[tmp_c][tmp_r+1].is_empty() || tmp_r == 7){
                    legal = false;
                }
            }
        }
        if(board[col][row-1].is_white() && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r-1].is_white()){
                tmp_r--;
                if(board[tmp_c][tmp_r-1].is_black()){
                    return true;
                } else if(board[tmp_c][tmp_r-1].is_empty() || tmp_r == 0){
                    legal = false;
                }
            }
        }
        if(board[col+1][row].is_white() && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c +1][tmp_r].is_white()){
                tmp_c++;
                if(board[tmp_c +1][tmp_r].is_black()){
                    return true;
                } else if(board[tmp_c +1][tmp_r].is_empty() || tmp_c == 7){
                    return false;
                }
            }
        }
        if(board[col -1][row+1].is_white() && col != 0 && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c - 1][tmp_r + 1].is_white()){
                tmp_c--;
                tmp_r++;
                if(board[tmp_c -1][tmp_r+1].is_black()){
                    return true;
                } else if(board[tmp_c-1][tmp_r+1].is_empty() || tmp_c == 0 || tmp_r == 7){
                    legal = false;
                }
            }
        }
        if(board[col -1][row-1].is_white() && col != 0 && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c - 1][tmp_r - 1].is_white()){
                tmp_c--;
                tmp_r--;
                if(board[tmp_c -1][tmp_r-1].is_black()){
                    return true;
                } else if(board[tmp_c-1][tmp_r-1].is_empty() || tmp_c == 0 || tmp_r == 0){
                    legal = false;
                }
            }
        }
        if(board[col +1][row-1].is_white() && col != 7 && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c + 1][tmp_r - 1].is_white()){
                tmp_c++;
                tmp_r--;
                if(board[tmp_c +1][tmp_r-1].is_black()){
                    return true;
                } else if(board[tmp_c+1][tmp_r-1].is_empty() || tmp_c == 7 || tmp_r == 0){
                    legal = false;
                }
            }
        }
        if(board[col +1][row+1].is_white() && col != 7 && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c + 1][tmp_r + 1].is_white()){
                tmp_c++;
                tmp_r++;
                if(board[tmp_c +1][tmp_r+1].is_black()){
                    return true;
                } else if(board[tmp_c+1][tmp_r+1].is_empty() || tmp_c == 7 || tmp_r == 7){
                    legal = false;
                }
            }
        }
    } else {
        if(board[col-1][row].is_black() && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c -1][tmp_r].is_black()){
                tmp_c--;
                if(board[tmp_c -1][tmp_r].is_white()){
                    return true;
                } else if(board[tmp_c - 1][tmp_r].is_empty() || tmp_c == 0){
                    legal = false;
                }
            }
        }
        if(board[col][row+1].is_black() && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r + 1].is_black()){
                tmp_r++;
                if(board[tmp_c][tmp_r+1].is_white()){
                    return true;
                } else if(board[tmp_c][tmp_r+1].is_empty() || tmp_r == 7){
                    legal = false;
                }
            }
        }
        if(board[col][row-1].is_black() && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r-1].is_black()){
                tmp_r--;
                if(board[tmp_c][tmp_r-1].is_white()){
                    return true;
                } else if(board[tmp_c][tmp_r-1].is_empty() || tmp_r == 0){
                    legal = false;
                }
            }
        }
        if(board[col+1][row].is_black() && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c +1][tmp_r].is_black()){
                tmp_c++;
                if(board[tmp_c +1][tmp_r].is_white()){
                    return true;
                } else if(board[tmp_c +1][tmp_r].is_empty() || tmp_c == 7){
                    return false;
                }
            }
        }
        if(board[col -1][row+1].is_black() && col != 0 && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c - 1][tmp_r + 1].is_black()){
                tmp_c--;
                tmp_r++;
                if(board[tmp_c -1][tmp_r+1].is_white()){
                    return true;
                } else if(board[tmp_c-1][tmp_r+1].is_empty() || tmp_c == 0 || tmp_r == 7){
                    legal = false;
                }
            }
        }
        if(board[col -1][row-1].is_black() && col != 0 && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c - 1][tmp_r - 1].is_black()){
                tmp_c--;
                tmp_r--;
                if(board[tmp_c -1][tmp_r-1].is_white()){
                    return true;
                } else if(board[tmp_c-1][tmp_r-1].is_empty() || tmp_c == 0 || tmp_r == 0){
                    legal = false;
                }
            }
        }
        if(board[col +1][row-1].is_black() && col != 7 && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c + 1][tmp_r - 1].is_black()){
                tmp_c++;
                tmp_r--;
                if(board[tmp_c +1][tmp_r-1].is_white()){
                    return true;
                } else if(board[tmp_c+1][tmp_r-1].is_empty() || tmp_c == 7 || tmp_r == 0){
                    legal = false;
                }
            }
        }
        if(board[col +1][row+1].is_black() && col != 7 && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c + 1][tmp_r + 1].is_black()){
                tmp_c++;
                tmp_r++;
                if(board[tmp_c +1][tmp_r+1].is_white()){
                    return true;
                } else if(board[tmp_c+1][tmp_r+1].is_empty() || tmp_c == 7 || tmp_r == 7){
                    legal = false;
                }
            }
        }
    }
    return legal;
}

void Othello::make_move(const string &move){
    int row, col;
    int tmp_c, tmp_r;
    int tmp;
    row = int(toupper(move.at(0)) - 'A');
    col = int(move.at(1) - '1');
    tmp = game::moves_completed();
    if((tmp%2) == 0){
        if(board[col -1][row].is_white() && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c-1][tmp_r].is_white() && tmp_c > 0){ //up
                tmp_c--;
            }
            if(board[tmp_c-1][tmp_r].is_black()){
                while(tmp_c < col){
                    board[tmp_c][tmp_r].flip();
                    tmp_c++;
                }
            }
        }
        if(board[col+1][row].is_white() && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c+1][tmp_r].is_white() && tmp_c < 7){//down
                tmp_c++; 
            }
            if(board[tmp_c+1][tmp_r].is_black()){
                while(tmp_c > col){
                    board[tmp_c][tmp_r].set_black();
                    tmp_c--;
                }
            }
        }
        if(board[col][row+1].is_white() && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r+1].is_white() && tmp_r < 7){//right
                tmp_r++;
            }
            if(board[tmp_c][tmp_r+1].is_black()){
                while(tmp_r > row){
                    board[tmp_c][tmp_r].set_black();
                    tmp_r--;
                }
            }
        }
        if(board[col][row-1].is_white() && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r-1].is_white() && tmp_r > 0){//left
                tmp_r--;
            }
            if(board[tmp_c][tmp_r-1].is_black()){
                while(tmp_r < row){
                    board[tmp_c][tmp_r].set_black();
                    tmp_r++;
                }
            }
        }
        if(board[col-1][row-1].is_white() && row != 0 && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c-1][tmp_r-1].is_white() && tmp_c > 0 && tmp_r > 0){//up left
                tmp_r--;
                tmp_c--;
            }
            if(board[tmp_c-1][tmp_r-1].is_black()){
                while(tmp_c < col){
                    board[tmp_c][tmp_r].set_black();
                    tmp_r++;
                    tmp_c++;
                }
            }
        }
        if(board[col-1][row+1].is_white() && row != 7 && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c-1][tmp_r+1].is_white() && tmp_c > 0 && tmp_r < 7){//up right
                tmp_r++;
                tmp_c--;
            }
            if(board[tmp_c-1][tmp_r+1].is_black()){
                while(tmp_c < col){
                    board[tmp_c][tmp_r].set_black();
                    tmp_r--;
                    tmp_c++;
                }
            }
        }
        if(board[col+1][row-1].is_white() && row != 0 && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c+1][tmp_r-1].is_white() && tmp_c < 7 && tmp_r > 0){//down left
                tmp_r--;
                tmp_c++;
            }
            if(board[tmp_c+1][tmp_r-1].is_black()){
                while(tmp_c > col){
                    board[tmp_c][tmp_r].set_black();
                    tmp_r++;
                    tmp_c--;
                }
            }
        }
        if(board[col+1][row+1].is_white() && row != 7 && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c+1][tmp_r+1].is_white() && tmp_c < 7 && tmp_r < 7){//dow right
                tmp_r++;
                tmp_c++;
            }
            if(board[tmp_c+1][tmp_r+1].is_black()){
                while(tmp_c > col){
                    board[tmp_c][tmp_r].set_black();
                    tmp_r--;
                    tmp_c--;
                }
            }
        }
        board[col][row].set_black();
        game::make_move(move);
        H_passes = 0;
    } else {
        if(board[col -1][row].is_black() && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c-1][tmp_r].is_black() && tmp_c > 0){ //up
                tmp_c--;
            }
            if(board[tmp_c-1][tmp_r].is_white()){
                while(tmp_c < col){
                    board[tmp_c][tmp_r].set_white();
                    tmp_c++;
                }
            }
        }
        if(board[col+1][row].is_black() && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c+1][tmp_r].is_black() && tmp_c < 7){//down
                tmp_c++; 
            }
            if(board[tmp_c+1][tmp_r].is_white()){
                while(tmp_c > col){
                    board[tmp_c][tmp_r].set_white();
                    tmp_c--;
                }
            }
        }
        if(board[col][row+1].is_black() && row != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r+1].is_black() && tmp_r < 7){//right
                tmp_r++;
            }
            if(board[tmp_c][tmp_r+1].is_white()){
                while(tmp_r > row){
                    board[tmp_c][tmp_r].set_white();
                    tmp_r--;
                }
            }
        }
        if(board[col][row-1].is_black() && row != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c][tmp_r-1].is_black() && tmp_r > 0){//left
                tmp_r--;
            }
            if(board[tmp_c][tmp_r-1].is_white()){
                while(tmp_r < row){
                    board[tmp_c][tmp_r].set_white();
                    tmp_r++;
                }
            }
        }
        if(board[col-1][row-1].is_black() && row != 0 && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c-1][tmp_r-1].is_black() && tmp_c > 0 && tmp_r > 0){//up left
                tmp_r--;
                tmp_c--;
            }
            if(board[tmp_c-1][tmp_r-1].is_white()){
                while(tmp_c < col){
                    board[tmp_c][tmp_r].set_white();
                    tmp_r++;
                    tmp_c++;
                }
            }
        }
        if(board[col-1][row+1].is_black() && row != 7 && col != 0){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c-1][tmp_r+1].is_black() && tmp_c > 0 && tmp_r < 7){//up right
                tmp_r++;
                tmp_c--;
            }
            if(board[tmp_c-1][tmp_r+1].is_white()){
                while(tmp_c < col){
                    board[tmp_c][tmp_r].set_white();
                    tmp_r--;
                    tmp_c++;
                }
            }
        }
        if(board[col+1][row-1].is_black() && row != 0 && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c+1][tmp_r-1].is_black() && tmp_c < 7 && tmp_r > 0){//down left
                tmp_r--;
                tmp_c++;
            }
            if(board[tmp_c+1][tmp_r-1].is_white()){
                while(tmp_c > col){
                    board[tmp_c][tmp_r].set_white();
                    tmp_r++;
                    tmp_c--;
                }
            }
        }
        if(board[col+1][row+1].is_black() && row != 7 && col != 7){
            tmp_c = col;
            tmp_r = row;
            while(board[tmp_c+1][tmp_r+1].is_black() && tmp_c < 7 && tmp_r < 7){//dow right
                tmp_r++;
                tmp_c++;
            }
            if(board[tmp_c+1][tmp_r+1].is_white()){
                while(tmp_c > col){
                    board[tmp_c][tmp_r].set_white();
                    tmp_r--;
                    tmp_c--;
                }
            }
        }
        board[col][row].set_white();
        game::make_move(move);
        C_passes = 0;
    }
}

void Othello::restart(){
    for(int j = 0; j < 8; j++){
        for(int i = 0; i < 8; i++){
            board[j][i].set_empty();
        }
    }
    board[3][3].set_white();
    board[3][4].set_black();
    board[4][3].set_black();
    board[4][4].set_white();
    H_passes = 0;
    C_passes = 0;
    game::restart();
}

bool Othello::is_game_over() const{
    int space_used, black_amount, white_amount;
    space_used = black_amount = white_amount = 0;
    for(int j = 0; j < 8; j++){
        for(int i = 0; i < 8; i++){
            if(board[j][i].is_black()){
                black_amount++;
            }else if(board[j][i].is_white()){
                white_amount++;
            }
        }
    }
    space_used = black_amount +white_amount;
    if(space_used == 64 || white_amount == 0 || black_amount == 0){
        return true;
    } else if(H_passes == 2 || C_passes == 2){
        return true;
    } else {
        return false;
    }
}

game::who Othello::winning() const{
    int black_amount, white_amount;
    black_amount = white_amount = 0;
    for(int j = 0; j < 8; j++){
        for(int i = 0; i < 8; i++){
            if(board[j][i].is_black()){
                black_amount++;
            } else if(board[j][i].is_white()){
                white_amount++;
            }
        }
    }
    if(black_amount > white_amount){
        return HUMAN;
    } else if(white_amount > black_amount){
        return COMPUTER;
    } else {
        return NEUTRAL;
    }
}
void Othello::display_status() const{
    int col = 1;
    int num = 0;
    cout << RESET;
    cout << YELLOW << "\tWelcome to Othello!" << endl;
    cout << "------------Game Status---------------" << endl;
    cout << "   A   B   C   D   E   F   G   H " << endl;
    for(int j = 0; j < 8; j++){
        if(j == num){
            cout << YELLOW << col;
            num++;
            col++;
        }
        for(int i = 0; i < 8; i++){
            if(i == 0){
            cout << B_GREEN << BLACK << "| ";
            }
            board[j][i].output_color();
            cout << " | ";
            if(i == 7){
                cout << RESET << endl;
            }
        }
    }
}

void Othello::pass(){
    string move = "  ";
    int count = 0;
    int tmp = game::moves_completed();
   if(tmp%2 == 0){
       cout << "The next possible move for HUMAN: ";
       for(char j = 'A'; j < 'I'; j++){
           for(char i = '1'; i < '9'; i++){
               move.at(0) = j;
               move.at(1) = i;
               if(is_legal(move)){
                   cout << move << " ";
                   count++;
               }
           }
       }
       if(count == 0){
            cout << "Pass: No more moves." << endl;
            move = "  ";
            game::make_move(move);
            H_passes++;
       } else if(count != 0){
           cout << endl;
       }
   } else{
       for(char j = 'A'; j < 'I'; j++){
           for(char i = '1'; i < '9'; i++){
               move.at(0) = j;
               move.at(1) = i;
               if(is_legal(move)){
                   count++;
               }
           }
       }
        if(count == 0){
            cout << "Pass: No more moves!" << endl;
            move = "  ";
            game::make_move(move);
            C_passes++;
        }
   }
}

game* Othello::clone() const{
    return new Othello(*this);
}

void Othello::compute_moves(queue<string>& moves) const{
    string move = "  ";
    while(!moves.empty()){
        moves.pop();
    }
    for(char j = 'A'; j < 'I'; j++){
        for(char i = '1'; i < '9'; i++){
            move.at(0) = j;
            move.at(1) = i;
            if(is_legal(move)){
                moves.push(move);
            }
        }
    }
}

int Othello::evaluate() const{
    string move = "  ";
    int tmp_c, tmp_r;
    int count = 0;
    for(char j = 'A'; j < 'I'; j++){
        for(char i = '1'; i < '9'; i++){
            move.at(0) = j;
            move.at(1) = i;
            tmp_c = int(j - 'A');
            tmp_r = int(i - '1');
            if(move == "A1" || move == "A8" || move == "H1" || move == "H8"){
                if(board[tmp_c][tmp_r].is_white()){
                    count += 2;
                } else {
                    count -= 2;
                }
            } else {
                if(board[tmp_c][tmp_r].is_white()){
                    count += 1;
                } else {
                    count -= 1;
                }
            }
        }
    }
    return count;
}

int Othello::get_c_passes() const {
    return C_passes;
}

int Othello::get_h_passes() const{
    return H_passes;
}