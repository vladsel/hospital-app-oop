#include "MedInstitution.h"

//get doctors
int Medical_Institution::GetDoctors() const {
	return doctors;
}

//get city
string Medical_Institution::GetCity() const {
	return city;
}

//get rank
int Medical_Institution::GetRank() const {
	return rank;
}

//set doctors
void Medical_Institution::SetDoctors(int doctors) {
	if (doctors >= 0)
		this->doctors = doctors;
	//else
	//	cout << "SetDoctors(int): doctors < 0, error" << endl;
}

//set city
void Medical_Institution::SetCity(string city) {
	if (!city.empty())
		this->city = city;
	//else 
	//	cout << "SetCity(string): city is empty, error" << endl;
}

//set rank
void Medical_Institution::SetRank(int rank) {
	if (rank > 0)
		this->rank = rank;
	//else
	//	cout << "SetRank(int): rank < 0, error" << endl;
}