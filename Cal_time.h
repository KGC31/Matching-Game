#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Board.h"

using namespace std;

struct point {
	float num;
	string name;
};

void write_file(string filename, point t);

vector<point> read_file(string filename, vector<point>& arr);

vector<point> sorted(vector<point> arr);

void leaderboard(vector<point> arr);

void printleaderboard();

