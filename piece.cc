/**
Name: Po-Yi, Lin (Peter)
Email: pl757117@ohio.edu
*/
#include <iostream>
#include "piece.h"
using namespace std;

piece::piece(){
    empty = ' ';
    white = 'O';
    black = 'X';
    s_color = empty;
}

bool piece::is_white() const{
    return s_color == 'O';
}

bool piece::is_black() const{
    return s_color == 'X';
}

bool piece::is_empty() const{
    return s_color == ' ';
}

void piece::flip(){
    if(is_white()){
        s_color = 'X';
    } else if(is_black()){
        s_color = 'O';
    }
}
void piece::output_color() const{
    if(s_color == ' '){
        cout << B_GREEN << s_color;
    } else if(s_color == 'X'){
        cout << B_GREEN << BLACK << s_color;
    } else {
        cout << WHITE << s_color;
    }
    cout << B_GREEN << BLACK;
}