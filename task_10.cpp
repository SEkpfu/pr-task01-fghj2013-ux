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

void all_in_one_for_salary(int h, int m_h, Salary *employee) {
    if (!employee) return;
    const float tax = 0.13f;
    float earns = h * m_h * 
                (1.0f + (employee->extra / 100.0f));

    employee->tax += earns * tax;
    employee->salary += earns - employee->tax;
}


int main(void) {
    int n = 4;
    std::vector<Salary> workers(n);
    int m = 3;
    int workers_h[n][m];
    int workers_m_h[n][m];

    int max = 0, max_i = 0;
    float sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int h, m_h;
            std::cin >> h >> m_h;
            workers_h[i][j] = h;
            workers_m_h[i][j] = m_h;

            // std::cout << h << ' ' << m_h << '\n';
            all_in_one_for_salary(h, m_h, &workers[i]);
        }
        if (workers[i].salary > max) {
            max = workers[i].salary;
            max_i = i;
        }

        sum += workers[i].salary;
    }

    std::cout << "1st worker 2nd month salary: " << workers_h[0][1] * workers_m_h[0][1] -
    workers_h[0][1] * workers_m_h[0][1] * 0.13f << '\n';
    std::cout << "3rd worker all tax: " << workers[2].tax << '\n';
    std::cout << "Max salary index: " << max_i << '\n';
    std::cout << "Salary sum: " << sum;
    return 0;
}

/*
10 10
10 10
10 10
10 9
10 9
10 9
10 8
10 8
10 8
10 7
10 7
10 7

*/