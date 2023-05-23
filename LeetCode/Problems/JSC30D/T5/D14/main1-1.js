// 解説AC1

class TimeLimitedCache {
    cache = new Map();
    set(key, value, duration) {
        var ret = this.cache.has(key);
        if (ret) clearTimeout(this.cache.get(key).promise);
        var promise = setTimeout(() => this.cache.delete(key), duration);
        this.cache.set(key, { value, promise });
        return ret;
    }
    get = (key) => this.cache.has(key) ? this.cache.get(key).value : -1;
    count = () => this.cache.size;
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */

/** 
 * @param {number} key
 * @return {number} value associated with key
 */


/** 
 * @return {number} count of non-expired keys
 */


/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
