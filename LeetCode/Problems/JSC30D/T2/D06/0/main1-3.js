// 解説AC3

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var val = init;
    for (const i in nums) val = fn(val, nums[i]);
    return val;
};
