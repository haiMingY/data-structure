function sort(arr) {
    quickSort(arr, 0, arr.length - 1);
}

function quickSort(arr, begin, end) {
    if (begin < end) {

        let left = begin;
        let right = end;
        let mid = (begin + end) >> 1;
        swap(arr, left, mid)
        let t = arr[left];
        while (left < right) {
            while (left < right && t <= arr[right]) { //从后向前找第一个大于t基数的数
                right--;
            }
            arr[left] = arr[right] //将找到的数放到基数位置
            while (left < right && arr[left] <= t) {//从前向后找第一个小于t基数的数
                left++;
            }
            arr[right] = arr[left];////将找到的数放到之前那个right 位置
        }
        arr[left] = t;
        quickSort(arr, begin, left - 1);
        quickSort(arr, left + 1, end);
    }

}


function swap(arr, first, second) {
    let temp = arr[first]
    arr[first] = arr[second]
    arr[second] = temp
}


function create() {
    let arr = []
    for (let index = 0; index < 30; index++) {
        arr.push(Math.floor(Math.random() * 10000 + 1));
    }
    return arr;
}


let array = create()

sort(array)

console.log(array);
