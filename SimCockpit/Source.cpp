#include"Logic.h"
#include"Output.h"
#include"Serial.h"
#include"ErrorH.h"
#include<iostream>


int main()
{

	Logic *lo = new Logic;
	
	LED *l = new LED(13, 'o');
	lo->addToVector(l);

	try
	{
		Serial s0("COM5");

		lo->GetFromFile();

		lo->sendAll(s0);
		lo->sendAll(s0);

	}
	catch (int e)
	{
		ErrorH *er = new ErrorH;

		er->Handle(e);
		
	}

	cout << "End" << endl;

	//getchar();
	return 0;
}