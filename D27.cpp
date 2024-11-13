/*Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statement

Implement C++ program for expression conversion as infix to postfix and its

evaluation using stack based on given conditions i. Operands and operator, both must be single

character.

ii. Input Postfix expression must be in a desired format.

iii. Only '+', '-', '*' and '/ ' operators are expected. 

*/



#include <iostream>

#include <stack>

#include <string>

using namespace std;



int precedence(char op) {

    if (op == '+' || op == '-') 

        return 1;

    if (op == '*' || op == '/') 

        return 2;

    return 0;

}



int applyOperation(int a, int b, char op) {

    switch (op) {

        case '+': return a + b;

        case '-': return a - b;

        case '*': return a * b;

        case '/': return a / b;

    }

    return 0;

}



string infixToPostfix(string infix) {

    stack<char> operators;

    string postfix = "";

    

    for (char ch : infix) {

        if (isalnum(ch)) {

            postfix += ch;

        } else {

            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {

                postfix += operators.top();

                operators.pop();

            }

            operators.push(ch);

        }

    }

    while (!operators.empty()) {

        postfix += operators.top();

        operators.pop();

    }

    return postfix;

}



int evaluatePostfix(string postfix) {

    stack<int> operands;

    for (char ch : postfix) {

        if (isdigit(ch)) {

            operands.push(ch - '0');

        } else {

            int b = operands.top(); operands.pop();

            int a = operands.top(); operands.pop();

            int result = applyOperation(a, b, ch);

            operands.push(result);

        }

    }

    return operands.top();

}



int main() {

    string infixExpression;

    cout << "Enter infix expression (single character operands): ";

    cin >> infixExpression;

    

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;

    cout << "Evaluation of Postfix Expression: " 

         << evaluatePostfix(postfixExpression) << endl;

    

    return 0;

}



/*

Output

MENU

1. Infix To Postfix

2. Set Variable Values

3. Postfix Calculator

4. Exit

Enter Your Choice:1

Enter a Infix Expression:(a+b/c*(d+e)-f)

Postfix Expression is :abc/de+*+fMENU

1. Infix To Postfix

2. Set Variable Values

3. Postfix Calculator

4. Exit

Enter Your Choice:2

Enter Number of Variables in Expression:5

Enter Value for 'A':25

Enter Value for 'B':78

Enter Value for 'C':12

Enter Value for 'D':4

Enter Value for 'E':3

Variables set sucessfully

MENU

1. Infix To Postfix

2. Set Variable Values

3. Postfix Calculator

4. Exit

Enter Your Choice:3

Enter Postfix Expression(Enter 0 to use last converted Expression):A+B(C/D)*E

Value of expression is 3

MENU

1. Infix To Postfix

2. Set Variable Values

3. Postfix Calculator

4. Exit

Enter Your Choice:4

Thank You!

*/
