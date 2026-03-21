def conta_infelizes(x):
    nova_soma = soma + x
    limite = nova_soma

    l = 0
    r = q - 1
    resultado = q

    while l <= r:
        mid = (l + r) // 2
        if array[mid] * 2 * q < limite:
            l = mid + 1
        else:
            resultado = mid
            r = mid - 1
    return resultado

n = int(input())

for _ in range(n):
    q = int(input())
    array = list(map(int, input().split()))
    array.sort()
    soma = sum(array)

    if conta_infelizes(0) > q // 2:
        print(0)
    elif q <= 2:
        print(-1)
    else:

        #descobre o menor x (mid) que deixa a pop infeliz
        l = 1
        r = 10**15
        resposta = -1

        while l <= r:
            mid = (l + r) // 2
            if conta_infelizes(mid) > q // 2:
                resposta = mid
                r = mid - 1
            else:
                l = mid + 1

        print(resposta)
