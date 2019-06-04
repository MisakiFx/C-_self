class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int count = 0;
        int leftSum = 0;
        int rightSum = 0;
        int leftMin = 27;
        int rightMin = 27;
        for(int i = 0; i < n; i++)
        {
            //如果不存在这种颜色手套有一只不匹配则为无效解，这些手套必须全部拿上
            if(left[i] == 0 || right[i] == 0)
            {
                count += left[i];
                count += right[i];
            }
            else
            {
                leftSum += left[i];
                rightSum += right[i];
                leftMin = min(leftMin, left[i]);
                rightMin = min(rightMin, right[i]);
            }
        }
        //根据数学原理可知要把一只手所有颜色手套全拿完需要这只手所有颜色手套总和-最小值+1 
        return count + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
    }
};
int main()
{

}