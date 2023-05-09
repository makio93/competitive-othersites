// 解説AC4

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let size = 0;
    for (var i=0; i<arr.length; ++i) if (fn(arr[i], i)) {
        arr[size] = arr[i];
        ++size;
    }
    while (arr.length > size) arr.pop();
    return arr;
};
