// 解説AC3

/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    return typeof object === "string" ? `"${object}"` : 
        object === null || typeof object !== "object" ? String(object) :
        Array.isArray(object) ? "[" + object.map((element) => jsonStringify(element)).join(',') + "]" : 
        "{" + Object.keys(object).map((key) => `"${key}":${jsonStringify(object[key])}`).join(',') + "}";
};
