// 自力AC2

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let value = init;
    return new (class {
        constructor() {}
        increment() {
            return ++value;
        }
        decrement() {
            return --value;
        }
        reset() {
            return value = init;
        }
    })(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
