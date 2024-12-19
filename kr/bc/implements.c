#include "header.h"


// 判断字符是否是操作数
int is_operand(char c) {
    return isdigit(c);
}

// 定义运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}

// 运算符与栈中运算符的优先级比较
int is_left_associative(char op) {
    return (op != '^');  // `^` 是右结合的，其它是左结合
}

// 执行基本的算术运算
int apply_operator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b); // 计算幂
        default: return 0;
    }
}

int isBlank(char c) {
    return c == ' ' || c == '\t';
}

/**
 * 中缀表达式转换为后缀表达式（逆波兰表达式）实现
 */
void infix_to_postfix(char* infix, char* postfix)
{
    char stack[100];

    int top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isBlank(current)) {
            continue;
        }

        if (is_operand(current)) {
            postfix[k++] = current;  // 如果是操作数，直接放入后缀表达式
        } else if (current == '(') {
            stack[++top] = current;  // 左括号压栈
        } else if (current == ')') {
            // 右括号，弹出栈中运算符直到遇到左括号
            while (top >= 0 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;  // 弹出左括号
        } else if (strchr("+-*/^", current)) {
            // 当前字符是运算符
            while (top >= 0 && precedence(stack[top]) >= precedence(current) && is_left_associative(current)) {
                postfix[k++] = stack[top--];  // 弹出优先级更高或相等的运算符
            }
            stack[++top] = current;  // 当前运算符压栈
        }
    }

    // 弹出栈中剩余的运算符
    while (top >= 0) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';  // 结束字符
}

/**
 * 计算后缀表达式的值
 */
int evaluate_postfix(char* postfix)
{
    int stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];

        if (is_operand(current)) {
            stack[++top] = current - '0';  // 将数字字符转换为整数并压栈
        } else if (strchr("+-*/^", current)) {
            int b = stack[top--];  // 弹出右操作数
            int a = stack[top--];  // 弹出左操作数
            int result = apply_operator(a, b, current);
            stack[++top] = result;  // 将运算结果压栈
        }
    }

    return stack[top];  // 栈顶即为结果

}