// 学習1回目,解説AC

var TimeLimitedCache = function() {
    this.dict = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let is_exist = false;
    if (this.dict.has(key)) {
        clearTimeout(this.dict.get(key).promise);
        is_exist = true;
    }
    this.dict.set(key, { value, promise: setTimeout(() => {
        this.dict.delete(key);
    }, duration) });
    return is_exist;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    return this.dict.has(key) ? this.dict.get(key).value : -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.dict.size;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
