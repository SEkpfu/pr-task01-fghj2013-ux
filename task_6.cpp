#include <iostream>
#include <string>

#define SURNAME_LENGTH 20

struct Salary{
    std::string surname;
    int hours;
    int earnings_hour;
    int extra;
    float tax;
    float salary;

    Salary() : hours(0), earnings_hour(0), extra (0),
    tax(0), salary(0), surname(SURNAME_LENGTH, '\0'){}
};

void all_in_one_for_salary(Salary *employee) {
    if (!employee) return;
    const float tax = 0.13f;
    float earns = employee->hours * employee->earnings_hour * 
                (1.0f + (employee->extra / 100.0f));

    employee->tax = earns * tax;
    employee->salary = earns - employee->tax;
}

void checking_earnings(Salary *employee) {
    int taxes_check = 0;
    int salary_check = 0;

    if (employee->salary < 1000.0f)
        salary_check = 1;

    if (employee->tax > 50.0f) 
        taxes_check = 1;
    
    if (salary_check)
        std::cout << employee->surname << '\n';

    if (taxes_check) {
        char c;
        for (int i = 0; (i < SURNAME_LENGTH) && employee->surname[i]; ++i) {
            c = employee->surname[i];
        }

        std::cout << employee->surname[0] << '-' << c << '\n';
    }
}

int main(void) {
    Salary employee;
    std::cin >> employee.surname >> employee.hours >> employee.earnings_hour >> employee.extra;
    all_in_one_for_salary(&employee);
    checking_earnings(&employee);
    return 0;
}