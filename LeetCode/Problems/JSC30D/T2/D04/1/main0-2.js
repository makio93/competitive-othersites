// 学習1回目,自力AC2

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for (var i in arr) arr[Number(i)] = fn(arr[Number(i)], Number(i));
    return arr;
};
