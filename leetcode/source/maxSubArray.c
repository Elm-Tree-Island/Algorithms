//
//  maxSubArray.c
//
//  Created by Mark on 2019/4/25.
//  Copyright © 2019 Mark Chen. All rights reserved.
//

#include <stdio.h>

// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/
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

// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
int maxProfit(int* prices, int pricesSize){
    if (pricesSize <= 0) {
        return 0;
    }
    
    /** Brute Force **/
    //     int max_profit = 0;
    //     int buy = 0;
    //     int sell = 0;
    //     for (int i = 0; i<pricesSize; i++) {
    //         for (int j = i+1; j<pricesSize; j++) {
    //             int profit = prices[j] - prices[i];
    //             if (profit > max_profit) {
    //                 max_profit = profit;
    //                 buy = i;
    //                 sell = j;
    //             }
    //         }
    //     }
    
    //     printf("Buy at %d, Sell at %d", prices[buy], prices[sell]);
    //     return max_profit;
    

    /** Other Way **/
    int max_profit = 0;
    
}




