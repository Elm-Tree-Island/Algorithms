//
//  maxSubArray.c
//
//  Created by Mark on 2019/4/25.
//  Copyright © 2019 Mark Chen. All rights reserved.
//

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    
    int max = nums[0];
    int sum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum > max) {
            max = sum;
        }
        if (sum < 0) {      // Attention, not 'else if'
            sum = 0;
        }
    }
    
    return max;
}
