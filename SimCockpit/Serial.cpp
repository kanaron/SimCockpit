#include"Serial.h"



using namespace std;

Serial::Serial()
{

}

Serial::Serial(string p)
{
	cp = ::CreateFile("COM5", GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);

	if (cp == INVALID_HANDLE_VALUE)
	{
		throw 0;
	}


	DCB dcb = { 0 };
	dcb.DCBlength = sizeof(DCB);

	if (!::GetCommState(cp, &dcb))
	{
		throw 1;
	}

	dcb.BaudRate = 9600;
	dcb.ByteSize = 8;
	dcb.Parity = 0;
	dcb.StopBits = 0;

	if (!::SetCommState(cp, &dcb))
	{
		throw 2;
	}
}

void Serial::add(char t)
{
	//cout << "2" << endl;
	this->q.push(t);
}

void Serial::write()
{
	//q.push('F');

	unsigned long written = 0;

	//cout << q.size();

	while (!q.empty())
	{
		char temp = q.front();

		cout << temp << endl;

		if (WriteFile(cp, &temp, 1, &written, NULL) != 0)
		{
			q.pop();
		}
		//Sleep(5);
	}
}

