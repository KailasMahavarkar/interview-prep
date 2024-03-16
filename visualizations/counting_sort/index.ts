function countingSort(nums) {
    const n = nums.length;
    const maxElement = Math.max(...nums);
    const count = new Array(maxElement + 1).fill(0);
    const result = new Array(n);

    for (let i = 0; i < n; i++) {
        count[nums[i]]++;
    }

    for (let i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    for (let i = n - 1; i >= 0; i--) {
        result[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }

    return result;
}

// Example usage:
const arr = [4, 2, 2, 8, 3, 3, 1];
const sortedArr = countingSort(arr);
console.log(sortedArr); // Output: [1, 2, 2, 3, 3, 4, 8]
