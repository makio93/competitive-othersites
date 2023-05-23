// 解説AC1

/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    var promise = undefined;
    return function(...args) {
        clearTimeout(promise);
        promise = setTimeout(() => fn(...args), t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */
