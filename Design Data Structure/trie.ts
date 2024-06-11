class Trie {
    root: Record<string, Trie> | null;
    constructor() {
        this.root = null;
    }

    insert(word: string) {
        for (let i = 0; i < word.length; i++) {
            this.root[word[i]] = new Trie() 
        }
    }
}

new Trie();