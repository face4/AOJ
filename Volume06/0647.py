n, k = map(int, input().split())
li = [int(input()) for i in range(n)]
diff = []
for j in range(n-1):
    diff.append(li[j+1]-li[j]-1)
diff.sort(reverse=True)
print(n+sum(diff[k-1:]))
