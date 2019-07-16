while(True):
    n = int(input())
    if n == 0 : exit()
    b = list(map(int, input().split()))
    even, odd = b[:n], b[n:]
    sq = even[0]*even[1]//odd[0]
    l, r = 1, 2**32
    while r-l > 1:
        mid = (l+r)//2
        if mid*mid <= sq : l = mid
        else             : r = mid
    print(l)
    print(" ".join(map(str, sorted([x//l for x in even]))))