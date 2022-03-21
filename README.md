#### [栈：先进后出](./src/stack.c)

---

```C
typedef struct stack{
    void **data;
    int top;
}Stack;
```



#### [队列：先进先出](./src/queue.c)

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
  3. 队满判断：(Q.rear + 1) % MAXLENGTH == Q.rear`（损失一个空间）`
  4. 队列长度：(Q.rear + MAXKENGTH - Q.front) % MAXLENGTH



#### 树

---

1. 二叉树
   * 线索二叉树
   * [二叉搜索树](./src/binarySearchTree.c)
   * 平衡二叉树-->[红黑树（大致平衡）](./src/red-black-tree.c)
   * 最优二叉树
2. 森林


---

* 平衡二叉树的调整（`最下不平衡树`）
  * 插入（LL，LR，RL，RR）
  * 删除（递归调用，不是根节点则需要平衡性检查）
    1. 左子树大于右子树高度，将左子树中最大的那个元素赋给当前根节点，...
    2. 左子树小于右子树高度，...
    3. 左右子树有一个为空，直接用非空子树或者NULL替换当前节点
* 红黑树
  1. 每个节点或是红色，或是黑色
  2. 根节点是黑色的
  3. 每个叶子节点（NULL）是黑色的
  4. 如果一个节点是红色的，则它的两个子节点都是黑色的。
  5. 对于每个节点，从该节点到其后代叶节点的简单路径上，均包含相同数目的黑色节点。



#### 图

---

* 存储结构
* 遍历
* 最小生成树
* 应用

---

* 基本存储结构

  ```C
  typedef struct graph{
      int vtx[MAXLEN];
      int arc[MAXLEN][MAXLEN];
      int arcnum;
      int vtxnum;
  }Graph;
  ```

* 遍历

  * [广度优先搜索](./src/breadthFirstSearch.c)
  * 深度优先搜索


#### 堆

---

* 插入：末尾插入，然后上浮
* 删除：末尾元素替代删除元素，然后下沉
* [堆排序](./src/heap-sort.c)
* [相对名次](./src/releative-rank.c)


#### 动态规划

---

* [钢铁切割](./src/steelBarCutting.c)
* [最小路径和](./src/minPathSum.cpp)
* [最小编辑距离](./src/minEditDistance.cpp)
* [买股票的最佳时机](./src/maxProfit2.cpp)


#### some

---

* [八皇后问题--递归](./src/eightQueen.cpp)
*


#### 排序

---

* [快速排序](./src/quick-sort.c)
