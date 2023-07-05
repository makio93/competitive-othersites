// 学習1回目,解説AC2

/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    var timeout = undefined;
    return function(...args) {
        clearInterval(timeout);
        timeout = setInterval(() => {
            fn(...args);
            clearInterval(timeout);
        }, t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
