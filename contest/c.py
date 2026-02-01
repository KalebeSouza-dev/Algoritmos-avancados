t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    #  A ajisai impar // B mai par // Tie empate

    out = 0
    c1 = -1
    for i in range(n):
        x = a[i] ^ b[i]
        out ^= x
        if x == 1:
            c1 = i + 1
            
    if out == 0:
        print("Tie")
    else:
        if c1 % 2 == 1:
            print("Ajisai")
        else:
            print("Mai")