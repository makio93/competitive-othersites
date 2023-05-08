// 解説AC3

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const newArr = new Array(arr.length);
    for (var i=0; i<arr.length; ++i) newArr[i] = fn(arr[i], i);
    return newArr;
};
