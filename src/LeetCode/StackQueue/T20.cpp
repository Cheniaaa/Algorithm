#include <iostream>
#include <cstdio>
#include "stack"
#include "unordered_map"

using namespace std;

#define Stack_Init_Size 30

typedef struct {
    char *base;
    char *top;
    int size;
} MyStack;


int initStack(MyStack *stack) {
    stack->base = (char *) malloc(Stack_Init_Size * sizeof(char));
    if (!stack->base) {
        printf("不能分配");
        exit(-1);
    }
    stack->top = stack->base;
    stack->size = Stack_Init_Size;
    printf("栈初始化成功\n");
    return 1;
}

bool emptyStack(MyStack *stack) {
    if (stack->top == stack->base) {
        return true;
    }
    return false;
}

int push(MyStack *stack, char elem) {
    if (stack->top - stack->base >= stack->size) {
        stack->base = (char *) realloc(stack->base, (stack->size + 10) * sizeof(char));
        if (!stack->base) { return -1; }
        stack->top = stack->base + stack->size;
        stack->size += 10;
    }
    *(stack->top++) = elem;
    return 1;
}

char pop(MyStack *stack) {
    if (emptyStack(stack)) { exit(-1); }
    char e = *(--stack->top);
    return e;
}

char top(MyStack *stack) {
    if (stack->top - stack->base > 0) {
        char c = *(stack->top - 1);
        return c;
    }
}


bool invalid(string s) {
    if (s.length() % 2 == 1) {
        return false;
    }
    unordered_map<char, char> map = {
            {'}', '{'},
            {']', '['},
            {')', '('}
    };

    stack<char> stack;
    for (char item: s) {
        if (map.count(item)) {
            if (stack.empty() || stack.top() != map[item]) {
                return false;
            }
            stack.pop();
        } else {
            stack.push(item);
        }
    }
    return stack.empty();
}


int main() {
    string s = "{{}}";
    if (invalid(s)) {
        cout << "匹配成功";
    } else {
        cout << "匹配失败";
    }
    return 0;
}
