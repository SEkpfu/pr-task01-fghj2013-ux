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

void all_in_one_for_salary(Salary *employee, int num) {
    if (!employee) return;
    const float tax = 0.13f;
    float earns = employee->hours * employee->earnings_hour * 
                (1.0f + (employee->extra / 100.0f));

    employee->tax = earns * tax;
    employee->salary = earns - employee->tax;

    std::cout << num << "st will get: " << employee->salary << '\n';
}

int employee_cmp(Salary *employee1, Salary *employee2) {
    int ans = 0;

    if (employee1->salary > employee2->salary) {
        ans = 1;
        std::cout << "First wins\n" << 
            "Sum salary: " << employee1->salary + employee2->salary;
    }
    else if (employee1->salary < employee2->salary) {
        ans = 2;
        std::cout << "Second wins\n" << 
            "Sum salary: " << employee1->salary + employee2->salary;
    }

    return ans;
}

int main(void) {

    return 0;
}