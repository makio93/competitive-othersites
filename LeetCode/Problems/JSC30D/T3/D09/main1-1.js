// 解説AC1

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memo = {};
    return function(...args) {
        const akey = JSON.stringify(args);
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
