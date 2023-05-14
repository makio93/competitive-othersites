// 解説AC3

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memo = {};
    return function(...args) {
        let akey = args[0];
        if (args[1]) akey = akey * 100001 + args[1];
        if (akey in memo) return memo[akey];
        else {
            memo[akey] = fn(...args);
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
