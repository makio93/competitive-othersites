// 学習1回目,自力AC1

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    return arr.map((value, index, array) => array[index] = fn(value, index), this);
};
