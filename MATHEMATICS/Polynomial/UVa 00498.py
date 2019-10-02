while True:
    try:
        coeffs = list(map(int,input().strip().split()))
        xs = list(map(int,input().strip().split()))

        for x in range(len(xs)):
            ans = 0
            n = len(coeffs)
            for i in range(n):
                ans += pow(xs[x],i) * coeffs[n-i-1]
            if x!=len(xs)-1:
                print(ans,end=' ')
            else:
                print(ans)
    except:
        break
