def c(a, b):
    if a < 0 or b < 0:
        return 0
    r = 1
    for i in range(a, a-b, -1):
        r *= i
    for i in range(2, b+1):
        r /= i
    return int(r)


t = list(map(int, input().split()))
b = [t[0], t[1]]
h = [t[2], t[3]]
paths = 0

hx_max = h[0] + 2
hx_min = h[0] - 2
hy_max = h[1] + 2
hy_min = h[1] - 2

for i in range(hy_min):
    paths += c(hx_max+1+i, i) * c((b[1]-i)+(b[0]-hx_max-1), b[0]-hx_max-1)
for i in range(hx_min):
    paths += c(hy_max+1+i, i) * c((b[0]-i)+(b[1]-hy_max-1), b[1]-hy_max-1)

paths += c(hx_max+(hy_min-1), hy_min-1) * c((b[1]-hy_min)+(b[0]-hx_max-1), b[0]-hx_max-1)
paths += c(hy_max+(hx_min-1), hx_min-1) * c((b[0]-hx_min)+(b[1]-hy_max-1), b[1]-hy_max-1)
paths += c(h[0]+(hy_min-1), hy_min-1) * c((b[1]-h[1])+(b[0]-hx_max-1), b[0]-hx_max-1)
paths += c(h[1]+(hx_min-1), hx_min-1) * c((b[0]-h[0])+(b[1]-hy_max-1), b[1]-hy_max-1)

print(paths)
