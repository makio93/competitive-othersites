// 自力WA

var TimeLimitedCache = function() {
    class TimeLimitedCache {
        constructor() {
            this.dict = new Map();
        }
    };
    TimeLimitedCache.prototype.set = function(key, value, duration) {
        if (this.dict.has(key)) {
            clearTimeout(this.dict.get(key).get('prom'));
            var promId = new Promise(res => {
                this.key = key;
                setTimeout(res, duration);
            });
            const tmp = new Map([['val', value], ['prom', promId]]);
            this.dict.set(key, tmp);
            promId.then(() => {
                this.dict.delete(this.key);
            });
            return true;
        }
        else {
            var promId = new Promise(res => {
                this.key = key;
                setTimeout(res, duration);
            });
            const tmp = new Map([['val', value], ['prom', promId]]);
            this.dict.set(key, tmp);
            promId.then(() => {
                this.dict.delete(this.key);
            });
            return false;
        }
    };
    TimeLimitedCache.prototype.get = function(key) {
        if (this.dict.has(key)) return this.dict.get(key).get('val');
        else return -1;
    };
    TimeLimitedCache.prototype.count = function() {
        return this.dict.size;
    };
    return new TimeLimitedCache();
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
