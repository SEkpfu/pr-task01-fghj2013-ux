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

int min_func(const std::vector<float> src) {
    int n = src.size();
    float min = src[0];

    for (int i = 0; i < n; ++i) {
        if (src[i] < min) {
            min = src[i];
        }
    }
}

std::pair<float, int> max_func(const std::vector<float> src) {
    int n = src.size();
    int max_i = 0;
    float max = src[0];

    for (int i = 0; i < n; ++i) {
        if (src[i] > max) {
            max = src[i];
            max_i = i;
        }
    }

    return std::make_pair(max, max_i);
}

int cnt_of_bigger(std::vector<int> src, int num) {
    int n = src.size();
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (num < src[i]) {
            ++cnt;
        }
    }

    return cnt;
}

int sum_func(std::vector<int> src) {
    int sum = 0;

    for(auto i : src) {
        sum += i;
    }

    return sum;
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
    return 0;
}