// 自力WA2-2

/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    return new Promise((resolve) => {
        finished = new Array(functions.length, false);
        var id = 0, icnt = 0, result;
        for (var i=0; i<n; ++i) {
            if (id == functions.length) break;
            result = functions[id];
            finished[id] = true;
            while (id<finished.length && finished[id]) ++id;
        }
        for (var i=0; i<functions.length; ++i) {
            functions[i]().then(() => {
                if (icnt < functions.length) ++icnt;
                else return resolve(result);
                if (id < functions.length) {
                    result = functions[id];
                    finished[id] = true;
                    while (id<finished.length && finished[id]) ++id;
                }
            });
        }
    });
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
