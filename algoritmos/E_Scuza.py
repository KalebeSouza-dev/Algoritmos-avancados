def busca_binaria(array, k):
    left, right = 0, len(array) - 1
    resposta = -1
    while left <= right:
        mid = (left + right) // 2
        if array[mid] <= k:
            resposta = mid
            left = mid + 1
        else:
            right = mid - 1
    return resposta

q = int(input())

for _ in range(q):
    n, q = map(int, input().split())
    h = list(map(int, input().split()))  # alturas
    questions = list(map(int, input().split()))  # pernas

    soma = h[0]
    somaAcumulada = [0] * n
    somaAcumulada[0] = soma

    max_h = [0] * n
    max_h[0] = h[0]
    # no msm loop crio a soma acumulada, e ordeno h, comparando i com i++ para realizar busca binaria
    for i in range(1, n):
        soma += h[i]
        somaAcumulada[i] = soma

        max_h[i] = max(max_h[i - 1], h[i])

    result = []
    for k in questions:
        b = busca_binaria(max_h, k)
        if b == -1:
            result.append("0")
        else:
            result.append(str(somaAcumulada[b]))

    print(' '.join(result))
