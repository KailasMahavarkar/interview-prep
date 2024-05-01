def min_people_unable_to_attend(people, start_time, end_time):
    events = []
    for x in range(len(start_time)):
        events.append([start_time[x], end_time[x], people[x]])

    events.sort()
    result = 0
    prev = events[0]
    for curr in range(1, len(events)):
        currNode = events[curr]
        if prev[1] > currNode[0]:
            result += prev[2]
        prev = currNode
    return result


# Example usage:
people =     [4, 3, 5, 6, 10, 5]
start_time = [1, 2, 3, 6, 5, 4]
end_time =   [1, 2, 5, 7, 7, 7]

print(
    min_people_unable_to_attend(
        people=people,
        start_time=start_time,
        end_time=end_time
    )
)
