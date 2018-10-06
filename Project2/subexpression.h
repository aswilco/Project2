class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
	SubExpression(Expression* left);
    static Expression* parse();
protected: 
    Expression* left;
    Expression* right;
};    