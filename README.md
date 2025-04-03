# COMPILER-DESIGN-BASICS

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: JAY PANDIAN

*INTERN ID*: CT04WX43

*DOMAIN*: C++ PROGRAMMING

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

This C++ program is a simple arithmetic expression evaluator that interprets and calculates mathematical expressions using a recursive descent parser. It supports fundamental operations like addition (+), subtraction (-), multiplication (*), and division (/), along with parentheses for grouping expressions.

How the Code Works:
At the core of the program is the ArithmeticParser class, which processes mathematical expressions character by character and evaluates them in a structured manner. The program takes an arithmetic expression as input from the user, parses it, and then computes and displays the result. If the input is invalid, an error message is shown instead.

Breaking Down the Components

Main Function (main)
Prompts the user to enter an arithmetic expression.
Passes the input to the ArithmeticParser class for evaluation.
Displays the computed result or an error message if the input is invalid.

Class: ArithmeticParser
Uses recursive parsing to process the expression.
Ensures correct operator precedence (multiplication and division are processed before addition and subtraction).
Detects and handles errors such as unexpected characters, division by zero, and mismatched parentheses.

Parsing Logic
The program follows the recursive descent parsing method, breaking down expressions into smaller components and processing them systematically.

parseExpression()
Manages addition and subtraction.
Calls parseTerm() to process individual terms.
Applies operations as + or - are encountered.

parseTerm()
Handles multiplication and division.
Calls parseFactor() to process numbers or sub-expressions.
Ensures multiplication and division are computed before addition and subtraction.

parseFactor()
Processes parentheses.
Recursively calls parseExpression() for expressions inside parentheses.
Calls parseNumber() to handle numerical values.

parseNumber()
Extracts numbers from the input string.
Converts digit sequences into numerical values.

This structured approach allows the program to accurately interpret and evaluate mathematical expressions while maintaining clear error handling.
