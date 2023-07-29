// 学習2回目,解説AC2

/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let val = init;
    return new class {
        constructor() {
            this.init = init;
            this.val = init;
        }
        increment = () => ++this.val;
        decrement = () => --this.val;
        reset = () => this.val = this.init;
    }();
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
