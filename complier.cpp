#include <iostream>
#include <cctype>
#include <string>

class SimpleParser {
private:
    const char* input;
    int pos;

    // Helper function to consume whitespace 
    void skipWhitespace() {
        while (input[pos] == ' ') pos++; 
    }

        double parseNumber() {
        skipWhitespace();
        double num = 0;
        bool isDecimal = false;
        double decimalPlace = 0.1;
        
        // Read number manually
        while (std::isdigit(input[pos]) || input[pos] == '.') {
            if (input[pos] == '.') {
                isDecimal = true;
            } else {
                if (!isDecimal) {
                    num = num * 10 + (input[pos] - '0');
                } else {
                    num += (input[pos] - '0') * decimalPlace;
                    decimalPlace /= 10;
                }
            }
            pos++;
        }
        return num;
    }

    // Parses factors )
    double parseFactor() {
        skipWhitespace();
        if (input[pos] == '(') {  
            pos++; 
            double result = parseExpression();  
            if (input[pos] == ')') pos++; 
            return result;
        } else {
            return parseNumber();
        }
    }

    // Parses multiplication and division
    double parseTerm() {
        double result = parseFactor();
        while (true) {
            skipWhitespace();
            if (input[pos] == '*') {
                pos++;
                result *= parseFactor();
            } else if (input[pos] == '/') {
                pos++;
                double divisor = parseFactor();
                if (divisor == 0) {
                    std::cerr << "Oops! Division by zero detected.\n";  
                    return 0;  
                }
                result /= divisor;
            } else {
                break;
            }
        }
        return result;
    }

    // Parses addition and subtraction
    double parseExpression() {
        double result = parseTerm();
        while (true) {
            skipWhitespace();
            if (input[pos] == '+') {
                pos++;
                result += parseTerm();
            } else if (input[pos] == '-') {
                pos++;
                result -= parseTerm();
            } else {
                break;
            }
        }
        return result;
    }

public:
    SimpleParser(const std::string& expr) : input(expr.c_str()), pos(0) {}

    // Evaluates the full expression
    double evaluate() {
        return parseExpression();
    }
};

int main() {
    std::string expression;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, expression);

    SimpleParser parser(expression);
    std::cout << "Result: " << parser.evaluate() << std::endl;

    return 0;
}
