/**
 * ���ݸ���ر�������
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Table
{
    public:
        Table(int type);
        /**
         * ����u��������
         * str:Ҫ���ҵ�����
         * return:�ɹ������±꣬ʧ�ܷ���-1
         */
        int SearchByU(string str);
        /**
         * ����h��������
         * str:Ҫ���ҵ�����
         * return:�ɹ������±꣬ʧ�ܷ���-1
         */
        int SearchByH(string str);
        /**
         * ����s��������
         * str:Ҫ���ҵ�����
         * return:�ɹ������±꣬ʧ�ܷ���-1
         */
        int SearchByS(string str);
        /**
         * ����v��������
         * str:Ҫ���ҵ�����
         * return:�ɹ������±꣬ʧ�ܷ���-1
         */
        int SearchByV(string str);
        /**
         * ����t��������
         * str:Ҫ���ҵ�����
         * return:�ɹ������±꣬ʧ�ܷ���-1
         */
        int SearchByT(string str);
        /**
         * �����±��ӡԪ����Ϣ
         * index:�±�
         */
        void PrintByIndex(int index);
        /**
         * ��ӡ��Ļ�����Ϣ
         */
        void PrintBaseMessage();
        /**
         * ��ӡ�����������
         */
        void PrintData();
    private:
        double pressure;//ѹǿ
        double tSat;    //�¶�
        vector<string> t;//�¶�
        vector<string> v;//�ܶȵĵ��� / ���
        vector<string> u;//����ѧ��
        vector<string> h;//��
        vector<string> s;//��
};