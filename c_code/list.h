#pragma once
#include <stdio.h>
#include <stdlib.h>

//节点结构体
typedef struct Node {
    int data;
    struct Node *next;
} LinkListNode;
//链表结构体
typedef struct Link {
    int length; // 链表长度
    LinkListNode  head;//虚拟头结点
} LinkList;
//节点初始化
LinkListNode *GetListNode(int val); 
LinkList *GetList();
int insertListNode(LinkList *l, int ind, int val);
int DeleteListNode(LinkList *l, int ind);
void ClearList(LinkList *l);
int ReverseList(LinkList *l);
void OutputList(LinkList *l);
