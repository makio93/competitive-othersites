// 解説AC2

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memo = {};
    return function() {
        let akey = '';
        for (const key of arguments) akey += ',' + key;
        if (akey in memo) return memo[akey];
        else {
            memo[akey] = fn(...arguments);
            return memo[akey];
        }
    }
}

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
