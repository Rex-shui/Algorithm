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
  3. 队满判断：(Q.rear + 1) % MAXLENGTH == Q.rear**`（损失一个空间）`**
  4. 队列长度：(Q.rear + MAXKENGTH - Q.front) % MAXLENGTH



#### 树

---

1. 二叉树
2. 二叉搜索树
3. 平衡二叉树（AVL树）

---

* 二叉树

  ```C
  typedef struct Node{
      void *data;
      struct Node *left,*right;
  }Node;
  ```

  遍历：先序遍历，中序遍历，后序遍历，层次遍历

* 二叉搜索树
  1. 对于任何节点x，左子树中的关键字最大不超过下x.key，右子树中的关键字最小不低于x.key。
  2. 插入
  3. 删除：

* 平衡二叉树
  1. 平衡二叉树是一颗空树，或者左右子树高度差的绝对值不超过1
  2. 平衡二叉树的左右两个子树都是一颗平衡二叉树






