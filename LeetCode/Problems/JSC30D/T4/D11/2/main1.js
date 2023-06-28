// 学習2回目,解説AC

/**
 * @param {number} millis
 */
async function sleep(millis) {
    return new Promise(res => { setTimeout(res, millis) });
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
