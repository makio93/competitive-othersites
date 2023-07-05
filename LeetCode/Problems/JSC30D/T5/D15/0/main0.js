// 自力AC

/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let tTime = -1;
    var promise = undefined;
    return function(...args) {
        if (tTime != -1) clearTimeout(promise);
        tTime = Date.now() + t;
        promise = setTimeout(() => {
            tTime = -1;
            fn(...args);
        }, t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
