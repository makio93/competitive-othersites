// 学習2回目,自力AC1

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var filteredArr = new Array();
    for (var i in arr) if (fn(arr[i], Number(i))) filteredArr.push(arr[i]);
    return filteredArr;
};
