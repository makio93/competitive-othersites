// 解説AC2

/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    async function evalNext() {
        if (functions.length === 0) return;
        const func = functions.shift();
        await func();
        await evalNext();
    }
    const Proms = new Array(n).fill().map(evalNext);
    await Promise.all(Proms);
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
