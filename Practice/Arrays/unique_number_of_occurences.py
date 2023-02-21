from collections import Counter

def uniqueOccurences(arr, size):
    carr = Counter(arr).values()
    return len(set(carr)) == len(carr)

if __name__ == '__main__':
    arr = [10, 10, 20, 20, 20, 5]
    print(uniqueOccurences(arr, 6))
