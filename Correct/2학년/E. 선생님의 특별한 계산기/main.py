import sys
input = sys.stdin.readline

Q = int(input())
stack = []
result = 0

for _ in range(Q):
    query = input().strip().split()
    
    if query[0] == '1':
        x = int(query[1])
        result += x
        stack.append(('add', x))
    elif query[0] == '2':
        x = int(query[1])
        result -= x
        stack.append(('sub', x))
    elif query[0] == '3':
        j = int(query[1])
        for _ in range(j):
            op, x = stack.pop()
            if op == 'add':
                result -= x
            else:
                result += x
    elif query[0] == '4':
        print(result)
    elif query[0] == '5':
        print(len(stack))