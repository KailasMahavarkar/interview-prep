function printArray(arr) {
    for (let i = 0; i < arr.length; i++) {
        console.log(arr[i] + " ");
    }
    console.log();
}

function insertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        let temp = arr[i];
        let j = i - 1;
        while (j >= 0) {
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
}

const arrayToSort = [5, 4, 1];
insertionSort(arrayToSort);

