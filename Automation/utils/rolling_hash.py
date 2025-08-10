import hashlib

class RollingHash:
    """Rolling hash implementation for efficient file change detection"""

    def __init__(self, window_size=1024):
        self.window_size = window_size
        self.base = 256
        self.mod = 10**9 + 7

    def compute_hash(self, data: bytes) -> str:
        """Compute rolling hash for the entire file content"""
        if len(data) == 0:
            return "0"

        # For files smaller than window, use simple hash
        if len(data) <= self.window_size:
            return hashlib.sha256(data).hexdigest()[:16]

        # Rolling hash for larger files
        hash_value = 0
        power = 1

        # Compute hash for first window
        for i in range(min(self.window_size, len(data))):
            hash_value = (hash_value + (data[i] * power)) % self.mod
            if i < self.window_size - 1:
                power = (power * self.base) % self.mod

        hashes = [hash_value]

        # Roll the hash through the rest of the data
        for i in range(self.window_size, len(data)):
            # Remove leftmost character
            hash_value = (hash_value - (data[i - self.window_size] * power)) % self.mod
            # Add new rightmost character
            hash_value = (hash_value * self.base + data[i]) % self.mod
            hashes.append(hash_value)

        # Combine all hashes into final hash
        final_hash = hashlib.sha256(str(hashes).encode()).hexdigest()[:16]
        return final_hash
