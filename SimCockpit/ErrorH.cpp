#include "ErrorH.h"


ErrorH::ErrorH()
{

}

void ErrorH::Handle(int e)
{
	switch (e)
	{
	case 0:
	{
		cout << "NO COM" << endl;
		getchar();
		break;
	}
	default:
	{
		cout << "COS" << endl;
		getchar();
		break;
	}
	}
}