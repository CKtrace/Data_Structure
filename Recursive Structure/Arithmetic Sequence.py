def ari_seq(n):
    if n==1:
        return 1
    else:
        return ari_seq(n-1) + 5