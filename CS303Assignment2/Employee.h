#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee {
protected:
	double hoursWorked;
	double hourlyRate;

public:
	virtual double weeklySalary(double hours, double rate) = 0;
	virtual double vacationEarned(double hours) = 0;
	virtual double insuranceContrib(double hours, double rate) = 0;
};

#endif //EMPLOYEE_H

