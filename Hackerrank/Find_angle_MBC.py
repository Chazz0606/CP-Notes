# Enter your code here. Read input from STDIN. Print output to STDOUT

import math

ab,bc=int(input()),int(input())
theta=math.degrees(math.atan(ab/bc))
theta=math.floor(theta+0.5)
print(str(theta)+"°")