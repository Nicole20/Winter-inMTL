#pragma once
#include<iostream>
#include<vector>
#include<glut.h>
#include<freeglut.h>
#include<ctime>

using namespace std;

class curb
{
public:
	curb();

	int salt, pos;
	vector<int> top, middle, bottom;

	void add();

	~curb();
};
