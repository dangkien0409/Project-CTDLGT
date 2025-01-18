#include <stdio.h>

#define MAX 100

// Cấu trúc để biểu diễn cạnh
typedef struct {
    int dinh1, dinh2, trongso;
} Canh;

Canh danhsachcanh[MAX];
int cha[MAX];
int bac[MAX];
int sodinh, socanh;

// Tìm gốc của tập hợp chứa đỉnh x
int timgoc(int x) {
    if (cha[x] != x) {
        cha[x] = timgoc(cha[x]);
    }
    return cha[x];
}

// Hợp nhất hai tập hợp chứa x và y
void hopnhat(int x, int y) {
    int gocX = timgoc(x);
    int gocY = timgoc(y);

    if (bac[gocX] < bac[gocY]) {
        cha[gocX] = gocY;
    } else if (bac[gocX] > bac[gocY]) {
        cha[gocY] = gocX;
    } else {
        cha[gocY] = gocX;
        bac[gocX]++;
    }
}

// Sắp xếp các cạnh theo trọng số tăng dần
void sapxepcanh() {
    for (int i = 0; i < socanh - 1; i++) {
        for (int j = i + 1; j < socanh; j++) {
            if (danhsachcanh[i].trongso > danhsachcanh[j].trongso) {
                Canh temp = danhsachcanh[i];
                danhsachcanh[i] = danhsachcanh[j];
                danhsachcanh[j] = temp;
            }
        }
    }
}

// Thuật toán Kruskal
void kruskal() {
    Canh caykhung[MAX];
    int socanhcaykhung = 0;

    sapxepcanh();

    for (int i = 0; i < sodinh; i++) {
        cha[i] = i;
        bac[i] = 0;
    }

    for (int i = 0; i < socanh && socanhcaykhung < sodinh - 1; i++) {
        int u = danhsachcanh[i].dinh1;
        int v = danhsachcanh[i].dinh2;

        if (timgoc(u) != timgoc(v)) {
            caykhung[socanhcaykhung++] = danhsachcanh[i];
            hopnhat(u, v);
        }
    }

    printf("Cac canh trong cay khung nho nhat:\n");
    for (int i = 0; i < socanhcaykhung; i++) {
        printf("%d -- %d == %d\n", caykhung[i].dinh1, caykhung[i].dinh2, caykhung[i].trongso);
    }
}

int main() {
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &sodinh, &socanh);

    printf("Nhap cac canh (dinh1 dinh2 trongso):\n");
    for (int i = 0; i < socanh; i++) {
        scanf("%d %d %d", &danhsachcanh[i].dinh1, &danhsachcanh[i].dinh2, &danhsachcanh[i].trongso);
    }

    kruskal();

    return 0;
}