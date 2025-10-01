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
    float salary_of_all = 0.f;
    for (int i = 0; i < 5; ++i) {
        Salary employee1;
        std::cin >> employee1.hours >> employee1.earnings_hour >> employee1.extra;
        all_in_one_for_salary(&employee1, i + 1);
        salary_of_all += employee1.salary;
    }

    std::cout << "All salary: " << salary_of_all << '\n'
     << "Avg salary is: " << salary_of_all / 5.f << '\n';
}