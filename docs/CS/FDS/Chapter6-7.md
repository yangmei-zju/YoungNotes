# Chapter 6 哈希表
## 6.1 哈希表
「哈希表 hash table」，又称「散列表」，其通过建立键 key 与值 value 之间的映射，实现高效的元素查询。具体而言，我们向哈希表输入一个键 key ，则可以在 $O(1)$ 时间内获取对应的值 value 。
### 6.1.1 常见操作
初始化、查询操作、添加键值对和删除键值对。
### 6.1.2 数组实现
**哈希函数**：
1. 通过某种哈希算法 hash() 计算得到哈希值。
2. 将哈希值对桶数量（数组长度）`capacity` 取模，从而获取该 `key` 对应的数组索引 `index` 。
`index = hash(key) % capacity`
![box](images\image-9.png)
# Chapter 7 树
## 7.1 二叉树
```c
/* 二叉树节点结构体 */
typedef struct TreeNode {
    int val;                // 节点值
    int height;             // 节点高度
    struct TreeNode *left;  // 左子节点指针
    struct TreeNode *right; // 右子节点指针
} TreeNode;

/* 构造函数 */
TreeNode *newTreeNode(int val) {
    TreeNode *node;

    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

```
### 7.1.1 常见术语
- 「根节点 root node」：位于二叉树顶层的节点，没有父节点。
- 叶节点 leaf node」：没有子节点的节点，其两个指针均指向 \(\text{None}\) 。
- 边 edge」：连接两个节点的线段，即节点引用（指针）。
- 节点所在的「层 level」：从顶至底递增，根节点所在层为 1 。
- 节点的「度 degree」：节点的子节点的数量。在二叉树中，度的取值范围是 0、1、2 。
- 二叉树的「高度 height」：从根节点到最远叶节点所经过的边的数量。
- 节点的「深度 depth」：从根节点到该节点所经过的边的数量。
- 节点的「高度 height」：从距离该节点最远的叶节点到该节点所经过的边的数量。
### 7.1.2 基本操作
#### 1.初始化二叉树
#### 2. 插入与删除节点
```c
/* 插入与删除节点 */
TreeNode *P = newTreeNode(0);
// 在 n1 -> n2 中间插入节点 P
n1->left = P;
P->left = n2;
// 删除节点 P
n1->left = n2;

```
### 7.1.3 常见二叉树类型
- 完美二叉树 perfect binary tree
- 完全二叉树 complete binary tree
- 完满二叉树 full binary tree
- 平衡二叉树 balanced binary tree
## 7.2 二叉树遍历
### 7.2.1层序遍历
从顶部到底部逐层遍历二叉树，并在每一层按照从左到右的顺序访问节点。
层序遍历本质上属于「广度优先遍历 breadth-first traversal」，它体现了一种“一圈一圈向外扩展”的逐层遍历方式。
**代码实现**
```c
int *levelorder(TreeNode *root, int *size){
    //辅助队列
    TreeNode **queue =(TreeNode **)malloc(Maxsize*sizeof(TreeNode *));//树指针数组
    int front = 0, rear = 0;
    
    //辅助数列
    int index = 0; 
    int *arr = (int *)malloc(Maxsize * sizeof(int));
    TreeNode *node;

    //加入根节点
    queue[rear++] = root;

    while(front < rear){
        //队列出队
        node = queue[front++];
        //保存节点值进入辅助数组
        arr[index++] = node->val;
        //子节点入队 注意左右节点入队的顺序  左边先入，则左先出
        if(node->left != NULL){
            queue[rear++] = node->left;
        }
        if(node->right != NULL){
            queue[rear++] = node->right;
        }
    }
    //更新数组长度 超过Maxsize后会为arr自动分配空间
    *size = index;
    arr = realloc(arr, sizeof(int) *(*size));
    //释放辅助队列数组
    free(queue);

    return arr;
}
```
>对于队列的使用和栈的使用，如果遍历顺序满足左右子节点先入后出则应该选择stack, 而先入先出应该选择 queue.两者基本等价也就是说层序遍历也可采用stack，nod->right先入栈后出栈。 另外，如果遍历满足之字形状（zigorder）, 可以建立两个stack， 一个左子节点先入，另一个右子节点先入。

### 7.2.2   前序、中序、后序遍历
相应地，前序、中序和后序遍历都属于「深度优先遍历 depth-first traversal」，它体现了一种“先走到尽头，再回溯继续”的遍历方式， 通常基于递归实现。
## 7.3 二叉树数组表示
1. 完美二叉树，根据层序遍历的顺序将各个节点对应数组索引。
- 若数组arr[0]储存根节点， 若节点的索引为 $i$ ，则该节点的左子节点索引为$2i+1$  ，右子节点索引为$2i+2$;
- 若数组的arr[1]储存根节点，若节点的索引为 $i$ ，则该节点的左子节点索引为$2i$  ，右子节点索引为$2i+1$;
2. 完全二叉树：`NULL`子节点只出现在最底层且靠右
- 确定节点的个数`size`， 判断索引为 $i$ 的节点其右子树索引$2i+1$是否大于`size`， 以此确定右节点是否为空。
    
3. 表示任意二叉树，应该在层序遍历中显示的写出所有的`NULL`节点。
- 标记空位：使用`int`的最大值`INT_MAX`，因此要求节点值不能为 INT_MAX

4. 基于数组表示的二叉树的操作
```c

```
     