n, t = map(int, input().split())
def f(i, j):
    return 60*j[0]+j[1]-60*i[0]-i[1]
res = []
tmp = input().split()
name, bef = tmp[3], list(map(int, tmp[2].split(":")))
for i in range(n-1):
    tmp = input().split()
    aft = list(map(int, tmp[0].split(":")))
    tim = f(bef, aft)
    if tim >= t : res.append([name, str(tim)])
    name, bef = tmp[3], list(map(int, tmp[2].split(":")))
print(len(res))
if len(res) != 0 : print("\n".join([" ".join(x) for x in res]))