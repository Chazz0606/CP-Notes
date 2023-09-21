def cnt_add(cnt, val):
    if val in cnt:
        cnt[val] += 1
    else:
        cnt[val] = 1
    return cnt


a = [list(input()) for _ in range(3)]
b = [list(input()) for _ in range(3)]
green_cnt = 0
yellow_cnt = 0
a_cnt = {}
b_cnt = {}

for i in range(3):
    for j in range(3):
        if a[i][j] == b[i][j]:
            green_cnt += 1
        else:
            a_cnt = cnt_add(a_cnt, a[i][j])
            b_cnt = cnt_add(b_cnt, b[i][j])
for i in b_cnt:
    if i in a_cnt:
        yellow_cnt += min(a_cnt[i], b_cnt[i])
print(green_cnt)
print(yellow_cnt)
