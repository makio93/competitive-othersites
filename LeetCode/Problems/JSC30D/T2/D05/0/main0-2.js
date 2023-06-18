// 自力AC2

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var len = arr.length
    for (var i=0; i<len; ++i) {
        if (fn(arr[0], Number(i))) arr.push(arr[0]);
        arr.shift();
    }
    return arr;
};
