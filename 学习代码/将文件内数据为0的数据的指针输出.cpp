#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file("integers", ios_base::in | ios_base::binary);
    if (file) {
        while (file) {//�����ļ�βfileΪ0
            streampos here = file.tellg();//ȥ�ĵ�ǰ��ָ���λ�� 
            int v;
            file.read(reinterpret_cast<char *>(&v), sizeof(int));
            if (file && v == 0) 
            cout << "Position " << here << " is 0" << endl;
        }
    } else {
        cout << "ERROR: Cannot open file 'integers'." << endl;
    }
    file.close();
    return 0;
}
