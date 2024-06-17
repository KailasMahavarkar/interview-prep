import time
from collections import deque


class TimerWheel:
    def __init__(self, num_slots, capacity):
        self.num_slots = num_slots
        self.capacity = capacity
        self.slots = [deque() for _ in range(num_slots)]
        self.current_slot = 0
        self.total_requests = 0

    def advance(self):
        self.current_slot = (self.current_slot + 1) % self.num_slots
        cleared_requests = len(self.slots[self.current_slot])
        self.total_requests -= cleared_requests
        self.slots[self.current_slot].clear()

    def allow_request(self):
        if self.total_requests < self.capacity:
            self.slots[self.current_slot].append(time.time())
            self.total_requests += 1
            return True
        else:
            return False


class RateLimiter:
    def __init__(self, capacity, time_span):
        self.capacity = capacity
        self.time_span = time_span
        self.num_slots = 10
        self.slot_time = time_span / self.num_slots
        self.timer_wheel = TimerWheel(self.num_slots, capacity)
        self.last_check = time.time()

    def is_allowed(self):
        current_time = time.time()
        elapsed_time = current_time - self.last_check
        slots_to_advance = int(elapsed_time / self.slot_time)

        if slots_to_advance > 0:
            for _ in range(min(slots_to_advance, self.num_slots)):
                self.timer_wheel.advance()
            self.last_check = current_time

        return self.timer_wheel.allow_request()


if __name__ == "__main__":
    capacity = 3
    time_span = 10

    rate_limiter = RateLimiter(capacity, time_span)

    for i in range(15):
        if rate_limiter.is_allowed():
            print(f"Request {i + 1} allowed.")
        else:
            print(f"Request {i + 1} denied.")
        time.sleep(1)
