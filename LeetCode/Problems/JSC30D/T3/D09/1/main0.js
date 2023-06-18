// 学習1回目,自力AC

/**
 * @param {Function} fn
 */
function memoize(fn) {
    let memo = new Map();
    return function(...args) {
        if (memo.has(args.toString())) return memo.get(args.toString());
        memo.set(args.toString(), fn(...args));
        return memo.get(args.toString());
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
