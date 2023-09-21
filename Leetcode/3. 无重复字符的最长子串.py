s = input()
max_len = 0
current_string = ''
for i in range(len(s)):
    for j in range(len(current_string)):
        if s[i] == current_string[j]:
            max_len = max(max_len, len(current_string))
            current_string = current_string[j+1:]
            break
    current_string = current_string + s[i]
max_len = max(max_len, len(current_string))
print(max_len)
