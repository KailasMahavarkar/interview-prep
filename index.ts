class Solution {
    constructor() {
        this.n = 0;
        this.dp = new Array(51).fill(-1);
        this.st = new Set();
    }

    solve(idx, s) {
        if (idx >= this.n) {
            return 0;
        }

        if (this.dp[idx] !== -1) {
            return this.dp[idx];
        }

        let currStr = "";
        let minExtra = this.n;

        for (let i = idx; i < this.n; i++) {
            currStr += s[i];
            console.log(currStr);
            let currExtra = this.st.has(currStr) ? 0 : currStr.length;
            let nextExtra = this.solve(i + 1, s);
            let totalExtra = currExtra + nextExtra;
            minExtra = Math.min(totalExtra, minExtra);
        }
        return this.dp[idx] = minExtra;
    }

    minExtraChar(s, dictionary) {
        this.n = s.length;
        this.dp.fill(-1);
        for (let word of dictionary) {
            this.st.add(word);
        }
        return this.solve(0, s);
    }
}

// Example usage:
const solution = new Solution();
const s = "leetcode";
const dictionary = ["a", "bcd", "de"];
console.log(solution.minExtraChar(s, dictionary));
