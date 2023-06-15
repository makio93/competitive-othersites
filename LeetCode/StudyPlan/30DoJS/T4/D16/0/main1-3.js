// 解説AC3

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
	return async function(...args) {
        const timeoutPromise = new Promise((res, rej) => {
            setTimeout(() => rej("Time Limit Exceeded"), t);
        });
        const originalPromise = fn(...args);
        return Promise.race([timeoutPromise, originalPromise]);
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
