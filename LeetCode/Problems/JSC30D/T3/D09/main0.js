// 自力AC

/**
 * @param {Function} fn
 */
function memoize(fn) {
    var memo = new Map();
    return function(...args) {
        const akey = args.toString();
        if (memo.has(akey)) return memo.get(akey);
        else {
            memo.set(akey, fn(...args));
            return memo.get(akey);
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
