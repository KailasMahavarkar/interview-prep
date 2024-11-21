class Mutex {
    private queue: (() => void)[];
    private locked: boolean;
    public count: number;

    constructor() {
        this.queue = [];
        this.locked = false;
        this.count = 0;
    }

    lock(): Promise<void> {
        return new Promise((resolve) => {
            if (!this.locked) {
                this.locked = true;
                resolve();
            } else {
                this.count++;
                this.queue.push(resolve);
            }
        });
    }

    unlock(): void {
        if (this.queue.length > 0) {
            const resolve = this.queue.shift();
            if (resolve) resolve();
        } else {
            this.locked = false;
            this.count--;
        }
    }
}

class Thread {
    private mutex: Mutex;

    constructor(mutex: Mutex) {
        this.mutex = mutex;
    }

    async run(): Promise<void> {
        await this.mutex.lock();
        try {
            console.log(`Thread ${this.mutex.count} is running`);
            await new Promise<void>((resolve) => setTimeout(resolve, 1000));
        } finally {
            this.mutex.unlock();
            console.log(`Thread ${this.mutex.count} is done`);
        }
    }
}

const mutex = new Mutex();
const thread1 = new Thread(mutex);
const thread2 = new Thread(mutex);
const thread3 = new Thread(mutex);
const thread4 = new Thread(mutex);

thread1.run();
thread2.run();
thread3.run();
thread4.run();


