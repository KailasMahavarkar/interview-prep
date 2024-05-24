function subsetGeneric(arr = []) {
    let n = arr.length;
    let result = [];

    const solve = (nums, temp, idx) => {
        if (idx === n) {
            result.push([...temp]);
            return;
        }

        // Exclude the current element
        solve(nums, temp, idx + 1);

        // Include the current element
        temp.push(nums[idx]);
        solve(nums, temp, idx + 1);
        temp.pop();
    };


    solve(arr, [], 0);
    return result;
}

function subsetIterative(arr = []) {
    let n = arr.length;
    let result = [];
    let temp = [];

    const solve = (nums, temp, idx) => {
        result.push([...temp]);

        for (let i = idx; i < n; i++) {
            temp.push(nums[i]);
            solve(nums, temp, i + 1);
            temp.pop();
        }
    };


    solve(arr, temp, 0);
    return result;
}

function compareArray(arr1, arr2) {
    arr1.sort();
    arr2.sort();
    if (!Array.isArray(arr1) || !Array.isArray(arr2)) {
        return false;
    }
    if (arr1.length !== arr2.length) {
        return false;
    }
    for (let i = 0; i < arr1.length; i++) {
        const el1 = arr1[i];
        const el2 = arr2[i];
        if (Array.isArray(el1) && Array.isArray(el2)) {
            if (!compareArray(el1, el2)) {
                return false;
            }
        } else {
            if (el1 !== el2) {
                return false;
            }
        }
    }
    return true;
}

const k = eval(`\`\``)
const resultGeneric = subsetGeneric([1, 2, 3]);
const resultIterative = subsetIterative([1, 2, 3]);
console.table(resultIterative);
console.table(resultGeneric);
console.log(compareArray(resultGeneric, resultIterative));