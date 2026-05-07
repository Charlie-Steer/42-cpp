#include "RPN.hpp"
#include <iostream>

// returns 'false' on failure. Stores result on argument.
bool RPN::compute_expression(char *expression, int *result) {
	char *cursor = expression;
	int operand1 = 0;
	int operand2 = 0;
	while (*cursor != '\0') {
		if (*cursor >= '0' && *cursor <= '9') {
			expression_stack.push(*cursor - '0');
		} else if (*cursor == '/' || *cursor == '*' || *cursor == '+' || *cursor == '-') {
			if (expression_stack.size() < 2) {
				std::cerr << "Error: Expression couldn't be solved due to lack of numbers in stack." << std::endl;
				return false;
			} else if (*cursor == '/') {
				operand2 = expression_stack.top();
				expression_stack.pop();
				operand1 = expression_stack.top();
				expression_stack.pop();
				if (operand2 == 0) {
					std::cerr << "Error: Attempt to divide by zero." << std::endl;
					return false;
				}
				expression_stack.push(operand1 / operand2);
			} else if (*cursor == '*') {
				operand2 = expression_stack.top();
				expression_stack.pop();
				operand1 = expression_stack.top();
				expression_stack.pop();
				expression_stack.push(operand1 * operand2);
			} else if (*cursor == '+') {
				operand2 = expression_stack.top();
				expression_stack.pop();
				operand1 = expression_stack.top();
				expression_stack.pop();
				expression_stack.push(operand1 + operand2);
			} else if (*cursor == '-') {
				operand2 = expression_stack.top();
				expression_stack.pop();
				operand1 = expression_stack.top();
				expression_stack.pop();
				expression_stack.push(operand1 - operand2);
			}
		} else if (*cursor != ' ') {
			std::cerr << "Error: Unparsable character '" << *cursor << "'." << std::endl;
			return false;
		}
		++cursor;
	}
	if (expression_stack.size() != 1) {
		std::cerr << "Error: Mutiple values left in stack by the end of the computation." << std::endl;
		return false;
	} else {
		*result = expression_stack.top();
		return true;
	}
}

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->expression_stack = other.expression_stack;
	}
	return *this;
}

RPN::~RPN() {}
