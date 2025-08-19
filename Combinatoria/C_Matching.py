t = int(input())
for _ in range(t):
    n = input()
    if n[0] == '0':
        print(0)
        continue
    mult = 1
    for i in range(len(n)):
        if i == 0 and n[0] == "?":
            mult *= 9
        elif n[i] == "?":
            mult *= 10
    print(mult)