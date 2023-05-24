// 解説AC2

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
    let lastArgs = null, timeoutPromise = null;
    const fnInterval = function(...args) {
        if (lastArgs === null) {
            clearInterval(timeoutPromise);
            timeoutPromise = null;
        }
        else {
            fn(...lastArgs);
            lastArgs = null;
        }
    }
    return function(...args) {
        if (timeoutPromise) lastArgs = args;
        else {
            fn(...args);
            timeoutPromise = setInterval(fnInterval, t);
        }
    }
};
  
/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
