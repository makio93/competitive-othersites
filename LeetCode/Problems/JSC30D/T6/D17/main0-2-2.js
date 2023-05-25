// 自力2-2AC(ヒント有)

/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    const isEqual = function(t1, t2) {
        if (t1 === t2) return true;
        if (t1 == undefined || t2 == undefined) return false;
        if (t1 == null || t2 == null) return t1 == t2;
        if (typeof t1 != typeof t2) return false;
        if ((typeof t1) != "object" || (typeof t2) != "object") return (t1 === t2);
        if (Array.isArray(t1) != Array.isArray(t2)) return false;
        if (Array.isArray(t1)) {
            if (t1.length !== t2.length) return false;
            for (var i in t1) if (!isEqual(t1[i], t2[i])) return false;
            return true;
        }
        else {
            if (Object.keys(t1).length !== Object.keys(t2).length) return false;
            for (var key of Object.keys(t1)) if (!(key in t2) || !isEqual(t1[key], t2[key])) return false;
            return true;
        }
    }
    return isEqual(o1, o2);
};
