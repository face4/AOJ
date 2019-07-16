n=int(input())
a,b=map(int,input().split())
c,d=map(int,input().split())
a-=1;b-=1;c-=1;d-=1
def f(x, y, z):
    return abs(x//(z+1)-y//(z+1))+abs(x%(z+1)-y%(z+1))
print(min([f(a,b,i+1)+f(c,d,i+1) for i in range(n)]))