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

void all_in_one_for_salary(Salary *employee, int num) {
    if (!employee) return;
    const float tax = 0.13f;
    float earns = employee->hours * employee->earnings_hour * 
                (1.0f + (employee->extra / 100.0f));

    employee->tax = earns * tax;
    employee->salary = earns - employee->tax;

    std::cout << num << "st will get: " << employee->salary << '\n';
}

int main(void) {
    Salary employee1;
    Salary employee2;
    Salary employee3;
    Salary employee4;
    Salary employee5;

    std::cin >> employee1.hours >> employee1.earnings_hour >> employee1.extra;
    std::cin >> employee2.hours >> employee2.earnings_hour >> employee2.extra;
    std::cin >> employee3.hours >> employee3.earnings_hour >> employee3.extra;
    std::cin >> employee4.hours >> employee4.earnings_hour >> employee4.extra;
    std::cin >> employee5.hours >> employee5.earnings_hour >> employee5.extra;

    all_in_one_for_salary(&employee1, 1);
    all_in_one_for_salary(&employee2, 2);
    all_in_one_for_salary(&employee3, 3);
    all_in_one_for_salary(&employee4, 4);
    all_in_one_for_salary(&employee5, 5);

    float salary_of_all = employee1.salary + employee2.salary +
                          employee3.salary + employee4.salary + 
                          employee5.salary;
    std::cout << "Avg salary is: " << salary_of_all / 5.f << '\n';
}