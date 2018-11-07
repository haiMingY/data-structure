

/**
 * 
 * @param {Array} arr  //需要旋转的数组
 * @param {Number} n  数组的长度
 */
function leftRotateByOne(arr, n) { //运行一次只将第一个元素换到最后的位置
    let temp = arr[0]
    let index;
    for (index = 0; index < n - 1; index++) {
        arr[index] = arr[index + 1]
    }
    arr[index] = temp;
}

/**
 * 
 * @param {Array} arr  //需要旋转的数组
 * @param {Number} d  // 转换几次
 * @param {Number} n 
 */
function leftRotate(arr, d, n) {
    for (let index = 0; index < d; index++) {
        leftRotateByOne(arr, n)
    }
}

/**
 * 
 * @param {Array} arr 
 */
function printArray(arr) {
    console.log(arr.join(" "));
}

/**
 * 
 * @param {Array} arr  //需要旋转的数组
 * @param {Number} d  // 转换几次
 * @param {Number} n 
 */
function gcdLeftRotate(arr, d, n) {
    let j;
    let temp;
    let k;
    let g = gcd(d, n)
    for (let index = 0; index < g; index++) {
        temp = arr[index]
        j = index
        while (true) {
            k = j + d  //每次增加 d
            if (k >= n) {
                k -= n;
            }
            if (k === index) {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp
    }
}
/**
 * 最大公约数
 * @param {Number} a 
 * @param {Number} b 
 */
function gcd(a, b) {
    if (b === 0) {
        return a
    } else {
        return gcd(b, a % b)
    }
}

let arr = [1, 2, 3, 4, 5, 6, 7]

// leftRotate(arr, 4, arr.length);
gcdLeftRotate(arr, 6, arr.length);
printArray(arr);