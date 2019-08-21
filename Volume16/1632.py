while True:
    n, m = map(int, input().split())
    if n+m==0 : break
    a = [list(map(int,input().split())) for i in range(m)]
    for i in range(1, m):
        for j in range(n):
            a[i][j] += a[i-1][j]
    print(max(a[m-1]))