#pragma once
#include "stdafx.h"
#include "iostream"
#include "fstream"
#define MAX 100
#define vocuc 999
using namespace std;
class File{
private:
	int a[MAX][MAX],n;
	int x,y;
	ifstream ifile;
	ofstream ofile;

public:
	char filename[MAX];
	bool readFile(char[],int[][MAX],int&,int,int);
	void xuatFile(int[][MAX],int,int,int);
};