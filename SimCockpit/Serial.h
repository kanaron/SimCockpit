#pragma once
#include<string>
//#include<winbase.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<windows.devices.serialcommunication.h>


using namespace std;

class Serial
{

	HANDLE cp;
	queue<char> q;

public: 
	Serial();
	Serial(string p);

	void add(char t);

	void write();
};