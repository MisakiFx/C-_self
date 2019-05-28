//不用+写加法
class UnusualAdd {
public:
    int addAB(int A, int B) {
        int C;//要进的位
        int cur;
        while(B != 0)
        {
            cur = A ^ B;
            C = (A & B) << 1;
            A = cur;
            B = C;
        }
        return A;
    }
};