//完全不会
//链接：https://www.nowcoder.com/questionTerminal/a5190a7c3ec045ce9273beebdfe029ee
//来源：牛客网

//https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee?tpId=85&amp;&amp;tqId=29839&amp;rp=1&amp;ru
/**
 * 题目描述
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)
输出描述:
输出可以产生的幸运的袋子数

示例1
输入
3
1 1 1

输出
2
 */
#include <stdio.h>
#include <stdlib.h>
int bag[1001],n;
 
int comp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int dfs(int pos,long long sum,long long pi){
    int i,c;
    for(i=pos,c=0;i<n;++i){
        sum+=bag[i];
        pi*=bag[i];
        if (sum>pi) c+=1+dfs(i+1,sum,pi);
        else if (bag[i]==1) c+=dfs(i+1,sum,pi);
        else break;
        sum-=bag[i];
        pi/=bag[i];
        for(;i<n-1 && bag[i]==bag[i+1];++i);// duplicate
    }
    return c;
}
int main(){
    int i;
    while(~scanf("%d",&n)){
        for(i=0;i<n;scanf("%d",&bag[i++]));
        qsort(bag,n,sizeof(int),comp);
        printf("%d\n",dfs(0,0,1));
    }
    return 0;
}