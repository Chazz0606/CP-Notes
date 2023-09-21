num = input()
num_name = {
    '2': ['A', 'B', 'C'], '3': ['D', 'E', 'F'], '4': ['G', 'H', 'I'],
    '5': ['J', 'K', 'L'], '6': ['M', 'N', 'O'], '7': ['P', 'R', 'S'],
    '8': ['T', 'U', 'V'], '9': ['W', 'X', 'Y']
}
acceptable_names = []
for _ in range(4617):
    acceptable_names.append(input())

new_acceptable_names = []
for i in range(len(acceptable_names)):
    if len(acceptable_names[i]) == len(num):
        new_acceptable_names.append(acceptable_names[i])
acceptable_names = new_acceptable_names.copy()
new_acceptable_names = []

for i in range(len(num)):
    for j in range(len(acceptable_names)):
        if acceptable_names[j][i] in num_name[num[i]]:
            new_acceptable_names.append(acceptable_names[j])
    acceptable_names = new_acceptable_names.copy()
    new_acceptable_names = []

if len(acceptable_names) == 0:
    print('NONE')
else:
    for name in acceptable_names:
        print(name)
