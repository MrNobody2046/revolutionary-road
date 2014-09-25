# coding:utf-8
a = "rrr"
a = "brbrrrbbbrrrrrbrrbbrbbbbrrrrb"
length = len(a)
"""
最长串的条件：

两边不能有w
中间只能变化一次
"""

def count_distance(start, end, length):
    if start > end:
        return length - start + end + 1
    else:
        return end - start + 1
trunk = a
max_counts = 0
mid = end = cursor = 0
temp = 0
color = ""
start = end = length
fstart = -1
pre_start = -1
sample = ""
for i in range(13):
    color = trunk[start % length]
    print color
    while temp < length:
        temp += 1  # 循环计数器
        start -= 1
        sample = trunk[start % length]
        if sample != color and sample != "w":
            if color == "w":
                color = sample
            else:
                break
    start = (start+1) % length
    while temp < length:
        temp += 1
        end += 1
        sample = trunk[end % length]
        if sample != color and sample != "w":
            break
    end = end % length
    print start,end,temp
    if temp>=length-1:
        max_counts = length
        break
    count = temp - 1

    if pre_start < 0:
        pre_start = end
    else:
        if pre_start != start:
            #修正偏差
            count -= (pre_start - start) % length
        pre_start = end
    if count >max_counts:
        max_counts = count
    start = end
    if start >= fstart:
        print end,fstart
    temp = 0
        # break

print "MAx len",max_counts

def spliting(li, index=0):
    # back serach: 结果是闭合区间
    length = len(li)
    start = index + length
    flag = li[start % length]  # 决定这一段内容是r还是b 初始值可能是wrb中的任意一种
    temp = 0
    while temp < length:
        temp += 1  # 循环计数器
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
    remain = (index + temp + length) % length
    # print "Flag is:%s,Start is:%d，Remain:%d" % (flag,start,remain)
    end = index
    # print "SearchFront,Start from:%d" % index
    temp = 0
    while temp < remain:
        temp += 1
        end += 1
        front = li[end % length]
        if front != flag and front != "w":
            break
    end -= 1
    if end > length:
        end = end % length
    print "Start:%d,End:%d" % (start, end)
    return start, end
#
#

#
# spliting(a, index=1)
# spliting(a, index=3)
# end = 0
# interval = []
# span = 0
# max_count = 0
# fstart = None
# while True:
#     start, end = spliting(a, index=end+1)
#     if not fstart:
#         fstart = start
#         print fstart
#     if len(interval) == 0:
#         interval.append((start, end ))
#     elif len(interval) == 1:
#         interval.append((start, end ))
#     else:
#         interval[0] = interval[1]
#         interval[1] = (start, end )
#     if len(interval) == 1:
#         count = count_distance(interval[0][0], interval[0][1], l)
#         if count > max_count:
#             max_count = count
#     if len(interval) == 2:
#         count = count_distance(interval[0][0], interval[1][1], l)
#         if count > max_count:
#             max_count = count
#     if end == fstart:
#         break
# print max_count
# start,end = spliting(a)
# fend = end
# count = []
# while True:
# start,end = spliting(a,index=end+1)
#     distance = count_distance(start,end,29)
#     count.append(distance)
#     if fend - end == 0:
#         break
# print count
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
