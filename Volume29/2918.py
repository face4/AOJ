n = input()
print(len(list(filter(lambda x:x%2==0, map(int,input().split())))))