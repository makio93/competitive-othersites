// 学習1回目,自力AC2

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var filteredArr = [];
    for (var i in arr) if (fn(arr[i], Number(i))) filteredArr.push(arr[i]);
    return filteredArr;
};
