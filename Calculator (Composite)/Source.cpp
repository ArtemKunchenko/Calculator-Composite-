#include <iostream>
using namespace std;

class ArithmeticExpression
{
public:
	virtual double evaluate() = 0;
};


class NumericOperand : public ArithmeticExpression
{
public:
	NumericOperand(double value) { _value = value; }
	double evaluate() override { return _value; }
private:
	double _value;
};

class CompositeOperand : public ArithmeticExpression
{
public:
	CompositeOperand(ArithmeticExpression* left, char operation, ArithmeticExpression* right)
	{
		_left = left;
		_operation = operation;
		_right = right;

	}
	~CompositeOperand()
	{
		delete _left;
		delete _right;
	}

	double evaluate()  override
	{
		double leftValue = _left->evaluate();
		double rightValue = _right->evaluate();

		switch (_operation)
		{
		case '+':
			return leftValue + rightValue;
		case '-':
			return leftValue - rightValue;
		case '*':
			return leftValue * rightValue;
		case '/':
			if (rightValue == 0)
			{
				cout << "Division by 0 is unacceptable" << endl;
				return 0.0;
			}
			return leftValue / rightValue;
		default:
			cout << "Invalid operator is expression" << endl;
			return 0.0;
		}
	}


private:
	ArithmeticExpression* _left;
	char _operation;
	ArithmeticExpression* _right;
};

int main() 
{
	
	ArithmeticExpression* ex1 = new NumericOperand(2.0);
	ArithmeticExpression* ex2 = new NumericOperand(2.0);
	ArithmeticExpression* ex3 = new NumericOperand(4.0);
	ArithmeticExpression* compEx1 = new CompositeOperand(ex1, '+', ex2);
	ArithmeticExpression* compEx2 = new CompositeOperand(compEx1, '*', ex3);
	cout << "(2+2)*4= " << compEx2->evaluate() << endl;
	
	system("pause");
	return 0;
}