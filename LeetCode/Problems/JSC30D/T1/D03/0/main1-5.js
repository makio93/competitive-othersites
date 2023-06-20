// 解説AC5

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let value = init;
    return new Proxy({}, {
        get: (target, key) => {
            switch(key) {
                case "increment":
                    return () => ++value;
                case "decrement":
                    return () => --value;
                case "reset":
                    return () => value = init;
                default:
                    throw Error("Undefined Method.");
            }
        },
    });
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
