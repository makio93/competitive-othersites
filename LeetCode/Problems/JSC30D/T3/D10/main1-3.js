// 解説AC3

/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    return function curried(...args) {
        if (args.length === 0) return fn(...args);
        return (...nextArgs) => {
            if (nextArgs.length === 0) return fn(...args);
            return curried(...args, ...nextArgs);
        };
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
