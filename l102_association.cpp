#include<iostream>
#include<vector>
#include<functional>/*for wrapper*/
#include<string>
class Patient;/*Foreward because in Doctor needed*/
class Doctor
{
	private:std::string m_name{};
		std::vector<std::reference_wrapper<const Patient>> m_patient{};/*given by refernce*/
	public:Doctor(const std::string& name):m_name{name}{}
               void addPatient(Patient& patient);
	friend std::ostream& operator<<(std::ostream& out,const Doctor& doctor);
	const std::string& getName() const {return m_name;}	
};

class Patient
{
	private:std::string m_name{};
		std::vector<std::reference_wrapper<const Doctor>> m_doctor{};
               void addDoctor(Doctor& doctor){m_doctor.push_back(doctor);}

	public:Patient(const std::string& name):m_name{name}{}

	friend std::ostream& operator<<(std::ostream& out,const Patient& patient);
	const std::string& getName() const {return m_name;}
	friend void Doctor::addPatient(Patient& patient);/*frient to have access to data from patien*/
};


void Doctor::addPatient(Patient& patient)
{
m_patient.push_back(patient);
patient.addDoctor(*this);
}
std::ostream& operator<<(std::ostream& out,const Doctor& doctor)
{
	if(doctor.m_patient.empty()){out << doctor.m_name << " has no patient\n";return out;}
	out << doctor.m_name << "is seeing patient: ";
	for(const auto& patient : doctor.m_patient) out << patient.get().getName() << ' ';
	return out;
}

std::ostream& operator<<(std::ostream& out,const Patient& patient)
{
	if(patient.m_doctor.empty()){out << patient.m_name << " has no doctor\n";return out;}
	out << patient.m_name << " is seeing doctor: ";
	for(const auto& doctor : patient.m_doctor) out << doctor.get().getName() << ' ';
	return out;
}
int main()
{
std::cout << "assoziation an object and another object have this relationship\n";
std::cout << "1.assoziated object(member) is otherwise unrelated to the object.\n";
std::cout << "2.assoziated object(member) can belong to more than one object at the time.\n";
std::cout << "3.assoziated object(member) does not have the existence managed by the object.\n";
std::cout << "4.assoziated object(member) may or may not know about the existence of the object.\n";
std::cout << "Doctors patiens relation\n";
Patient dave{"Dave"};
Patient frank{"Frank"};
Patient betsy{"Betsy"};


Doctor ortho {"Orthopaede"};
Doctor chirurg{"Chirurge"};

std::cout << ortho  << '\n';
std::cout << chirurg  << '\n';
std::cout << dave  << '\n';
std::cout << frank  << '\n';
std::cout << betsy  << '\n';

ortho.addPatient(dave);
ortho.addPatient(betsy);
ortho.addPatient(frank);

chirurg.addPatient(dave);
chirurg.addPatient(frank);

std::cout << ortho  << '\n';
std::cout << chirurg  << '\n';
std::cout << dave  << '\n';
std::cout << frank  << '\n';
std::cout << betsy  << '\n';




	return 0;
}
