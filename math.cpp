#include <iostream>
using namespace std;

class Math {
protected:
	double a;
	double b;
public:
	Math() : a{0}, b{0} {}
	explicit Math(double a) : a{a}, b{0}{}
	Math(double a, double b) : a{a}, b{b} {}

	virtual void RootEquation() = 0;
};

class LineEquation : public Math {
public:
	LineEquation(double a, double b) : Math(a,b) {}

	void RootEquation() override {
		if (a == 0 && b != 0)
		{
			throw runtime_error("Equation has no solutions\n");
		}
		else if(a == 0 && b == 0) {
			throw runtime_error("Equation has many solutions\n");
		}
		
		cout << "Result: x = " << -b / a << endl;
	}

};

class SquadEquation : public Math {
private:
	double c;
public:
	SquadEquation(double a, double b, double c) : Math(a, b), c{ c } {}

	void RootEquation() override {
		if (a == 0)
		{
			LineEquation tmp(b, c);
			tmp.RootEquation();
		}
		double discriminant = b * b - 4 * a * c;
		if (discriminant > 0) 
		{
			double root1 = (-b + sqrt(discriminant)) / (2 * a);
			double root2 = (-b - sqrt(discriminant)) / (2 * a);
			cout << "Result: x1 = " << root1 << ", x2 = " << root2 << endl;
		}
		else if (discriminant == 0) {
			double root = -b / (2 * a);
			cout << "Equation one double corin: x = " << root << endl;
		}
		else {
			throw runtime_error("The equation has no real roots\n");
		}
	}
};

int main() {
	LineEquation example1(2, -3);
	example1.RootEquation();

	SquadEquation example2(1, -3, 2);
	example2.RootEquation();
}
