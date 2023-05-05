// 学習3

/**
 * @return {Function}
 */

const createHelloWorld = (function() {
    return function() { return function() {
        return "Hello World";
    };};
})();

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
