#include "CppUnitTest.h"
#include "../17_Code/Menu.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CourseUnitTest {
	TEST_CLASS(CourseUnitTest) {
	public:
		TEST_METHOD(TestHospital) {
			Hospital *hosp = new Hospital;
			Assert::IsTrue(hosp->GetHospitalPatients() == -1);
			Assert::IsTrue(hosp->GetFreePlaces() == -1);
			Assert::IsTrue(hosp->GetCity() == "unknown");
			Assert::IsTrue(hosp->GetDoctors() == -1);
			Assert::IsTrue(hosp->GetRank() == -1);
			hosp->SetCity("Kyiv");
			hosp->SetDoctors(90);
			hosp->SetFreePlaces(10);
			hosp->SetHospitalPatients(50);
			hosp->SetRank(2);
			Assert::IsTrue(hosp->GetHospitalPatients() == 50);
			Assert::IsTrue(hosp->GetFreePlaces() == 10);
			Assert::IsTrue(hosp->GetCity() == "Kyiv");
			Assert::IsTrue(hosp->GetDoctors() == 90);
			Assert::IsTrue(hosp->GetRank() == 2);
			delete hosp;
			Hospital *hosp1 = new Hospital("Odessa", 150.5, 4, 50, 50);
			Assert::IsTrue(hosp1->GetHospitalPatients() == 50);
			Assert::IsTrue(hosp1->GetFreePlaces() == 50);
			Assert::IsTrue(hosp1->GetCity() == "Odessa");
			Assert::IsTrue(hosp1->GetDoctors() == 150);
			Assert::IsTrue(hosp1->GetRank() == 4);
			delete hosp1;
		}
		TEST_METHOD(TestClinic) {
			Clinic *cl = new Clinic;
			Assert::IsTrue(cl->GetDayPatients() == -1);
			Assert::IsTrue(cl->GetCity() == "unknown");
			Assert::IsTrue(cl->GetDoctors() == -1);
			Assert::IsTrue(cl->GetRank() == -1);
			cl->SetCity("Kyiv");
			cl->SetDoctors(90);
			cl->SetRank(2);
			cl->SetDayPatients(44);
			Assert::IsTrue(cl->GetDayPatients() == 44);
			Assert::IsTrue(cl->GetCity() == "Kyiv");
			Assert::IsTrue(cl->GetDoctors() == 90);
			Assert::IsTrue(cl->GetRank() == 2);
			delete cl;
			Clinic *cl1 = new Clinic("Odessa", 150, 4, 50);
			Assert::IsTrue(cl1->GetDayPatients() == 50);
			Assert::IsTrue(cl1->GetCity() == "Odessa");
			Assert::IsTrue(cl1->GetDoctors() == 150);
			Assert::IsTrue(cl1->GetRank() == 4);
			delete cl1;
		}
		TEST_METHOD(TestQueue) {
			Medical_Institution *hosp1 = new Hospital("Odessa", 150, 4, 50, 50);
			Medical_Institution *hosp2 = new Hospital("Kyiv", 151, 5, 51, 51);
			Hospital *hosp3 = new Hospital("Khmelnytsk", 152, 5, 52, 52);
			Medical_Institution *cl1 = new Clinic("Irpen", 153, 7, 53);
			Medical_Institution *cl2 = new Clinic("Brovary", 154, 8, 54);
			Clinic *cl3 = new Clinic("Kyiv", 155, 9, 55);
			Queue lst;
			lst.Push(hosp1);
			lst.Push(hosp2);
			lst.Push(hosp3);
			lst.Push(cl1);
			lst.Push(cl2);
			lst.Push(cl3);
			lst.Sort();
			Assert::IsFalse(lst.Empty() == true);
			Assert::IsTrue(lst.Task("Kyiv") == 306);
			Assert::IsTrue(lst.Size() == 6);
			lst.Pop();
			lst.Pop();
			Assert::IsTrue(lst.Size() == 4);
			lst.Delete();
			Assert::IsTrue(lst.Empty() == true);
		}
	};
}
