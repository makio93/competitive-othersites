// 自力AC

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
    var lastArgs = undefined;
    var promise = undefined;
    function fnCall(...args) {
        lastArgs = args;
        if (!promise) {
            fn(...lastArgs);
            lastArgs = undefined;
            promise = setTimeout(() => {
                promise = undefined;
                if (lastArgs) fnCall(...lastArgs);
            }, t);
        }
    }
    return (...args) => fnCall(...args);
};
  
/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
