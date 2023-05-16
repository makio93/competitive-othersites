// 自力WA

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
	return async function(...args) {
        let start = Date.now(), id = fn(t);
        while (Date.now()-start<=t && id===undefined) ;
        if (Date.now()-start > t) console.log("Time Limit Exceeded");
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */
