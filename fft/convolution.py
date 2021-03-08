# cook your dish here
# O(n^2) polynomial multiplication

def conv(A,B):
    m=len(A)
    n=len(B)
    C=[0]*(n+m-1)
    for i in range(m):
        for j in range(n):
            C[i+j]+=(A[i]*B[j])
    return C
t=int(input())
for tt in range(t):
    n=int(input())
    A=[int(i) for i in input().split()]
    B=[int(i) for i in input().split()]
    C=conv(A,B)
    for x in C:
        print(x,end=' ')
    print("")
    
