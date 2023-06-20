// 解説AC4-0

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    return new class {
        constructor() {
            this.init = init;
            this.value = init;
        }
        increment = () => ++this.value;
        decrement = () => --this.value;
        reset = () => this.value = this.init;
    }();
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
