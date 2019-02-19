a,b,c,d=map(int,input().split())
print("No" if ((a*b)%2)*((c+d)%2)==1 else "Yes")