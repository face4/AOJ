a, b, x = map(int, input().split())
print((x+max(0, x-b)//(a-b)*b)%1000000007)