#pragma once
#include"Serial.h"
#include<sstream>
#include<string.h>

using namespace std;

class Output
{
	//double data;
	char first;

public:

	Output();
	//Output(double d, char f);
	Output(char f);

	virtual void addToSend(Serial &s, double data);
	virtual void addToSend(Serial &s, vector<char> data);

	char getf();

	//void set(double d);

 	//virtual ~Output();
};

class LEDDisp :public Output
{

	double data;

public:
	
	LEDDisp();
	LEDDisp(double d, char f);

	double get();

	void set(double d);
};

class LCDDisp :public Output
{

	double data;

public:

	LCDDisp();
	LCDDisp(double d, char f);

	double get();

	void set(double d);
};

class LED :public Output
{
	vector<char> data;

public:

	LED();
	LED(int len, char f);

	vector<char> get();

	void set(int id, char d);
};

class Radio :public Output
{
	double data;
	double stby;

public:

	Radio();
	Radio(double st, double d, char f);

	double get();
	double getStby();

	void setstby(double ds);
	void set(double d);

	void addStbyToSend(Serial &s);
};
