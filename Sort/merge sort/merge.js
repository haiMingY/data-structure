

let $$temparr = [];
function sort(arr) {
    mergeSortDown(arr);
    // mergeSortUp(arr, 0, arr.length - 1);
}

function mergeSortUp(arr, left, right) { //自底向上
    if (left < right) {
        let center = left + ((right - left) >> 1);
        mergeSortUp(arr, left, center);
        mergeSortUp(arr, center + 1, right);
        merge(arr, left, center + 1, right);
    }
}

function mergeSortDown(arr) { //自顶向下
    let n = arr.length;
    for (let sz = 1; sz < n; sz += sz) {
        for (let lo = 0; lo < n - sz; lo += sz + sz) {
            merge(arr, lo, lo + sz, Math.min(n - 1, lo + sz + sz - 1));
        }

    }
}

function merge(arr, left, mid, right) {
    let leftEnd = mid - 1;
    let index = left;
    let nums = right - left + 1;
    while (left <= leftEnd && mid <= right) {
        if (arr[left] >= arr[mid]) { //大于
            $$temparr[index++] = arr[mid++];
        } else {
            $$temparr[index++] = arr[left++];
        }
    }
    while (left <= leftEnd) {
        $$temparr[index++] = arr[left++];
    }

    while (mid <= right) {
        $$temparr[index++] = arr[mid++];
    }

    for (let t = 0; t < nums; t++) { //重新赋值给原有的数组
        arr[right] = $$temparr[right]
        right--
    }

}
function create() {
    let arr = []
    for (let index = 0; index < 30; index++) {
        arr.push(Math.floor(Math.random() * 10000 + 1));
    }
    return arr;
}
let arr = create();
console.log(arr);

sort(arr)

console.log(arr);
