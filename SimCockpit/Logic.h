#pragma once
#include"Serial.h"
#include"Output.h"
#include<vector>
#include<fstream>
#include<regex>
#include<iostream>


class Logic
{
	vector<Output*> obj;

public:

	Logic();
	void addToVector(Output *o);
	void sendAll(Serial &s);
	void GetFromFile();
};