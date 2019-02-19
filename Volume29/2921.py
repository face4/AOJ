n = int(input())
li = list(map(int, input().split()))
ans = 1000
s = 0
for i in range(n):
    s += li[i]
    ans = min(ans, s//(i+1))
print(ans)