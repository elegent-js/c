#include "header.h"

/**
 * 接收用户输入的中缀表达式，转换为后缀表达式，最后输出计算结果
 */
int main(int argc, char *argv[])
{
    char infix[100];
    char postfix[100];

    printf("请输入中缀表达式：");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("后缀表达式：%s\n", postfix);

    // 计算后缀表达式的值
    int result = evaluate_postfix(postfix);
    printf("计算表达式：%s, 计算结果：%d\n", infix, result);
    return 0;
}

