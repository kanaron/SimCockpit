#include"Logic.h"

Logic::Logic()
{
	cout << "Logic" << endl;
}

void Logic::addToVector(Output *o)
{
	obj.push_back(o);
}

void Logic::sendAll(Serial &s)
{
	LEDDisp *ld;
	LCDDisp *lc;
	LED *l;
	Radio *r;


	for (int i = 0; i < obj.size(); i++)
	{
		if (ld = dynamic_cast<LEDDisp*>(obj[i]))
		{
			//cout << "1" << endl;

			ld->addToSend(s, ld->get());
		}

		if (lc = dynamic_cast<LCDDisp*>(obj[i]))
		{
			//cout << "1" << endl;

			lc->addToSend(s, lc->get());
		}

		if (l = dynamic_cast<LED*>(obj[i]))
		{
			//cout << "1" << endl;

			l->addToSend(s, l->get());
		}

		if (r = dynamic_cast<Radio*>(obj[i]))
		{
			r->addStbyToSend(s);
			r->addToSend(s, r->get());
		}
	}
}

void Logic::GetFromFile()
{
	ifstream file;
	file.open("data.txt");

	LEDDisp *ld;
	LCDDisp *lc;
	LED *l;
	Radio *r;

	string temp;
	size_t off = 0;

	do
	{
		file >> temp;

		for (int i = 0; i < obj.size(); i++)
		{
			if (obj[i]->getf() == temp[0])
			{
				if (ld = dynamic_cast<LEDDisp*>(obj[i]))
				{
					ld->set(stod(&temp[1]));
				}

				if (lc = dynamic_cast<LCDDisp*>(obj[i]))
				{
					lc->set(stod(&temp[1]));
				}

				if (l = dynamic_cast<LED*>(obj[i]))
				{
					for (int j = 0; j < l->get().size(); j++)
					{
						l->set(j, temp[j + 1]);
					}
				}

				if (r = dynamic_cast<Radio*>(obj[i]))
				{
					regex reg("([a-z])(\\d{3}\\.\\d{2})(\\d{3}\\.\\d{2})");
					smatch s;
					regex_search(temp, s, reg);
					r->set(stod(s[2]));
					r->setstby(stod(s[3]));
				}
			}
		}

	} while (!file.eof());

	file.close();
}