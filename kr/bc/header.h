#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 * 中缀表达式转换为后缀表达式（逆波兰表达式）
 */
void infix_to_postfix(char* infix, char* postfix);

/**
 * 计算后缀表达式的值
 */
int evaluate_postfix(char* postfix);