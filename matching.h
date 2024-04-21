#include<iostream>
#include<string>

using namespace std;

bool Check_cell(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2);

bool Check_vertical(string** arr, int& posx1, int& posx2, int& posy);

bool Check_horizontal(string** arr, int& posx, int& posy1, int& posy2);

bool L_check(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2);

bool U_check_vertical(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2, int& row);

bool U_check_horizontal(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2, int& col);

bool Z_check_vertical(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2);

bool Z_check_horizontal(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2);

bool Matching(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2, int& row, int& col);