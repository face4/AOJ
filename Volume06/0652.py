a,b,c=map(int,input().split())
print(c//(7*a+b)*7+(7 if c%(7*a+b)>6*a else (c%(7*a+b)+a-1)//a))