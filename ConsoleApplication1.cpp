#include <iostream>
using namespace std;

int Сount(int n, int u, int count)
{
    if (n > u)
    {
        cout << count + 1 << ". ";
        cout << n << "+" << u << endl;
        n = n - 1;
        u = u + 1;
        count = count + 1;
        return Сount(n, u, count);
    }
    else
    {
        return count;
    }
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Пожалуйста, натуральное число: ";
	cin >> n;
	cout << "Результат: " << Сount(n - 1, 1, 0) << endl;
	return 0;
}
