class RateLimiter {
    constructor(limitPerInterval, intervalInSeconds) {
        this.segmentCount = intervalInSeconds; // Each segment represents 1 second
        this.segments = new Array(this.segmentCount).fill(null).map(() => []);
        this.limitPerInterval = limitPerInterval;
        this.intervalInSeconds = intervalInSeconds;
        this.currentSegmentIndex = 0;

        // Simulate the passage of time by moving to the next segment every second
        this.intervalTimer = setInterval(() => {
            this.moveNextSegment();
        }, 1000); // Simulate 1-second intervals
    }

    moveNextSegment() {
        // Move to the next segment and reset the requests array for the new segment
        this.currentSegmentIndex = (this.currentSegmentIndex + 1) % this.segmentCount;
        this.segments[this.currentSegmentIndex] = [];
    }

    async checkAndConsume(clientId) {
        // Count requests for the current segment
        const requestsInCurrentSegment = this.segments[this.currentSegmentIndex].filter(req => req === clientId).length;

        // Check if the client has exceeded the limit for the current interval
        if (requestsInCurrentSegment >= this.limitPerInterval) {
            console.log(`Rate limit exceeded for client ${clientId} in the last ${this.intervalInSeconds} seconds.`);
            return false;
        }

        // Add the request to the current segment
        this.segments[this.currentSegmentIndex].push(clientId);
        console.log(`Request from client ${clientId} accepted.`);

        return true;
    }

    async close() {
        // Stop the interval timer when done
        clearInterval(this.intervalTimer);
    }
}

// Example usage:
async function testRateLimiter() {
    const rateLimiter = new RateLimiter(3, 60); // 100 requests per minute

    // Simulate requests
    for (let i = 0; i < 120; i++) { // Make 120 requests (over 2 minutes)
        const clientId = `Client-${Math.floor(Math.random() * 5)}`; // Random client ID
        const allowed = await rateLimiter.checkAndConsume(clientId);
        if (!allowed) {
            console.log(`Request from client ${clientId} blocked.`);
        }
        await sleep(100); // Simulate some delay between requests
    }

    await rateLimiter.close(); // Stop the rate limiter when done
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

// Run the test
testRateLimiter().catch(err => console.error(err));
