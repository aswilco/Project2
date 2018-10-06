class IfExpression : public SubExpression
{
public:
	IfExpression(Expression* right) : SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if (right->evaluate() > 0) return 1;
		else return 0;
	}
};