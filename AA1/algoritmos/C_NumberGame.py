n = int(input())

for _ in range(n):
    k = int(input())
    array = [int(i) for i in input().split()]
    for i in range(k, -1, -1):
        a = sorted(array)
        for x in range(i, 0, -1):
            #thais
            passou = True
            for j in range(len(a)-1,-1,-1):
                a.sort()
                if a[j] <= x:
                    passou = False
                    a.pop(j)
                    #davi
                    if a:
                        a.sort()
                        a[0] += x                            
                    break
            if passou: break
        if(len(a) == k-i):
            print(i)
            break
        