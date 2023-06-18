// 学習1回目,自力AC1

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    return arr.filter((value, index, array) => fn(value, index));
};
