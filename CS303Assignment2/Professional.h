#ifndef PROFESSIONAL_H_
#define PROFESSIONAL_H_

#include "Employee.h"

class Professional : public Employee {
public:
	double weeklySalary(double hours, double rate) = 0;
	double vacationEarned(double hours) = 0;
	double insuranceContrib(double hours, double rate) = 0;
};

#endif //PROFESSIONAL_H_
