def prod(nums):
    product = 1
    for i in nums:
        product *= i
    return product


def get_product_mod(nums, base):
    return prod(i % base for i in nums) % base


comet_name = input()
comet_name_nums = [ord(i)-64 for i in list(comet_name)]
group_name = input()
group_name_nums = [ord(i)-64 for i in list(group_name)]
if get_product_mod(comet_name_nums, 47) == get_product_mod(group_name_nums, 47):
    print('GO')
else:
    print('STAY')


# import random
# import time
#
#
# def prod(nums):
#     product = 1
#     for i in nums:
#         product *= i
#     return product
#
#
# def first(nums, base):
#     return prod(i % base for i in nums) % base
#
#
# def second(nums, base):
#     return prod(nums) % base
#
#
# for i in range(10):
#     x = [random.randint(10, 100) for _ in range(random.randint(10, 100))]
#     base = random.randint(10, 100)
#     t1 = time.perf_counter()
#     a = first(x, base)
#     ta = time.perf_counter() - t1
#
#     t1 = time.perf_counter()
#     b = second(x, base)
#     tb = time.perf_counter() - t1
#
#     if ta < tb:
#         winner = 'first'
#     elif tb < ta:
#         winner = 'second'
#     else:
#         winner = 'draw'
#     print(winner, ta, tb)
