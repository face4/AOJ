n = int(input())
a = [int(_) for _ in input().split()]
w = [int(_) for _ in input().split()]
r = [w for a, w in zip(a,w) if a == 0]
l = [w for a, w in zip(a,w) if a == 1]

if r and l:
    print(min(r)+min(l))
else:
    print(0)