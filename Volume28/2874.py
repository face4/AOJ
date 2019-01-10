n = int(input())
li = [int(_) for _ in input().split()]
for i in li:
    for j in li:
        if i != j and abs(i-j)%(n-1) == 0:
            print(i,j)
            quit()