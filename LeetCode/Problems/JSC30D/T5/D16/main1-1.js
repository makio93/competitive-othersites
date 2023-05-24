// 解説AC1

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
    let lastArgs = null, timeoutPromise = null;
    const fnTimeout = function(...args) {
        if (lastArgs === null) timeoutPromise = null;
        else {
            fn(...lastArgs);
            lastArgs = null;
            timeoutPromise = setTimeout(fnTimeout, t);
        }
    }
    return function(...args) {
        if (timeoutPromise) lastArgs = args;
        else {
            fn(...args);
            timeoutPromise = setTimeout(fnTimeout, t);
        }
    }
};
  
/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
