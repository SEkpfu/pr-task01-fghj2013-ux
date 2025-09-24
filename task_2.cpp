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

float taxes(const float salary) {
    const float tax = 0.13f;

    return salary * tax;
}

float white_salary(float salary, float tax) {
    return salary - tax;
}

float earns (Salary *employee) {
    if (!employee) return 0.0f;

    return employee->hours * employee->earnings_hour * 
                (1.0f + (employee->extra / 100.0f));
}

int main(void) {

    return 0;
}