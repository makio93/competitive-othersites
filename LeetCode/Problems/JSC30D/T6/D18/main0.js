// 自力AC

/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    if (object === undefined) return "";
    if (object === null) return "null";
    if (typeof object !== "object") {
        if (typeof object === "string") return String('"') + object + '"';
        else return String(object);
    }
    let str = "";
    if (Array.isArray(object)) {
        str += "[";
        for (var i=0; i<object.length; ++i) {
            str += jsonStringify(object[i]);
            if (i+1 < object.length) str += ",";
        }
        str += "]";
        return str;
    }
    str += "{";
    for (const key in object) {
        str += '"' + String(key) + '"' + ':';
        str += jsonStringify(object[key]);
        str += ",";
    }
    if (str.slice(-1) === ",") str = str.slice(0, -1);
    str += "}";
    return str;
};
