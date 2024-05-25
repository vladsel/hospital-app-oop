#ifndef _HOSPITAL_H_
#define _HOSPITAL_H_

#include "MedInstitution.h"

//child class
class Hospital : public Medical_Institution {
public:
	Hospital() : hospital_patients(-1), free_places(-1) {}
	Hospital(string _city, int _doctors, int _rank, int _hospital_patients, int _free_places)
		: Medical_Institution(_city, _doctors, _rank), hospital_patients(_hospital_patients), 
		free_places(_free_places) {}
	Hospital(const Hospital &hosp);
	void SetHospitalPatients(int hospital_patients);
	int GetHospitalPatients() const;
	void SetFreePlaces(int free_places);
	int GetFreePlaces() const;
	virtual void Display(ostream &out) const override;
	virtual void Input(istream &in) override;
private:
	int hospital_patients;
	int free_places;
};

#endif // _HOSPITAL_H_