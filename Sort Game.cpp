#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> &emp1, pair<string, int> &emp2)
{
    if (emp1.second == emp2.second)
    {
        return emp1.first < emp2.first; }
    return emp1.second > emp2.second; 
}

int main()
{
    int x;
    cin >> x; 
    int N;
    cin >> N; 

    vector<pair<string, int>> employees; 

    for (int i = 0; i < N; i++)
    {
        string name;
        int salary;
        cin >> name >> salary; 
        if (salary >= x)
        {
            employees.push_back(make_pair(name, salary));
		}
    }

    sort(employees.begin(), employees.end(), compare); 
    for (auto emp : employees)
    {
        cout << emp.first << " " << emp.second << endl;
	}

    return 0;
}