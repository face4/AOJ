n = int(input())
li = input().split()
bef = li[0]
for i in range(1, n):
    bef = "F" if bef == "T" and li[i] == "F" else "T"
print(bef)
