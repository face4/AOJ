#coding on smartphon
n,m=map(int,input().split())
print(m-len(list(filter(lambda x:x<=m,[int(x) for x in input().split()]))))
