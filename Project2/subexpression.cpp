#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greater.h"
#include "less.h"
#include "equals.h"
#include "not.h"
#include "and.h"
#include "or.h"
#include "if.h"
#include "else.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

 SubExpression::SubExpression(Expression* left) {
	this->left = left;
}

Expression* SubExpression::parse()
{
    Expression* left;
    Expression* right;
	
    char operation, paren, nextOperation;
	if (cin.peek() == '?') {
		cin >> operation;
		right = Operand::parse();
		cin >> paren;
		return new IfExpression(right);
	}
    left = Operand::parse();
    cin >> operation;
	if (operation == '!') {
		cin >> paren;
		return new Negate(left);
	}

    right = Operand::parse();
	if (operation == ':') {
		Expression* conditional = SubExpression::parse();
		return new ElseExpression(left, right, conditional);

	}
    cin >> paren;
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
		case '>':
			return new GreaterThan(left, right);
		case '<':
			return new LessThan(left, right);
		case '|':
			return new Or(left, right);
		case '&':
			return new And(left, right);

    }
    return 0;
}
        