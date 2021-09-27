// 反转计数

/**
 * 
 * @param {number[]} arr 
 */
 const count = (arr) => {
    return merge_count(arr, 0, arr.length - 1)
}

/**
 * 
 * @param {number[]} arr 
 * @param {number} left 
 * @param {number} right 
 */
const merge_count = (arr, left, right) => {
    if (left >= right) return 0;
    const mid = (left + right) >> 1;
    let count = 0;
    count += merge_count(arr, left, mid);
    count += merge_count(arr, mid + 1, right);
    count += merge(arr, left, mid + 1, right);
    return count;

}

const merge = (arr, left, mid, right) => {

    let count = 0;
    let i = left;
    let j = mid;
    while (i <= mid - 1 && j <= right) {
        if (arr[i] > arr[j]) {
            count += (mid - i)
            j++;
        } else {
            i++;
        }
    }

    return count;
}

const arr = [8, 4, 2, 1]

const nums = count(arr);
console.log(nums);