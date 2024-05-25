#include "Clinic.h"

//copy constructor
Clinic::Clinic(const Clinic &cl) {
	city = cl.city;
	doctors = cl.doctors;
	rank = cl.rank;
	day_patients = cl.day_patients;
}

//set patients per day
void Clinic::SetDayPatients(int day_patients) {
	if (day_patients >= 0)
		this->day_patients = day_patients;
	//else
	//	cout << "SetDayPatients(int): day_patients < 0, error" << endl;
}

//get patients per day
int Clinic::GetDayPatients() const {
	return day_patients;
}

//output all values to stream (overrided function)
void Clinic::Display(ostream &out) const {
	out << "\nMedical Institution: Clinic" << endl;
	out << "number of doctors: " << doctors << endl;
	out << "quality rank: " << rank << endl;
	out << "location: " << city << endl;
	out << "\tpatients per day: " << day_patients << "\n" << endl;
}

//input all values to stream (overrided function)
void Clinic::Input(istream &in) {
	in >> doctors >> rank >> city >> day_patients;
}
