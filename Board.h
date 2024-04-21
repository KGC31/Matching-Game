#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include"matching.h"
#include<conio.h>
#include"Cal_time.h"
#include<MMSystem.h>

using namespace std;

void color(int color);
void Gotoxy(short x, short y);
void choice(string** array, int n, int m);
bool check(string** array, int n, int m);
void read(string** a, int n, int m, ifstream& fin);
void generate(string**& array, int& n, int& m);
void dele(string** array, int n);
int Menu();
void Cursor(string** array, int n, int m, int& n1, int& n2, int& m1, int& m2);
void board(string** array, int n, int m, int n1, int n2, int m1, int m2);
void boardview();
int getIntRange(int low, int high);
void howtoplay();