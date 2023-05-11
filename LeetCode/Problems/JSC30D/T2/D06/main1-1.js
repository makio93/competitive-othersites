// 解説AC1

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var val = init;
    for (const num of nums) val = fn(val, num);
    return val;
};
