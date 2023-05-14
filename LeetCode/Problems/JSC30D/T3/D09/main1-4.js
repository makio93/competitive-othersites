// 解説AC4

/**
 * @param {Function} fn
 */
var memoize = (fn, memo = {}) => (...args) => memo[args.join()] ?? (memo[args.join()] = fn(...args));


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
