#include"Output.h"


Output::Output()
{

}

/*Output::Output(double d, char f)
{
	first = f;
	data = d;
}*/

//void Output::set(double d)
//{
//	data = d;
//}

char Output::getf()
{
	return first;
}

Output::Output(char f)
{
	first = f;
}

void Output::addToSend(Serial &s, double data)
{
	s.add(first);

	ostringstream os;
	os << data;
	string temp = os.str();

	for (int i = 0; i < temp.length(); i++)
	{
		//cout << temp[i] << endl;
		s.add(temp[i]);
	}

	s.write();
	s.write();
}

void Output::addToSend(Serial &s, vector<char> data)
{
	s.add(first);

	for (int i = 0; i < data.size(); i++)
	{
		//cout << temp[i] << endl;
		s.add(data[i]);
	}

	s.write();
	s.write();
}


Radio::Radio()
{

}

LEDDisp::LEDDisp(double d, char f) :Output(f)
{
	data = d;
}

void LEDDisp::set(double d)
{
	data = d;
}

double LEDDisp::get()
{
	return data;
}

LCDDisp::LCDDisp(double d, char f) : Output(f)
{
	data = d;
}

void LCDDisp::set(double d)
{
	data = d;
}

double LCDDisp::get()
{
	return data;
}

LED::LED(int len, char f) : Output(f)
{
	for (int i = 0; i < len; i++)
	{
		data.push_back('1');
	}
}

void LED::set(int id, char d)
{
	data[id] = d;
}

vector<char> LED::get()
{
	return data;
}

Radio::Radio(double st, double d, char f) :Output(f)
{
	data = d;
	stby = st;
}

void Radio::set(double d)
{
	data = d;
}

void Radio::setstby(double ds)
{
	stby = ds;
}

double Radio::get()
{
	return data;
}

double Radio::getStby()
{
	return stby;
}

void Radio::addStbyToSend(Serial &s)
{
	ostringstream os;
	os << stby;
	string temp = os.str();

	for (int i = 0; i < temp.length(); i++)
	{
		//cout << temp[i] << endl;
		s.add(temp[i]);
	}
	

}