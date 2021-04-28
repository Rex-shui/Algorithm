#### 栈：先进后出

---

```C
typedef struct stack{
    void **data;
    int top;
}Stack;
```



#### 队列：先进先出

* 数据结构

---

```c
#define MAXLENGTH 100
typedef struct Queue{
    void **data;
    int front;
    int rear;
}Queue;
```

* 循环队列
  1. 头指针指向队首，尾指针指向队尾的下一个
  2. 队空判断：Q.front == Q.rear
  3. 队满判断：(Q.rear + 1) % MAXLENGTH == Q.rear**（损失一个空间）**
  4. 队列长度：(Q.rear + MAXKENGTH - Q.front) % MAXLENGTH



#### 树

---

1. 二叉树
   * 线索二叉树
   * 二叉搜索树
   * 平衡二叉树-->[红黑树（大致平衡）](./src/red-black-tree.c)
   * 最优二叉树
2. 森林

