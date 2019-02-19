m, n = map(int, input().split())
print(max([sum(list(map(int, input().split()))) for i in range(m)]))
