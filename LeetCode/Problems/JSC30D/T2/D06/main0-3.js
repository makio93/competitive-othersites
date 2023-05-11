// 自力AC3

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    for (const i in nums) init = fn(init, nums[Number(i)]);
    return init;
};
