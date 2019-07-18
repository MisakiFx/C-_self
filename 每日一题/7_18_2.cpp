#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
 
using namespace std;
 
string getFileName(string path){
    int pos = path.rfind('\\');
    return path.substr(pos + 1);
}
 
string modifyName(string name){
    if (name.size() > 16){
        name = name.substr(name.size() - 16);
    }
 
    return name;
}
 
struct ErrRecord{
    string file;
    int lineNo;
    int count;
 
    ErrRecord(string file, int lineNo){
        this->file = file;
        this->lineNo = lineNo;
        count = 1;
    }
 
    bool operator==(const ErrRecord & a){
        return (file == a.file) && (lineNo == a.lineNo);
    }
};
 
int main(){
    string file;
    int lineNo;
    vector<ErrRecord> myvec;
    while (cin >> file >> lineNo)
    {
        //在给入数据时是给全名，包括查重也是查全名（净文件名）
        ErrRecord record(getFileName(file), lineNo);
        auto res = find(myvec.begin(), myvec.end(), record);
        if (res == myvec.end()){
            myvec.push_back(record);
        }
        else{
            res->count++;
        }
    }
    int count = 0;
    //打印最后八个数据
    for (auto item : myvec)
    {
        if (count + 8 >= myvec.size()){
            //输出时是输出文件名后16个字符
            cout << modifyName(item.file) << " " << item.lineNo << " "
                << item.count << endl;
        }
        count++;       
    }
    return 0;
}