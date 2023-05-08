// 解説AC5-2

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for (var i in arr) arr[i] = fn(arr[i], Number(i));
    return arr;
};
