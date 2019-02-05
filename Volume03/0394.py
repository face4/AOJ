import math
n, k = map(int, input().split())
ret = 1
acc = 1
while True:
    want = math.ceil(acc / k)
    if(want+acc > n):
        break
    acc += want
    ret += 1
print(ret)