#include <iostream>
#include <cmath>
#define N 5

using namespace std;

class Polinom
{
private:
	int b;
	int *x;
	double* st;	
	double arr[N];
public:
	Polinom()
	{
		b = N;
		x = new int();
		st = new double[6];
	}

	Polinom(const Polinom& obj) {   // конструктор копіювання
		this->b = obj.b;
		for (int i = 0; i < this->b; i++) {
			this->st[i] = obj.st[i];
		}
	}

	~Polinom()
	{
		delete x;
		delete st;
	}

	int input()
	{
		cout << "\nВведiть коефiцiєнти:  \n";
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		return 0;
	}

	void output()
	{
		int b = N;
		cout << "Полiном:" << '\n';
		for (int j = 0; j < N,b != 0; j++, b--)
		{
			cout << arr[j] << 'x' << '^' << b << '+';
		}
		cout << '\n';
	}

	void InputX()
	{
		cout << "x = ";
		cin >> *x;
	}

	double result() {
		int res = 0;
		int b = N;
		for (int j = 0; b > 0, j < 6; b--, j++) {
			res+=(arr[j])* pow(*x, b);
		}
		return res;
	}

	void SetST(int c, int i)
	{
		st[i] = c;
	}

	int GetC1(int i)
	{
		return st[i];
	}


}; Polinom A; Polinom B;

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	double sum;
	double riz;
	double res;

	A.input();
	A.output();
	A.InputX();
	res = A.result();
	cout << "Результат = " << res;

	B.input();
	B.output();
	B.InputX();
	res = B.result();
	cout << "Результат = " << res;

	sum = A.result() + B.result();
	cout << "\n\nСума полiномiв = " << sum;

	riz = fabs(A.result() - B.result());
	cout << "\nРiзниця полiномiв = " << riz;

	return 0;
}
