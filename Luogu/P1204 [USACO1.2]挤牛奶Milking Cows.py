import math


n = int(input())
periods = [[-1, -1], [math.inf, math.inf]]
for i in range(n):
    l, r = map(int, input().split())
    start_val = 0
    start = 0
    for j in range(1, len(periods)):
        start = j
        if periods[j][0] <= l <= periods[j][1]:
            start_val = periods[start][0]
            break
        elif periods[j-1][1] < l < periods[j][0]:
            start_val = l
            break

    end_val = 0
    end = start
    for j in range(len(periods)):
        end = j
        if periods[j][0] <= r <= periods[j][1]:
            end_val = periods[end][1]
            break
        elif j != len(periods) - 1 and periods[j][1] < r < periods[j + 1][0]:
            end_val = r
            break

    periods = periods[:start]+[[start_val, end_val]]+periods[end+1:]

milking_length = [0]
stopping_length = [0]
for i in range(1, len(periods)-1):
    milking_length.append(periods[i][1]-periods[i][0])
    if i < len(periods)-2:
        stopping_length.append(periods[i+1][0]-periods[i][1])

print(max(milking_length), max(stopping_length))
