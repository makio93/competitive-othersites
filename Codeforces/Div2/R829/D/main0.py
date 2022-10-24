# 自力,TLE

n, x = map(int, input().split())
a = list(map(int, input().split()))

a.sort()
xfact = 1

for i in range(1, x+1) :
    xfact *= i

sum = 0
tfact = 1
id = 0
for i in range(n):
    while id < a[i]:
        id += 1
        tfact *= id
    sum += tfact

if sum % xfact == 0:
    print("Yes")
else:
    print("No")

