#include <iostream>

#define SURNAME_LENGTH 20

struct Salary{
    std::string surname;
    int hours;
    int earnings_hour;
    int extra;
    float tax;
    float salary;

    Salary() : hours(0), earnings_hour(0), extra (0), salary(0),
    tax(0), surname(SURNAME_LENGTH, '\0'){}
};

void employee_info(Salary *employee) {
    if (!employee) return;
    
    std::cin >> employee->hours >> employee->earnings_hour >> employee->extra;
}

int main(void) {
    Salary employee;
    employee_info(&employee);
    return 0;
}