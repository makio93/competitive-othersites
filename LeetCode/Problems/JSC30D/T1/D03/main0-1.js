// 自力AC1

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    return new (class {
        constructor(init) {
            this.init = init;
            this.value = init;
        }
        increment() {
            return ++this.value;
        }
        decrement() {
            return --this.value;
        }
        reset() {
            return this.value = this.init;
        }
    })(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
