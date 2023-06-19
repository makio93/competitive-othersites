// 自力AC

/**
 * @param {number} millis
 */
async function sleep(millis) {
    const start = new Date();
    while ((new Date()).getTime()-start.getTime() < millis) ;
    return millis;
};

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
