#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN {
	private:
		std::stack<int> expression_stack;
	public:
		bool compute_expression(char *expression, int *result);

		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
};

#endif
