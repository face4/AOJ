while True:
    a, b = map(int, input().split())
    if(b == 0):
        break
    b -= a
    print(" ".join([str(x) for x in [b%500//100, b%1000//500, b//1000]]))
    