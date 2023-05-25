// 解説AC2

/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    var ost = [];
    ost.push([o1, o2]);
    while (ost.length) {
        [t1, t2] = ost.pop();
        if (t1 === t2) continue;
        if (typeof t1 !== "object" || typeof t2 !== "object") return false;
        if (Array.isArray(t1) !== Array.isArray(t2)) return false;
        const s1 = Object.keys(t1), s2 = Object.keys(t2);
        if (s1.length !== s2.length) return false;
        for (const key of s1) {
            if (!(key in t2)) return false;
            ost.push([t1[key], t2[key]]);
        }
    }
    return true;
};
