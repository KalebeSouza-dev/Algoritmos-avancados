import sys

n, q = map(int, sys.stdin.readline().split())
array = list(map(int, sys.stdin.readline().split()))

for i in range(q):
    k = int(sys.stdin.readline())
    left = 0
    right = n - 1
    resultado = -1
    
    while left <= right:
        mid = (left + right) // 2
        if array[mid] == k:
            resultado = mid
            right = mid - 1
        elif array[mid] < k:
            left = mid + 1
        else:
            right = mid - 1
    sys.stdout.write(str(resultado) + '\n')
