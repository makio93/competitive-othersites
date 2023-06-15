// 自力AC1

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        if (!functions.length) return x;
        else return functions[0](compose(functions.slice(1))(x));
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
