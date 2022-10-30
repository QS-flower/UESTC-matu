#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

struct score {
    int id;
    char name[50];
    float chinese, math, english;
    float average(){
        return (chinese + math + english) / 3;
    }
    bool operator<(const score &r) const{
        return chinese + math + english < r.chinese + r.math + r.english;
    }
    bool operator>(const score &r) const{
        return chinese + math + english > r.chinese + r.math + r.english;
    }
    void displayln(){
        printf("%d %s %f %f %f\n", id, name, chinese, math, english);
    }
};

template <class type>
struct linkedlist {
    struct node {
        type data;
        node *nxt;
        node(const type &data, node *nxt) : data(data), nxt(nxt) {}
        ~node() {
            if (nxt)
                delete nxt;
        }
    } *head;
    linkedlist() : head(0){}
    void clear() {
        if (head) {
            delete head;
            head = 0;
        }
    }
    ~linkedlist() {
        clear();
    }
    void push_front(const type &data) {
        head = new node(data, head);
    }
    struct iterator {
        node *p;
        iterator(node *p) : p(p) {}
        type &operator*() {
            return p->data;
        }
        type *operator->(){
            return &(p->data);
        }
        const iterator &operator++(int) {
            iterator ret = *this;
            p = p->nxt;
            return ret;
        }
        iterator &operator++() {
            p = p->nxt;
            return *this;
        }
        bool operator==(const iterator &r) const{
            return p == r.p;
        }
        bool operator!=(const iterator &r) const{
            return p != r.p;
        }
    };
    iterator begin() {
        return iterator(head);
    }
    iterator end() {
        return iterator(0);
    }
};

linkedlist<score> lst;
int n;

int main() {
    puts("����������ʵ��");
    puts("�����������ܶ���������");
    puts("ʵ����1,2,3,4,5,6��������");
    puts("***************************");
    printf("������������");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("������� %d ���˵���Ϣ��", i);
        score tmp;
        scanf("%d%s%f%f%f", &tmp.id, tmp.name, &tmp.chinese, &tmp.math, &tmp.english);
        lst.push_front(tmp);
    }
    int m = 0;
    for (linkedlist<score>::iterator it = lst.begin(); it != lst.end(); ++it)
        if(it->average() < 60)
            m++;
    printf("������ѧ��������%d\n", m);
    for (linkedlist<score>::iterator it = lst.begin(); it != lst.end(); ++it)
        if(it->average() < 60)
            it->displayln();
    puts("***************************");
    float ave = 0;
    for (linkedlist<score>::iterator it = lst.begin(); it != lst.end(); ++it)
        ave += it->average();
    ave /= n;
    m = 0;
    for (linkedlist<score>::iterator it = lst.begin(); it != lst.end(); ++it)
        if(it->average() >= ave)
            m++;
    printf("ƽ����֮�ϵ�������%d\n", m);
    for (linkedlist<score>::iterator it = lst.begin(); it != lst.end(); ++it)
        if(it->average() >= ave)
            it->displayln();
    puts("***************************");
    int cnt[11] = {};
    for (linkedlist<score>::iterator it = lst.begin(); it != lst.end(); ++it)
        cnt[(int)it->average() / 10]++;
    for (int i = 0; i < 9; i++)
        printf("[%d, %d) �������ٷֱȣ�%d, %f%%\n", i * 10, (i + 1) * 10, cnt[i], cnt[i] * 100.0 / n);
    printf("[90, 100] �������ٷֱȣ�%d, %f%%\n", cnt[9] + cnt[10], (cnt[9] + cnt[10]) * 100.0 / n);
    puts("***************************");
    score *a = new score[n];
    int pos = 0;
    for (linkedlist<score>::iterator it = lst.begin(); it != lst.end(); ++it)
        a[pos++] = *it;
    sort(a, a + n, greater<score>());
    for (int i = 0; i < n; i++){
        printf("%d. ƽ���� %f, ", i + 1, a[i].average());
        a[i].displayln();
    }
    puts("***************************");
    while(1){
        int id;
        printf("�������ѯѧ�ţ�");
        scanf("%d", &id);
        int p = -1;
        for (int i = 0; i < n; i++)
            if(a[i].id == id)
                p = i;
        if(p == -1)
            puts("δ�ҵ���ѧ����");
        else{
            printf("������%d, ƽ���֣�%f, ", p + 1, a[p].average());
            a[p].displayln();
        }
    }
    return 0;
}