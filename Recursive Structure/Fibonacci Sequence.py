# Recursive Version -> Not Recommend
def fibo_Recur_Seq(n):
    if n==1 or n==2:
        return 1
    else:
        return fibo_Recur_Seq(n-1) + fibo_Recur_Seq(n-2)

# Non-Recursive Version -> Recommend
def fibo_NonRecur_Seq(n):
    f =[]
    f.insert(0, 1)
    f.insert(1, 1)
    for i in range(2, n+1):
        f.append(f[i-1] + f[i-2])
    return f[n]