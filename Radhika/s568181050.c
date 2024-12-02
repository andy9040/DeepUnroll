#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100005
#define PI acosl(-1) //3.14159265358979323846264338327950L 
#define rep(i, N) for (i = 0; i < N; i++) //制御変数iを用いてN回転
#define array(N, t) (t*)calloc(N, sizeof(t)) //t型N要素の1次元配列を動的確保後0クリア(freeを忘れずに)
#define zero(a); {int iter; rep(iter, sizeof(a)/sizeof((a)[0])) (a)[iter]=0;} //1次元配列aのゼロ初期化?

typedef long long ll; typedef long double ld;
typedef struct node { int data; struct node *next; } Node;

Node *list[SIZE];
int queue[SIZE]; int q_head = 0, q_tail = 0;

void print_log(); //とりあえず文字を出力してどこまで実行できているか確認(for debug)
void printa_int(int *a, int size); //int型の1次元配列aを出力(for debug)
void printl_int(int size); //リンクリストを出力(for debug)
Node* add_node(int i, int data); void free_list(Node* head);
int queue_empty(); int queue_full();
void enqueue(int data); int dequeue();
ll* factorize(ll N); //Nを素因数分解、得られる配列は素因数,指数,素因数,…となっている(添字はintで指定する必要あり?)
void check_factorization(ll *fact); //素因数分解を表示(for debug)

int N;

int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int search(int *p, int x, int h, int t) {
    int i, d = 1, m = (h + t) / 2;
    if (p[h] == x) m = h;
    if (p[t] == x) m = t;
    if (p[m] == x) {
        for (i = 1;; i++) {
            if (i <= m) {
                if (p[m - i] != x - i) {
                    return x - i;
                }
            } else {
                return p[0] - 1;
            }
            if (i < N - m) {
                if (p[m + i] != x + i) {
                    return x + i;
                }
            } else {
                return p[N - 1] + 1;
            }
        }
    } else if (t > h) {
        return x;
    } else {
        int low = search(p, x, h, m);
        int high = search(p, x, m, t);
        if (low == high) return x;
        if (low != x) return low;
        return high;
    }
}

int main() {
    int i, X;
    scanf("%d %d", &X, &N);
    if (!N) {
        printf("%d\n", X);
        return 0;
    }
    int *p = array(N, int);
    rep(i, N) {
        scanf("%d", p + i);
    }
    qsort(p, N, sizeof(int), comp);
    printf("%d\n", search(p, X, 0, N - 1));
    return 0;
}

void print_log() {
    printf("=== print log ===\n");
}
void printa_int(int *a, int size) {
    int i;
    printf("[");
    for (i = 0; i < size; i++)
        printf("%d, ", a[i]);
    printf("]\n");
}
void printl_int(int size) {
    int i;
    Node *t;
    rep(i, size) {
        printf("[%d] ", i);
        for (t = list[i]; t; t = t->next) printf("%d, ", t->data);
        printf("\n");
    }
}
Node* add_node(int i, int data) {
    if (!list[i]) {
        list[i] = (Node*)malloc(sizeof(Node*));
        list[i]->data = data;
    } else {
        Node *t;
        t = list[i];
        list[i] = (Node*)malloc(sizeof(Node*));
        list[i]->data = data;
        list[i]->next = t;
    }
    return list[i];
}
void free_list(Node* head) {
    Node *prev = NULL, *t = head;
    while (t) {
        prev = t;
        t = t->next;
        free(prev);
    }
}
int queue_empty() {
    return q_head == q_tail;
}
int queue_full() {
    return (q_head - 1) % SIZE == q_tail % SIZE;
}
void enqueue(int data) {
    if (queue_full()) {
        printf("full!\n");
        return;
    }
    queue[q_tail++] = data;
    q_tail %= SIZE;
}
int dequeue() {
    if (queue_empty()) {
        printf("empty!\n");
        return -444444;
    }
    int data = queue[q_head++];
    q_head %= SIZE;
    return data;
}
ll* factorize(ll N) {
    ll *res = array(((sqrt(N) + 1) * 2), ll);
    ll i, x = N;
    int count = 0;
    for (i = 2; i * i <= N; i++) {
        ll e = 0;
        while (x % i == 0) {
            x /= i;
            e++;
        }
        if (e > 0) {
            res[count * 2] = i;
            res[count * 2 + 1] = e;
            count++;
        }
    }
    if (x > 1) {
        res[count * 2] = x;
        res[count * 2 + 1] = 1;
    }
    return res;
}
void check_factorization(ll *fact) {
    int i = 1;
    printf("%lld^%lld", fact[0], fact[1]);
    while (fact[i * 2] > 0) {
        printf(" * %lld^%lld", fact[i * 2], fact[i * 2 + 1]);
        i++;
    }
    printf("\n");
}