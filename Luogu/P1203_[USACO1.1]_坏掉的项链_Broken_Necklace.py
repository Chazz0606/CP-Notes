n = int(input())
beads = input()

lengths = []
bead_groups = []

group = [beads[0], 0]
for bead in beads:
    if bead == group[0]:
        group[1] += 1
    else:
        bead_groups.append(group)
        group = [bead, 1]
bead_groups.append(group)

i = 0
while i < len(bead_groups):
    if i != 0 and bead_groups[i][0] == 'w' and bead_groups[i-1][0] == bead_groups[i+1][0]:
        bead_groups[i-1][1] += bead_groups[i][1] + bead_groups[i+1][1]
        del bead_groups[i+1]
        del bead_groups[i]
    else:
        i += 1

a = 0
if len(bead_groups) > 1 and bead_groups[a][0] == 'w':
    color1 = bead_groups[1][0]
    b = 1
else:
    color1 = bead_groups[0][0]
    b = 0

while b < len(bead_groups)-1:
    b += 1
    lengths.append(sum([group[1] for group in bead_groups[a:b]]))
    while bead_groups[b][0] == color1:
        a += 1
        if bead_groups[a] == 'w':
            color1 = bead_groups[a+1][0]
        else:
            color1 = bead_groups[a][0]

if

print(max(lengths))
