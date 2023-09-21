n = int(input())
names = []
change = {}
for _ in range(n):
    name = input()
    names.append(name)
    change[name] = 0

for i in range(n):
    name = input()
    money, g = list(map(int, input().split()))
    if money == 0 or g == 0:
        continue
    each_money = money // g
    change[name] -= each_money * g
    for j in range(g):
        receiver = input()
        change[receiver] += each_money

for name in names:
    print(name + chr(32) + str(change[name]))
