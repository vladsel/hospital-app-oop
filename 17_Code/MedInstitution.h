#ifndef _MEDINSTITUTION_H_
#define _MEDINSTITUTION_H_

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;

//abstract class
class Medical_Institution {
public:
	Medical_Institution() : city("unknown"), doctors(-1), rank(-1) {}
	Medical_Institution(string _city, int _doctors, int _rank)
		: city(_city), doctors(_doctors), rank(_rank) {}
	virtual ~Medical_Institution() = default;
	int GetDoctors() const;
	string GetCity() const;
	int GetRank() const;
	void SetDoctors(int doctors);
	void SetCity(string city);
	void SetRank(int rank);
	virtual void Display(ostream &out) const = 0;
	virtual void Input(istream &in) = 0;
protected:
	string city;
	int doctors;
	int rank;
};

#endif // _MEDINSTITUTION_H_