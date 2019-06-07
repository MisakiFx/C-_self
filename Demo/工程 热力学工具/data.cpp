/**
 * 数据表实现
 */
#include "data.h"
Table::Table(int type)
{
    if(type == 1)
    {
        //初始化数据
        pressure = 2.5;
        tSat = 223.99;
        t.push_back("20");
        t.push_back("40");
        t.push_back("80");
        t.push_back("100");
        t.push_back("140");
        t.push_back("180");
        t.push_back("200");
        t.push_back("220");
        t.push_back("Sat.");
        v.push_back("1.0006");
        v.push_back("1.0067");
        v.push_back("1.0280");
        v.push_back("1.0423");
        v.push_back("1.0784");
        v.push_back("1.1261");
        v.push_back("1.1555");
        v.push_back("1.1898");
        v.push_back("1.1973");
        u.push_back("83.80");
        u.push_back("167.25");
        u.push_back("334.29");
        u.push_back("418.24");
        u.push_back("587.82");
        u.push_back("761.16");
        u.push_back("849.9");
        u.push_back("940.7");
        u.push_back("959.1");
        h.push_back("86.30");
        h.push_back("169.77");
        h.push_back("336.86");
        h.push_back("420.85");
        h.push_back("590.52");
        h.push_back("763.97");
        h.push_back("852.8");
        h.push_back("943.7");
        h.push_back("962.1");
        s.push_back(".2961");
        s.push_back(".5715");
        s.push_back("1.0737");
        s.push_back("1.3050");
        s.push_back("1.7369");
        s.push_back("2.1375");
        s.push_back("2.3294");
        s.push_back("2.5174");
        s.push_back("2.5546");
    }
    if(type == 2)
    {
        pressure = 5.0;
        tSat = 263.99;
        t.push_back("20");
        t.push_back("40");
        t.push_back("80");
        t.push_back("100");
        t.push_back("140");
        t.push_back("180");
        t.push_back("200");
        t.push_back("220");
        t.push_back("Sat.");
        v.push_back(".9995");
        v.push_back("1.0056");
        v.push_back("1.0268");
        v.push_back("1.0410");
        v.push_back("1.0768");
        v.push_back("1.1240");
        v.push_back("1.1530");
        v.push_back("1.1866");
        v.push_back("1.2859");
        u.push_back("83.65");
        u.push_back("166.95");
        u.push_back("333.72");
        u.push_back("417.52");
        u.push_back("586.76");
        u.push_back("759.63");
        u.push_back("848.1");
        u.push_back("938.4");
        u.push_back("1147.8");
        h.push_back("88.65");
        h.push_back("171.97");
        h.push_back("338.85");
        h.push_back("422.72");
        h.push_back("592.15");
        h.push_back("765.25");
        h.push_back("853.9");
        h.push_back("944.4");
        h.push_back("1154.2");
        s.push_back(".2956");
        s.push_back(".5705");
        s.push_back("1.0720");
        s.push_back("1.3030");
        s.push_back("1.7343");
        s.push_back("2.1341");
        s.push_back("2.3255");
        s.push_back("2.5128");
        s.push_back("2.9202");
    }
    if(type == 3)
    {
        pressure = 7.5;
        tSat = 290.59;
        t.push_back("20");
        t.push_back("40");
        t.push_back("80");
        t.push_back("100");
        t.push_back("140");
        t.push_back("180");
        t.push_back("220");
        t.push_back("260");
        t.push_back("Sat.");
        v.push_back(".9984");
        v.push_back("1.0045");
        v.push_back("1.0256");
        v.push_back("1.0397");
        v.push_back("1.0752");
        v.push_back("1.1219");
        v.push_back("1.1835");
        v.push_back("1.2696");
        v.push_back("1.3677");
        u.push_back("83.50");
        u.push_back("166.64");
        u.push_back("333.15");
        u.push_back("416.81");
        u.push_back("585.72");
        u.push_back("758.13");
        u.push_back("936.2");
        u.push_back("1124.4");
        u.push_back("1282.0");
        h.push_back("90.99");
        h.push_back("174.18");
        h.push_back("340.84");
        h.push_back("424.62");
        h.push_back("593.78");
        h.push_back("766.55");
        h.push_back("945.1");
        h.push_back("1134.0");
        h.push_back("1292.2");
        s.push_back(".2950");
        s.push_back(".5696");
        s.push_back("1.0704");
        s.push_back("1.3011");
        s.push_back("1.7317");
        s.push_back("2.1308");
        s.push_back("2.5083");
        s.push_back("2.8763");
        s.push_back("3.1649");
    }
    if(type == 4)
    {
        pressure = 10.0;
        tSat = 311.06;
        t.push_back("20");
        t.push_back("40");
        t.push_back("80");
        t.push_back("100");
        t.push_back("140");
        t.push_back("180");
        t.push_back("220");
        t.push_back("260");
        t.push_back("Sat.");
        v.push_back(".9972");
        v.push_back("1.0034");
        v.push_back("1.0245");
        v.push_back("1.0385");
        v.push_back("1.0737");
        v.push_back("1.1199");
        v.push_back("1.1805");
        v.push_back("1.2645");
        v.push_back("1.4524");
        u.push_back("83.36");
        u.push_back("166.35");
        u.push_back("332.59");
        u.push_back("416.12");
        u.push_back("584.68");
        u.push_back("756.65");
        u.push_back("934.1");
        u.push_back("1121.1");
        u.push_back("1393.0");
        h.push_back("93.33");
        h.push_back("176.38");
        h.push_back("342.83");
        h.push_back("426.50");
        h.push_back("595.42");
        h.push_back("767.84");
        h.push_back("945.9");
        h.push_back("1133.7");
        h.push_back("1407.6");
        s.push_back(".2945");
        s.push_back(".5686");
        s.push_back("1.0688");
        s.push_back("1.2992");
        s.push_back("1.7292");
        s.push_back("2.1275");
        s.push_back("2.5039");
        s.push_back("2.8699");
        s.push_back("3.3596");
    }
    if(type == 5)
    {
        pressure = 15.0;
        tSat = 342.24;
        t.push_back("20");
        t.push_back("40");
        t.push_back("80");
        t.push_back("100");
        t.push_back("140");
        t.push_back("180");
        t.push_back("220");
        t.push_back("260");
        t.push_back("300");
        t.push_back("Sat.");
        v.push_back(".9950");
        v.push_back("1.0013");
        v.push_back("1.0222");
        v.push_back("1.0361");
        v.push_back("1.0707");
        v.push_back("1.1159");
        v.push_back("1.1748");
        v.push_back("1.2550");
        v.push_back("1.3770");
        v.push_back("1.6581");
        u.push_back("83.06");
        u.push_back("165.76");
        u.push_back("331.48");
        u.push_back("414.74");
        u.push_back("582.66");
        u.push_back("753.76");
        u.push_back("929.9");
        u.push_back("1114.6");
        u.push_back("1316.6");
        u.push_back("1585.6");
        h.push_back("97.99");
        h.push_back("180.78");
        h.push_back("346.81");
        h.push_back("430.28");
        h.push_back("589.72");
        h.push_back("770.50");
        h.push_back("945.5");
        h.push_back("1133.4");
        h.push_back("1337.3");
        h.push_back("1610.5");
        s.push_back(".2934");
        s.push_back(".5666");
        s.push_back("1.0656");
        s.push_back("1.2955");
        s.push_back("1.7242");
        s.push_back("2.1210");
        s.push_back("2.4953");
        s.push_back("2.8576");
        s.push_back("3.2260");
        s.push_back("3.6848");
    }
    if(type == 6)
    {
        pressure = 20.0;
        tSat = 365.8;
        t.push_back("20");
        t.push_back("40");
        t.push_back("80");
        t.push_back("100");
        t.push_back("140");
        t.push_back("180");
        t.push_back("220");
        t.push_back("260");
        t.push_back("300");
        t.push_back("Sat.");
        v.push_back(".9928");
        v.push_back(".9992");
        v.push_back("1.0199");
        v.push_back("1.0337");
        v.push_back("1.0678");
        v.push_back("1.1120");
        v.push_back("1.1693");
        v.push_back("1.2462");
        v.push_back("1.3596");
        v.push_back("2.036");
        u.push_back("82.77");
        u.push_back("165.17");
        u.push_back("334.40");
        u.push_back("414.39");
        u.push_back("580.69");
        u.push_back("750.95");
        u.push_back("925.9");
        u.push_back("1108.6");
        u.push_back("1306.1");
        u.push_back("1785.6");
        h.push_back("102.62");
        h.push_back("185.16");
        h.push_back("350.80");
        h.push_back("434.06");
        h.push_back("602.04");
        h.push_back("773.20");
        h.push_back("949.3");
        h.push_back("1133.5");
        h.push_back("1333.3");
        h.push_back("1826.3");
        s.push_back(".2923");
        s.push_back(".5646");
        s.push_back("1.0624");
        s.push_back("1.2917");
        s.push_back("1.7193");
        s.push_back("2.1147");
        s.push_back("2.4870");
        s.push_back("2.8459");
        s.push_back("3.2071");
        s.push_back("4.0139");
    }
    if(type == 7)
    {
        pressure = 25;
        tSat = 0;
        t.push_back("20");
        t.push_back("40");
        t.push_back("100");
        t.push_back("200");
        t.push_back("300");
        v.push_back(".9907");
        v.push_back(".9971");
        v.push_back("1.0313");
        v.push_back("1.1344");
        v.push_back("1.3442");
        u.push_back("82.47");
        u.push_back("164.60");
        u.push_back("412.08");
        u.push_back("834.5");
        u.push_back("1296.6");
        h.push_back("107.24");
        h.push_back("189.52");
        h.push_back("437.85");
        h.push_back("862.8");
        h.push_back("1330.2");
        s.push_back(".2911");
        s.push_back(".5626");
        s.push_back("1.2881");
        s.push_back("2.2961");
        s.push_back("3.1900");
    }
    if(type == 8)
    {
        pressure = 30;
        tSat = 0;
        t.push_back("20");
        t.push_back("40");
        t.push_back("100");
        t.push_back("200");
        t.push_back("300");
        v.push_back(".9886");
        v.push_back(".9951");
        v.push_back("1.0290");
        v.push_back("1.1302");
        v.push_back("1.3304");
        u.push_back("82.17");
        u.push_back("164.04");
        u.push_back("410.78");
        u.push_back("831.4");
        u.push_back("1287.9");
        h.push_back("111.84");
        h.push_back("193.89");
        h.push_back("441.66");
        h.push_back("865.3");
        h.push_back("1327.8");
        s.push_back(".2899");
        s.push_back(".5607");
        s.push_back("1.2844");
        s.push_back("2.2893");
        s.push_back("3.1741");
    }
}
int Table::SearchByT(string str)
{
    for(int i = 0; i < t.size(); i++)
    {
        if(t[i] == str)
        {
            return i;
        }
    }
    return -1;
}
void Table::PrintByIndex(int index)
{
    if(index < 0)
    {
        cout << "PrintByIndex Error: No data select by index!" << endl;
        return;
    }
    cout << "pressure = " << pressure << "(Mpa)";
    if(tSat != 0)
    {
        cout << "\t" << "Tsat = " << tSat << "(°C)";
    }
    cout << endl;
    cout << "T(°C)" << "\t" << "v(m^3/kg)" << "\t" << "u(kj/kg)" << "\t" << "h(kj/kg)" << "\t" << "s(kj/kg*K)" << endl;
    cout << t[index] << "\t" << v[index] << "\t\t" << u[index] << "\t\t" << h[index] << "\t\t" << s[index] << endl;
}
int Table::SearchByV(string str)
{

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == str)
        {
            return i;
        }
    }
    return -1;
}
int Table::SearchByU(string str)
{

    for(int i = 0; i < u.size(); i++)
    {
        if(u[i] == str)
        {
            return i;
        }
    }
    return -1;
}
int Table::SearchByH(string str)
{

    for(int i = 0; i < h.size(); i++)
    {
        if(h[i] == str)
        {
            return i;
        }
    }
    return -1;
}
int Table::SearchByS(string str)
{

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == str)
        {
            return i;
        }
    }
    return -1;
}
void Table::PrintBaseMessage()
{
    cout << "pressure = " << pressure << "(Mpa)";
    if(tSat != 0)
    {
        cout << "\t" << "Tsat = " << tSat << "(°C)";
    }
    cout << endl;
}
void Table::PrintData()
{
    cout << "pressure = " << pressure << "(Mpa)";
    if(tSat != 0)
    {
        cout << "\t" << "Tsat = " << tSat << "(°C)";
    }
    cout << endl;
    cout << "T(°C)" << "\t" << "v(m^3/kg)" << "\t" << "u(kj/kg)" << "\t" << "h(kj/kg)" << "\t" << "s(kj/kg*K)" << endl;
    for(int i = 0; i < t.size(); i++)
    {
        cout << t[i] << "\t" << v[i] << "\t\t" << u[i] << "\t\t" << h[i] << "\t\t" << s[i] << endl;
    }
}