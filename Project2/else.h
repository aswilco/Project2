class ElseExpression : public SubExpression
{
public:
	ElseExpression(Expression* left, Expression* right, Expression* inConditional) : SubExpression(left, right)
	{
		conditional = inConditional;
	}
	double evaluate()
	{
		if (conditional->evaluate() > 0) return right->evaluate();
		else return left->evaluate();
	}
private:
	Expression* conditional;
};
