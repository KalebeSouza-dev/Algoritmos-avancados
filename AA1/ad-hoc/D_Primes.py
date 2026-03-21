n = int(input())
x = n - 2

if x <= 1:
    print('-1')
else:
    eh = False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            eh = True
            print("-1")
            break

    if not eh:
        print(f"2 {x}")
