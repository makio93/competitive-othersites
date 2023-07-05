// 学習1回目,自力AC

/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    var timeout = undefined;
    return function(...args) {
        if (timeout != undefined) clearTimeout(timeout);
        timeout = setTimeout(() => {
            fn(...args);
            timeout = undefined;
        }, t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
