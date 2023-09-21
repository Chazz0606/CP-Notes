def x(n, k):
    reverse = 0
    for i in range(n, 1, -1):
        if k > 2 ** (i - 1) / 2:
            k = 2 ** (i - 1) - k + 1
            reverse ^= i % 2 ^ 1
    k -= 1
    k ^= reverse
    return k
