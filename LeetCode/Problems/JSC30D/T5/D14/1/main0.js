// 学習1回目,自力AC

let dict;
var TimeLimitedCache = function() {
    dict = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let is_exist = false;
    if (dict.has(key)) {
        clearTimeout(dict.get(key).promise);
        is_exist = true;
    }
    dict.set(key, { val: value, promise: setTimeout(() => {
        dict.delete(key);
    }, duration) });
    return is_exist;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (dict.has(key)) return dict.get(key).val;
    else return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return dict.size;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
