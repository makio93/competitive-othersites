// 解説AC1

/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    if (object === null) return "null";
    if (Array.isArray(object)) {
        const elements = object.map((element) => jsonStringify(element));
        return `[${elements.join(',')}]`;
    }
    if (typeof object === "string") return `"${object}"`;
    if (typeof object === "object") {
        const keyValues = Object.keys(object).map((key) => `"${key}":${jsonStringify(object[key])}`);
        return `{${keyValues.join(',')}}`;
    }
    return String(object);
};
