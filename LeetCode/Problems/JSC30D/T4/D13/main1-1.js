// 解説AC1

/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    return new Promise(resolve => {
        var id = 0, icnt = 0;
        function helper() {
            if (id == functions.length) {
                if (icnt == 0) resolve();
                return;
            }
            while (id<functions.length && icnt<n) {
                ++icnt;
                const prom = functions[id++]();
                prom.then(() => {
                    --icnt;
                    helper();
                });
            }
        }
        helper();
    });
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
