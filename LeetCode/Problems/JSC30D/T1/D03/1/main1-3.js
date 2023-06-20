// 学習1回目,解説AC3

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var val = init;
    return new Proxy({}, {
        get: (target, key) => {
            if (key == "increment") return () => ++val;
            else if (key == "decrement") return () => --val;
            else if (key == "reset") return () => val = init;
        }
    });
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
