#pragma once
#include"Output.h"
#include"Logic.h"
#include<fstream>

using namespace std;


class Input
{
public:

	Input();

	void GetFromFile(Logic &l);
};