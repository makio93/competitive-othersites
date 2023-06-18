// 学習1回目,解説AC1

/**
 * @param {Function} fn
 */
function memoize(fn) {
    let memo = {};
    return function(...args) {
        const key = JSON.stringify(args);
        if (key in memo) return memo[key];
        return memo[key] = fn(...args);
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
