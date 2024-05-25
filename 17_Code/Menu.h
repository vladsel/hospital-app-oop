#ifndef _MENU_H_
#define _MENU_H_

#include "Queue.h"
#include <windows.h>
#include <locale>

//menu class
class Menu {
public:
	Menu() = default;
	~Menu() = default;
	void Begin();
private:
	Queue lst;
	int InputInt();
	void OutputListToFile();
	void InputListFromFile();
	void DoTask();
	void CreateHospital();
	void CreateClinic();
	void Run();
	void Frame(int x1, int y1, int x2, int y2, int print);
	void Info();
	void Coord(int x, int y);
	void Error();
	void Choice(int choice);
	bool IsDigit(const string value);
};

#endif // _MENU_H_