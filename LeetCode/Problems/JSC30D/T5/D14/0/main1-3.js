// 解説AC3

class TimeLimitedCache {
    cache = {};
    set(key, value, duration) {
        var ret = key in this.cache && Date.now() < this.cache[key].expiration;
        this.cache[key] = { value, expiration: Date.now()+duration };
        return ret;
    }
    get = (key) => this.cache[key] && Date.now() < this.cache[key].expiration ? this.cache[key].value : -1;
    count() {
        let cnt = 0;
        for (const entry of Object.values(this.cache)) if (Date.now() < entry.expiration) ++cnt;
        return cnt;
    }
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
