class Negate : public SubExpression
{
public:
	Negate(Expression* left) : SubExpression(left)
	{
	}
	double evaluate()
	{
		int value = left->evaluate();
		if (value == 0) return 1;
		else return 0;
	}
};