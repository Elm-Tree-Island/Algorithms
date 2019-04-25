//
//  https://leetcode.com/problems/min-stack/
//
//  minStack.c
//
//  Created by Mark on 2019/4/24.
//  Copyright © 2019 Mark Chen. All rights reserved.
//

#include "minStack.h"
#include <stdlib.h>

typedef struct {
    int val;
    int min_val;
} MinStackElement;

typedef struct {
    int size;
    int top;
    MinStackElement *values;
} MinStack;

int minValue = 0;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    if (maxSize <= 0) {
        return NULL;
    }
    
    MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
    stack->values = (MinStackElement *)malloc(sizeof(MinStackElement) * maxSize);
    stack->size = maxSize;
    stack->top = -1;
    
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top < obj->size) {
        if (obj->top == -1) {   // 栈为空，直接赋值
            obj->top = 0;
            MinStackElement *element = (MinStackElement *)(obj->values)+obj->top;
            element->val = x;
            element->min_val = x;
        } else {
            obj->top = obj->top + 1;
            MinStackElement *element = (MinStackElement *)(obj->values)+obj->top;
            element->val = x;
            // 对比之前最小值与当前要插入的值，若更小，则更新之，反之继续用原来的值
            MinStackElement *prev_element = (MinStackElement *)(obj->values)+obj->top-1;
            if (prev_element->min_val <= x) {
                element->min_val = prev_element->min_val;
            } else {
                element->min_val = x;
            }
        }
    } else {
        // Error
    }
}

void minStackPop(MinStack* obj) {
    if (obj != NULL) {
        if (obj->top == -1) {
            // Empty Stack
        } else {
            obj->top -= 1;
        }
    }
}

int minStackTop(MinStack* obj) {
    if (obj && obj->values) {
        MinStackElement *element = obj->values+obj->top;
        return element->val;
    } else {
        return 0;
    }
}

int minStackGetMin(MinStack* obj) {
    if (obj) {
        MinStackElement *element = obj->values+obj->top;
        return element->min_val;
    } else {
        return -10000;
    }
}

void minStackFree(MinStack* obj) {
    if (obj) {
        if (obj->values) {
            free(obj->values);
            obj->values = NULL;
        }
        
        free(obj);
        obj = NULL;
    }
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
