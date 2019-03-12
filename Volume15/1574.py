n, m = map(int, input().split())
li = list(map(int, input().split()))
print(max(li[0]-1, n-li[-1], *[(li[i]-li[i-1])//2 for i in range(1,m)]))