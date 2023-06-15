// 解説AC1-2

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        let val = x;
        for (const func of functions.reverse()) val = func.call(this, val);
        return val;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
