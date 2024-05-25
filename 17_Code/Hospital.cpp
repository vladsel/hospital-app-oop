#include "Hospital.h"

//copy constructor
Hospital::Hospital(const Hospital &hosp) {
	city = hosp.city;
	doctors = hosp.doctors;
	rank = hosp.rank;
	hospital_patients = hosp.hospital_patients;
	free_places = hosp.free_places;
}

//set hospitalized patients
void Hospital::SetHospitalPatients(int hospital_patients) {
	if (hospital_patients >= 0)
		this->hospital_patients = hospital_patients;
	//else
	//	cout << "SetHospitalPatients(int): hospital_patients < 0, error" << endl;
}

//get hospitalized patients
int Hospital::GetHospitalPatients() const {
	return hospital_patients;
}

//set free places
void Hospital::SetFreePlaces(int free_places) {
	if (free_places >= 0)
		this->free_places = free_places;
	//else
	//	cout << "SetHospitalPatients(int): hospital_patients < 0, error" << endl;
}

//get free places
int Hospital::GetFreePlaces() const {
	return free_places;
}

//output all values to stream (overrided function)
void Hospital::Display(ostream &out) const {
	out << "\nMedical Institution: Hospital" << endl;
	out << "number of doctors: " << doctors << endl;
	out << "quality rank: " << rank << endl;
	out << "location: " << city << endl;
	out << "\thospitalized patients: " << hospital_patients << endl;
	out << "\tfree places: " << free_places << "\n" << endl;
}

//input all values to stream (overrided function)
void Hospital::Input(istream &in) {
	in >> doctors >> rank >> city >> hospital_patients >> free_places;
}
