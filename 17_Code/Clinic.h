#ifndef _CLINIC_H_
#define _CLINIC_H_

#include "MedInstitution.h"

//child class
class Clinic : public Medical_Institution {
public:
	Clinic() : day_patients(-1) {}
	Clinic(string _city, int _doctors, int _rank, int _day_patients)
		: Medical_Institution(_city, _doctors, _rank), day_patients(_day_patients) {}
	Clinic(const Clinic &cl);
	void SetDayPatients(int day_patients);
	int GetDayPatients() const;
	virtual void Display(ostream &out) const override;
	virtual void Input(istream &in) override;
private:
	int day_patients;
};

#endif // _CLINIC_H_