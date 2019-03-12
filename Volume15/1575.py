pos = [[0,0], [1,0]]
way = [[0,1], [0,1]]
ans = 0
w, h = map(int, input().split())
n = int(input())
li = list(map(int, input().split()))
for p in li:
    ni = pos[p][0]+way[p][0]
    nj = pos[p][1]+way[p][1]
    if p == 0:
        if nj >= w or ni >= h:
            way[p][0],way[p][1]=way[p][1],-way[p][0]
            ni = pos[p][0]+way[p][0]
            nj = pos[p][1]+way[p][1]
    else:
        if nj >= w-1 or ni >= h-1:
            way[p][0],way[p][1]=way[p][1],-way[p][0]
            ni = pos[p][0]+way[p][0]
            nj = pos[p][1]+way[p][1]
    pos[p][0] = ni
    pos[p][1] = nj
    if abs(pos[0][0]-pos[1][0])+abs(pos[0][1]-pos[1][1]) == 1:
        ans += 1
print(ans)