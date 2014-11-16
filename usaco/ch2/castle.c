/*
 ID:sphy1
 LANG: C
 TASK: castle
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT "castle.in"
#define OUTPUT "castle.out"

typedef struct Room {
    int size;
    int idx;
} Room;

int M, N;
int walls[51][51] = { 0 };
int cells[51][51] = { 0 };

int room_idx = 1;
Room rooms[2500];
Room big = { 0, 0 };
int ret[3] = { 0 };

/*
setup 1:
walking cells get rooms
index each room then record in a two-dimensional array cells;
the data in cells looks like
11122
11122
13122
33332
33332
the number is the number of room.
setup 2:
try to break walls from west-south to east-north
record the answer
pay attention to the search direction
carefully judge whether there is wall on specified direction

*/

int not_has_wall(int num, int bit_idx) {
    // return 1 if bit of binary number is 0
    // return in specified direction not has wall
    return !((num >> bit_idx) % 2);
}

int has_wall(int num, int bit_idx) {
    return (num >> bit_idx) % 2;
}

int walk(int w, int x, int y) {
    if (not_has_wall(w, 0)) {
        wandering(x, y - 1); // xxx0 walk to west
    }
    if (not_has_wall(w, 1)) {
        wandering(x - 1, y); // xx0x walk to north
    }
    if (not_has_wall(w, 2)) {
        wandering(x, y + 1);  // x0xx walk to east
    }
    if (not_has_wall(w, 3)) {
        wandering(x + 1, y); // 0xxx walk to south
    }

}

int wandering(int x, int y) {
    if (x < 0 || y < 0) {
        printf("xx");
        return -1;
    }
    if (cells[x][y] > 0) {
        // already detected
        return 0;
    } else {
//        printf("In  :%d,%d \n", x, y);
        cells[x][y] = room_idx;
        rooms[room_idx].size++;
        int w = walls[x][y];
        walk(w, x, y);

        return 0;
    }
}

int print_cells() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d", cells[i][j]);
        }
        printf("\n");
    }
}

int try_remove_wall(int x, int y) {
    int w = walls[x][y];
    int sum;
    char direction;
    // east , south
    Room r = rooms[cells[x][y]];
    Room next;
    if (has_wall(w, 1) && x > 1) {
        next = rooms[cells[x - 1][y]];
        direction = 'N';
        if (r.idx != next.idx) {
            sum = r.size + next.size;
            if (sum > big.size) {
                big.size = sum;
                ret[0] = x, ret[1] = y;
                ret[2] = direction;
            }
        }
    }
    if (has_wall(w, 2) && y < M - 1) {
        next = rooms[cells[x][y + 1]];
        direction = 'E';
        if (r.idx != next.idx) {
            sum = r.size + next.size;
            if (sum > big.size) {
                big.size = sum;
                ret[0] = x, ret[1] = y;
                ret[2] = direction;
            }
        }
    }
}

int main() {
    freopen(INPUT, "r", stdin);
    freopen(OUTPUT, "w", stdout);

    scanf("%d %d", &M, &N);
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &walls[i][j]);
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (cells[i][j] == 0) {
                rooms[room_idx].idx = room_idx;
                rooms[room_idx].size = 0;
                wandering(i, j);
                room_idx++;
            }
        }
    }
    for (j = 0; j < M; j++) {
        for (i = N - 1; i >= 0; i--) {
            try_remove_wall(i, j);
        }
    }
    int max_room_size = 0;
    for (i = 1; i < room_idx; i++) {
        if (rooms[i].size >= max_room_size) {
            max_room_size = rooms[i].size;
        }
    }
    printf("%d\n\%d\n%d\n", room_idx - 1, max_room_size, big.size);
    printf("%d %d %c\n", ret[0] + 1, ret[1] + 1, ret[2]);
    exit(0);
}
