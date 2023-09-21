def get_path(c):
    p = 0
    if c == h or abs(c[0]-h[0])+abs(c[1]-h[1]) == 3 and abs(abs(c[0]-h[0])-abs(c[1]-h[1])) == 1:
        return 0
    if c == b:
        return 1
    if c[0]+1 <= b[0]:
        p += get_path([c[0]+1, c[1]])
    if c[1]+1 <= b[1]:
        p += get_path([c[0], c[1]+1])
    return p


t = list(map(int, input().split()))
b = [t[0], t[1]]
h = [t[2], t[3]]
print(get_path([0, 0]))
