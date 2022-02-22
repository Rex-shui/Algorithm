/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */


//给定得分数组score = [5, 4, 3, 2, 1]
//输出score[i] 的名次 ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
//解释：名次为 [1st, 2nd, 3rd, 4th, 5th] 。
//前三用特殊标识，后面的用名次号

void MIN_HEAP(int **p, int i, int size)
{
    int l = 2*i+1;
    int r = 2*i+2;

    int min;
    int *pSwap;

    if(l < size && *p[l] < *p[i]) {
        min = l;
    } else {
        min = i;
    }

    if(r < size && *p[r] < *p[min]) {
        min = r;
    }

    if(min != i) {
        pSwap = p[i];
        p[i] = p[min];
        p[min] = pSwap;
        MIN_HEAP(p, min, size);
    }
}

void BUILD_MIN_HEAP(int **p, int size)
{
    for(int i=size/2; i>=0; i--) {
        MIN_HEAP(p, i, size);
    }
}

void HEAP_SORT(int **p, int size)
{
    int *pSwap;
    for(int i=size-1; i>=0; i--)
    {
        pSwap = p[0];
        p[0] = p[i];
        p[i] = pSwap;
        MIN_HEAP(p, 0, i);
    }
}

void num_to_str(char *str, int num)
{
    int idx = 0;
    while(num)
    {
        str[idx++] = num%10+'0';
        num = num / 10;
    }
    str[idx] = '\0';
    char swp;
    for(int i=0; i<idx/2; i++)
    {
        swp = str[i];
        str[i] = str[idx-1-i];
        str[idx-1-i] = swp;
    }
}


//创建指针数组指向得分的每个值
//对指针数组进行堆排序--小根堆
//用指针数组中的地址值减去得分数组首地址即可获取相应排名
char ** findRelativeRanks(int* score, int scoreSize, int* returnSize){

    int **p;
    p = malloc(sizeof(int *)*scoreSize);
    for(int i=0; i<scoreSize; i++) {
        p[i] = score+i;
    }

    BUILD_MIN_HEAP(p, scoreSize);
    HEAP_SORT(p, scoreSize);

    char **desc;
    desc = malloc(sizeof(char *)*scoreSize);
    for(int i=0; i<scoreSize; i++) {
        if(i == 0) {
            char *t = malloc(16);
            strcpy(t, "Gold Medal");
            desc[p[i] - score] = t;
            continue;
        }
        if(i == 1) {
            char *t = malloc(16);
            strcpy(t, "Silver Medal");
            desc[p[i] - score] = t;
            continue;
        }
        if(i == 2) {
            char *t = malloc(16);
            strcpy(t, "Bronze Medal");
            desc[p[i] - score] = t;
            continue;
        }

        char *tmp = malloc(8);
        num_to_str(tmp, i+1);
        desc[p[i] - score] = tmp;
    }

    *returnSize = scoreSize;
    return desc;

}
