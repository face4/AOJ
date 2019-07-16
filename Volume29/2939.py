q = int(input())
li = [input().split() for i in range(q)]
for i in li:
    a, b, c, d = map(int, i)
    ans = 0
    for j in range(a, c+1):
        for k in range(b, d+1):
            ans += 0 if j%2 == 1 and k%2 == 0 else 1
    print(ans)
