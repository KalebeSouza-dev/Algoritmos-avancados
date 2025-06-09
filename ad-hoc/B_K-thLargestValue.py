n , q = map(int, input().split())
array = list(map(int, input().split()))
q_um = sum(array)

for i in range(q):
    t, idx = map(int, input().split())
    if t == 1:
        if array[idx - 1] == 1:
            array[idx - 1] = 0
            q_um -= 1
        else:
            array[idx - 1] = 1
            q_um += 1
    else:
        if idx <= q_um:
            print(1)
        else: 
            print(0)
