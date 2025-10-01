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

void all_in_one_for_salary(Salary *employee) {
    if (!employee) return;
    const float tax = 0.13f;
    float earns = employee->hours * employee->earnings_hour * 
                (1.0f + (employee->extra / 100.0f));

    float tax_val = earns * tax;
    float w_salary = earns - tax_val;
    employee->salary = w_salary;
    std::cout << "You will get:" << w_salary << '\n';
}

/*
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
*/

void employee_info(Salary *employee) {
    if (!employee) return;

    std::cin >> employee->hours >> employee->earnings_hour >> employee->extra;
}

int main(void) {
    Salary employee;
    employee_info(&employee);
    all_in_one_for_salary(&employee);

/*
    float b_salary = earns(&employee);
    float tax = taxes(b_salary);
    float w_salary = white_salary(b_salary, tax);

    std::cout << "Black salary = " << b_salary << '\n' <<
                 "White salary = " << w_salary;
*/
    return 0;
}