# 말 점수 정의
score_table = {
    'q': 9, 'r': 5, 'b': 3, 'n': 3, 'p': 1,
    'k': 0
}

white_score = 0
black_score = 0

for _ in range(8):
    line = input()
    for ch in line:
        if ch == '.':
            continue
        ch_lower = ch.lower()
        if ch_lower not in score_table:
            continue
        if ch.isupper():
            black_score += score_table[ch_lower]
        else:
            white_score += score_table[ch_lower]

if white_score > black_score:
    print("White")
elif black_score > white_score:
    print("Black")
else:
    print("Draw")