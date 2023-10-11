nums = list(range(1, 10))
for a in range(3):
    a = nums[a]
    nums.remove(a)
    temp_a = nums.copy()
    for b in range(8):
        b = nums[b]
        nums.remove(b)
        temp_b = nums.copy()

        for c in range(7):
            flag = True
            c = nums[c]
            nums.remove(c)
            x = 100 * a + 10 * b + c
            for i in str(2 * x):
                if int(i) in nums and flag:
                    nums.remove(int(i))
                else:
                    flag = False
                    break

            for i in str(3 * x):
                if int(i) in nums and flag:
                    nums.remove(int(i))
                else:
                    flag = False
                    break
            if flag:
                print(x, 2 * x, 3 * x)
            nums = temp_b.copy()

        nums = temp_a.copy()

    nums = list(range(1, 10))
