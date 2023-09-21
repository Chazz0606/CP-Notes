n = int(input())
cnt = [0] * 7
current_day = 5

for year in range(1900, 1900 + n):
    month_day_cnt = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if year % 4 == 0 and not year % 100 == 0 or year % 400 == 0:
        month_day_cnt[1] = 29
    for month in range(12):
        cnt[current_day] += 1
        current_day = (current_day + month_day_cnt[month]) % 7

print(' '.join(map(str, cnt[5:]+cnt[:5])))
