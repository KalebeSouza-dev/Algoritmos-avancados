t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    #  A ajisai impar // B mai par // Tie empate
    
    outstr = ""
 
    for k in range(20, -1, -1):
        out = 0
        c1= -1

        mask = 1 << k
        for i in range(n):
            x = ((a[i] & mask) > 0) ^ ((b[i] & mask) > 0)
            out ^= x
            if x == 1:
                c1 = i + 1

        if out == 0:
            continue

        if c1 % 2 == 1:
            outstr = "Ajisai"
        else:
            outstr = "Mai"
        break

    if outstr == "":
        print("Tie")
    else:
        print(outstr)