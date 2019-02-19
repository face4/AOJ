n = int(input())
li = list(map(int,input().split()))
li.sort(reverse = True)
ans = acc = 0
for x in li:
    if x%2 == 0:
        ans += x//2
    elif acc != 0:
        ans += (acc+x)//2
        acc = 0
    else:
        acc = x
print(ans)