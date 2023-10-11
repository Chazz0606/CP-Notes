class System:
    def __init__(self, win_score):
        self.win = 0
        self.lose = 0
        self.record = []
        self.win_score = win_score

    def check_win(self):
        if (self.win >= self.win_score and self.win - self.lose >= 2) \
                or (self.lose >= self.win_score and self.lose - self.win >= 2):
            self.record.append([self.win, self.lose])
            self.win = self.lose = 0


s11 = System(11)
s21 = System(21)
end = False
while not end:
    t = input()
    for res in t:
        if res == 'W':
            s11.win += 1
            s21.win += 1
        elif res == 'L':
            s11.lose += 1
            s21.lose += 1
        else:
            end = True
            break
        s11.check_win()
        s21.check_win()

    if end:
        break

for r in s11.record:
    print(f'{r[0]}:{r[1]}')
print(f'{s11.win}:{s11.lose}')

print('')

for r in s21.record:
    print(f'{r[0]}:{r[1]}')
print(f'{s21.win}:{s21.lose}')
