#coding:utf-8

CANDICATES= range(5)
RET = [None for i in range(10)]
BUFIDX = 0
CNT = 0
def print_and_cnt(li):
    global CNT
    CNT += 1
    print li,CNT

def rog(array, length, selected, callback=print_and_cnt):
    global BUFIDX
    # print RET
    if length < selected:
        return
    if selected <= 0:
        callback(RET)
        return
    for i in range(length):
        RET[BUFIDX] = array[i]
        # print BUFIDX,array, length, selected -1
        BUFIDX += 1
        rog(array, length, selected -1)
        BUFIDX -= 1

def rog2(array, length, selected, callback=print_and_cnt):
    global BUFIDX
    # print RET
    if length < selected:
        return
    if selected <= 0:
        callback(RET)
        return
    for i in range(length):
        RET[BUFIDX] = array[i]
        # print BUFIDX,array, length, selected -1
        BUFIDX += 1
        rog2(array[i+1:], length-i-1, selected -1)
        BUFIDX -= 1


rog2((1,2,3), 3, 1)
