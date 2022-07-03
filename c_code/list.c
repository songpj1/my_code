#include "list.h"

LinkListNode *GetListNode(int val) {
    LinkListNode *p = (LinkListNode *)malloc(sizeof(LinkListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *GetList() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insertListNode(LinkList *l, int ind, int val) {
    if (l == NULL) return 0;
    if(ind < 0 || ind > l->length) return 0;
    LinkListNode *p = &(l->head), *new_node = GetListNode(val);
    while(ind--) p = p->next;//不能是--ind 如果ind == 0 死循环
    //p走到了前一个节点
    new_node->next = p->next;
    p->next = new_node;
    l->length += 1;
    return 1;
}

int DeleteListNode(LinkList *l, int ind) {
    if(ind < 0 || ind >= l->length) return 0;
    LinkListNode *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

void ClearList(LinkList *l) {
    LinkListNode *p = l->head.next ,*q;
    while(p) {
        q = p;
        p = p->next;
        free(p);
    }
    free(l);
    return ;
}

int ReverseList(LinkList *l) {
    if(l == NULL) return 0;
    LinkListNode *p = l->head.next, *q;
    while(p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return 1;
}

void OutputList(LinkList *l) {
    printf("head -> ");
    LinkListNode *p = l->head.next;
    while(p) {
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf(" NULL\n");
    return ;
}
