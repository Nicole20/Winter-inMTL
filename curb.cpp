#include "stdafx.h"
#include "curb.h"

curb::curb()
{
	top.push_back(0);
	middle.push_back(0);
	bottom.push_back(0);

	salt = 3;
	pos = 1;

	srand(time(NULL));

	int temp;

	for (int i = 0; i < 9; i++)
	{
		temp = rand() % 4;
		top.push_back(temp);
		temp = rand() % 4;
		middle.push_back(temp);
		temp = rand() % 4;
		bottom.push_back(temp);
	}
}

void curb::add()
{
	int temp;

	temp = rand() % 4;
	top.push_back(temp);
	temp = rand() % 4;
	middle.push_back(temp);
	temp = rand() % 4;
	bottom.push_back(temp);
}

curb::~curb()
{
}
