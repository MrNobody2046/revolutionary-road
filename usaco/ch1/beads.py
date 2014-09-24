# coding:utf-8
a = "rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr"

l = len(a)
"""
最长串的条件：

两边不能有w
中间只能变化一次
"""


def spliting(li, index=0):
    # back serach: 结果是闭合区间
    length = len(li)
    start = index + length
    flag = li[start % length] # 决定这一段内容是r还是b 初始值可能是wrb中的任意一种
    j = 0
    while j < length:
        j -= 1 # 循环计数器
        start -= 1
        back = li[start % length]
        if back != flag and back != "w":
            if flag == "w":
                flag = back
            else:
                break
    start = start + 1
    if start > length:
        start = start % length
    remain = (index + j + length) % length
    # print "Flag is:%s,Start is:%d，Remain:%d" % (flag,start,remain)
    end = index
    # print "SearchFront,Start from:%d" % index
    while j < remain:
        j += 1
        end += 1
        front = li[end % length]
        if front != flag and front != "w":
            break
    end -= 1
    if end > length:
        end = end % length
    print "Start:%d,End:%d" % (start,end)
    return start, end

def count_distance(start,end,length):
    if start > end:
        return length - start + end + 1
    else:
        return end - start + 1

start,end = spliting(a)
fend = end
count = []
while True:
    start,end = spliting(a,index=end+1)
    distance = count_distance(start,end,29)
    count.append(distance)
    if fend - end == 0:
        break
print count
# start = 0
# for i,v in enumerate(a):
# _n = a[(i+1)%l]
#     if v != "w" and _n != "w" and v != _n:
#         start = i + 1
#         break
# print start
#
# i = start
# count = 1
# counts = []
# cur = a[i]
# reverted = 0
#
# for _ in a:
#     _n = a[(i+1)%l]
#     if _n == cur or _n == "w":
#         count += 1
#     else:
#         counts.append(count)
#         if a[i%l] == "w":
#             count = 2
#         else:
#             count = 1
#         cur = _n
#     i += 1
#     # print "Cur,",cur,"N",_n,"count",count,"I",i
# print counts
#
# start = 0
# max_size = 0
# l = len(counts)
# for _ in counts:
#     s = counts[start%l] + counts[(start+1)%l]
#     start += 1
#     if s > max_size:
#         max_size = s
# print max_size
