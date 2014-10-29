/*
ID:sphy1
LANG: C
TASK: packrec
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "packrec.in"
#define OUTPUT "packrec.out"

typedef struct {
    int x;
    int y;
} Rect;

Rect rotate(Rect r){
    Rect ret;
    ret.x = r.y;
    ret.y = r.x;
    return ret;
}

int sum_x(Rect rs[],int i){
    int j, sum=0;
    for(j=0;j<i;j++){
        sum += rs[j].x;
    }
    return sum;
}

int sum_y(Rect rs[],int i){
    int j, sum=0;
    for(j=0;j<i;j++){
        sum += rs[j].y;
    }
    return sum;
}

int max_x(Rect rs[],int i){
    int j, max=0;
    for(j=0;j<i;j++){
        if(max<rs[j].x)
            max = rs[j].x;
    }
    return max;
}

int max_y(Rect rs[],int i){
    int j, max=0;
    for(j=0;j<i;j++){
        if(max<rs[j].y)
            max = rs[j].y;
    }
    return max;
}

int num2li2int(int a,int b, int c, int d, int type){
    int ret[4];
    ret[0] = a, ret[1] = b, ret[2] = c, ret[3] = d;
    switch(type){
        case 0:return max(ret);
        case 1:return sum(ret);
    }
}

int max(int li[]){
    int i, max=0, size=4;
    for(i=0;i<size;i++){
        if(max<li[i])
            max = li[i];
    }
    return max;
}

int sum(int li[]){
    int i, sum=0, size=4;
    for(i=0;i<size;i++){
        sum += li[i];
    }
    return sum;
}

Rect case5(Rect rs[]){
    int x, y, crack_y, crack_x;
    Rect ret;
    x = rs[0].x + rs[1].x;
    y = num2li2int(rs[0].y, rs[1].y, 0, 0, 0) + rs[2].y;
    int min_y=rs[0].y;
    if(min_y > rs[1].y){
        min_y = rs[1].y;
    }
    crack_y = y - min_y;
}

Rect packing(Rect rs[], int type){
    // line
    Rect ret;
    switch(type){
        case 0:
        ret.x = sum_x(rs, 4);
        ret.y= max_y(rs, 4);
        break;
        case 1:
        ret.x = num2li2int(sum_x(rs, 3), rs[3].x, 0, 0, 0);
        ret.y = num2li2int(max_y(rs, 3), rs[3].y, 0, 0, 1);
        break;
        case 2:
        ret.x = num2li2int(sum_x(rs, 2), rs[2].x, 0, 0, 0) + rs[3].x;
        ret.y = num2li2int(num2li2int(max_y(rs, 2),rs[2].y, 0, 0, 1), rs[3].y, 0, 0, 0);
        break;
        case 3:
        ret.x = num2li2int(max_x(rs, 2), rs[2].x, rs[3].x, 0, 1);
        ret.y = num2li2int(rs[0].y+rs[1].y, rs[2].y, rs[3].y, 0, 0);
        break;
        case 4:
        ret.x = num2li2int(max_x(rs, 2), rs[2].x, rs[3].x, 0, 1);
        ret.y = num2li2int(rs[0].y+rs[1].y, rs[2].y, rs[3].y, 0, 0);
        break;
    }
    return ret;
}



void print_rect(Rect r){
    printf("Rect(%d,%d),size:%d\n",r.x,r.y,r.x*r.y);
}

int main(){
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);
    int i;
    Rect rects[4];
    for(i=0;i<4;i++){
        scanf("%d %d",&rects[i].x,&rects[i].y);
//        print_rect(rects[i]);
    }
    for(i=0;i<4;i++){
        print_rect(packing(rects,i));
    }
    exit(0);
}
