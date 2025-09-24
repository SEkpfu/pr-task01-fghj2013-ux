#include <iostream>
#include <vector>

struct Salary {
    int hours;
    int earnings_hour;
    int extra;
    float tax;
    float salary;

    Salary() : hours(0), earnings_hour(0), extra (0), tax(0), 
    salary(0){}
};

void all_in_one_for_salary(Salary *employee) {
    if (!employee) return;
    const float tax = 0.13f;
    float earns = employee->hours * employee->earnings_hour * 
                (1.0f + (employee->extra / 100.0f));

    employee->tax = earns * tax;
    employee->salary = earns - employee->tax;
}

int main(void) {
    int n;
    std::cin >> n;
    
    std::vector<float> salaries(0, n);
    std::vector<float> taxes(0, n);
    std::vector<Salary> employees;
    for (int i = 0; i < n; ++i) {
        Salary tmp;
        std::cin >> tmp.hours >> 
        tmp.earnings_hour >> tmp.extra;

        employees.push_back(tmp);
        all_in_one_for_salary(&employees[i]);
        salaries[i] = employees[i].salary;
        taxes[i] = employees[i].tax;
    }

    int min_i = 0;
    float min = salaries[0];
    int max_i = 0;
    float max = salaries[0];
    int cnt = 0;
    std::vector<int> indexes;
    float all_taxes = 0;
    for (int i = 0; i < n; ++i) {
        all_taxes += taxes[i];

        if (salaries[i] > 50000.f) {
            ++cnt;
            indexes.push_back(i);
        }

        if (min > salaries[i]) {
            min = salaries[i];
            min_i = i;
        }

        if (max < salaries[i]) {
            max = salaries[i];
            max_i = i;
        }
    }

    std::cout << "Min salary i " << min_i << '\n';
    std::cout << "Max salary " << max << '\n';
    std::cout << "Max salary i " << max_i << '\n';
    std::cout << "Cnt > 50000 " << cnt << '\n';
    for (int i = 0; i < (int)indexes.size(); ++i) {
        std::cout << indexes[i] << ' ';
    }
    std::cout << '\n' << "All taxes " << all_taxes;

}