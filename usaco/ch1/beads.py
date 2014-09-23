# coding:utf-8
a = "wwwbbrwrbrbrrbrbrwrwwrbwrwrrb"

l = len(a)

"""
最长串的条件：

两边不能有w
中间只能变化一次
"""



start = 0
for i,v in enumerate(a):
    _n = a[(i+1)%l]
    if v != "w" and _n != "w" and v != _n:
        start = i + 1
        break
print start

i = start
count = 1
counts = []
cur = a[i]
reverted = 0

for _ in a:
    _n = a[(i+1)%l]
    if _n == cur or _n == "w":
        count += 1
    else:
        counts.append(count)
        if a[i%l] == "w":
            count = 2
        else:
            count = 1
        cur = _n
    i += 1
    # print "Cur,",cur,"N",_n,"count",count,"I",i
print counts

start = 0
max_size = 0
l = len(counts)
for _ in counts:
    s = counts[start%l] + counts[(start+1)%l]
    start += 1
    if s > max_size:
        max_size = s
print max_size
