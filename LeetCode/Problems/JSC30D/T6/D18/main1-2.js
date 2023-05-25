// 解説AC2

/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    switch (typeof object) {
        case "object":
            if (Array.isArray(object)) {
                const elements = object.map((element) => jsonStringify(element));
                return `[${elements.join(',')}]`;
            }
            else if (object) {
                const keyValues = Object.keys(object).map((key) => `"${key}":${jsonStringify(object[key])}`);
                return `{${keyValues.join(',')}}`;
            }
            else return "null";
        case "string":
            return `"${object}"`;
        case "boolean":
        case "number":
            return String(object);
        default:
            return "";
    }
};
