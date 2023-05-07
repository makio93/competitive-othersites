// 解説AC4-1

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
class Counter {
    constructor(init) {
        this.init = init;
        this.value = init;
    }
    increment = () => ++this.value;
    decrement = () => --this.value;
    reset = () => this.value = this.init;
}
var createCounter = function(init) {
    return new Counter(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
