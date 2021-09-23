

/**
 * 跨越中点的处理函数
 * @param {number[]} arr  数组
 * @param {number} low 起始位置
 * @param {number} middle 中间位置
 * @param {number} height  终止位置
 */
const maxCorssingSum = (arr, low, middle, height) => {
    let sum = 0;
    let leftSum = Number.MIN_VALUE;
    for (let index = middle; index >= low; index--) {
        sum += arr[index];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    let rightSum = Number.MIN_VALUE;
    for (let index = middle + 1; index <= height; index++) {
        sum += arr[index];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return Math.max(
        leftSum + rightSum,
        leftSum,
        rightSum
    )
}

/**
 * 最大子数组问题求解函数
 * @param {number[]} arr 数组
 * @param {number} low  起始位置
 * @param {number} height 终止位置
 */
const maxSubArraySum = (arr, low, height) => {
    // 位置一致 
    if (low === height) return arr[low];
    const mid = (low + height) >> 1;
    return Math.max(
        maxSubArraySum(arr, low, mid),
        maxSubArraySum(arr, mid + 1, height),
        maxCorssingSum(arr, low, mid, height)
    )
}

const arr = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7];

const result = maxSubArraySum(arr, 0, arr.length - 1);

console.log("result  = %d ", result);