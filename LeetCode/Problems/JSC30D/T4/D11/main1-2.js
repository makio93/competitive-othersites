// 解説AC2

/**
 * @param {number} millis
 */
async function sleep(millis) {
    return new Promise((resolve, reject) => {
        try {
            setTimeout(resolve, millis);
        }
        catch (error) {
            reject(error);
        }
    });
};

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
