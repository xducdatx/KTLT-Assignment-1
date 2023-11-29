/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int Mahattan(int x,int y,int x1,int y1){
    int m=0;
    m=abs(x-x1)+abs(y-y1);
    return m; 
}
int checkFibo(int x)
{
	int a = 0;
	int b = 1;
	if (x == a || x == b) return 1;
	int c = a + b;
	while (c <= x)
	{
		if (c == x) return 1;
		a = b;
		b = c;
		c = a + b;
	}
	return 0;
}
int checkPrimeN(int x)
{
	if(x<2)
		return 0;
	for(int i=2; i<=x/2; i++)
		if(x%i==0)
			return 0;
	return 1;
}
int changeNumber (string x){
         //********************************************
        if (x[0]=='-'){
            x=x.substr(1,x.length()-1);
         }
    int n=x.size();
    int mang[n];
    for (int i=0;i<n;i++){
        if (x[i]=='0') mang[i]=0;
        else if (x[i]=='1') mang[i]=1;
        else if (x[i]=='2') mang[i]=2;
        else if (x[i]=='3') mang[i]=3;
        else if (x[i]=='4') mang[i]=4;
        else if (x[i]=='5') mang[i]=5;
        else if (x[i]=='6') mang[i]=6;
        else if (x[i]=='7') mang[i]=7;
        else if (x[i]=='8') mang[i]=8;
        else if (x[i]=='9') mang[i]=9;
    }
    int tonggiatri=0;
    for(int i=0;i<n;i++){
        tonggiatri=tonggiatri+mang[i]*pow(10,n-i-1);
    }
    return tonggiatri;
}
int countString (string x){
    int n=0;
    while(x[n]!='\0'){
    n++;
    }
    return n;
}
int checkNumber (string x){
    int check = 1;
    for (int i = 0; i < x.size(); i++){
    if (x[i]>47&&x[i]<58){ check=1; }
    else{
        check=0;
        break;}
    }   
    return check;
    }
string Sum2String (string x, string y){
int mang[10];
for (int i=0;i<10;i++){
    mang[i] = 0;
    }
for (int i=0;i<10;i++){
string x1 = x.substr(i,1);
string y1 = y.substr(i,1);
int m,n;
m = changeNumber(x1);
n = changeNumber(y1);
int sum = 0;
sum = mang[i]+m+n;
if (sum >=10){
sum = sum % 10;
if (i<9)  mang[i+1] = 1;
}
 mang[i] = sum;   
}
     long long  tong=0;
    for (int i=0;i<10;i++){
            tong += mang[i]*pow(10,9-i);}
    string result;          
    ostringstream convert;   
    convert << tong;      
    result = convert.str();    
     while (result.length() < 10){
        result.insert(result.begin() , '0');
    }
    return result;
 }
string notebook1(string ntb1) {
    // Complete this function to gain point
    string z1;
    ifstream file1;
    file1.open(ntb1);
    file1 >> z1;
    int check2 = 0;
    if (z1.length() == 14) check2 = 1;
    z1 = z1.substr(11,3);
    bool check = 0;
    int check1;
    check1 = checkNumber(z1);
    if (check1 == 1 && check2 == 1) check =1;
    
    
////////////
    if (check){
        int mang[changeNumber(z1)];
        for (int i=0;i<changeNumber(z1);i++){         // Mảng các giá trị
            file1>>mang[i];
        }
        int mangdem[10];                               // Mảng số lượng giá trị xuất hiện
        for(int i=0;i<10;i++){
            mangdem[i]=0;
        }
        for (int i=0;i<changeNumber(z1);i++){ 
            if (mang[i]==0) mangdem[0]=mangdem[0]+1;
            if (mang[i]==1) mangdem[1]=mangdem[1]+1;
            if (mang[i]==2) mangdem[2]=mangdem[2]+1;
            if (mang[i]==3) mangdem[3]=mangdem[3]+1;
            if (mang[i]==4) mangdem[4]=mangdem[4]+1;
            if (mang[i]==5) mangdem[5]=mangdem[5]+1;
            if (mang[i]==6) mangdem[6]=mangdem[6]+1;
            if (mang[i]==7) mangdem[7]=mangdem[7]+1;
            if (mang[i]==8) mangdem[8]=mangdem[8]+1;
            if (mang[i]==9) mangdem[9]=mangdem[9]+1;
        }
         for (int i=0;i<10;i++){ 
            if (mangdem[i]>=10) mangdem[i]=mangdem[i]%10;
        }
        long long sum=0;
        for (int i=0;i<10;i++){
            sum += mangdem[i]*pow(10,9-i);}
        string result1;          
    ostringstream convert;   
    convert << sum;      
    result1 = convert.str();
     while (result1.length() < 10){
        result1.insert(result1.begin() , '0');
    }
    return result1;
    }

////////////
else{
    return "0000000000";}
}

string notebook2(string ntb2) {
    // Complete this function to gain point
///////////////////
ifstream file2;
file2.open(ntb2);
string n2;
file2 >> n2;
int x2;
x2 = changeNumber(n2);
int check3 = 0;
if (n2.length() == 5 && x2 >= 5 && x2 <= 100) check3 = 1;
if (check3 ==  0) return "1111111111";
bool check2 = 0;
int check4 = 0;
check4 = checkNumber(n2); //  kiểm tra đầu vào xem nó có hợp lệ hay k ***********************
int arr2[x2];// mảng dùng để lưu các giá trị đếm pink và Pink của mỗi hàng **********
if (check3 == 1 && check4 == 1 && x2 >= 5 && x2 <= 100) check2 =1;
if (check2){
    long long sum2 = 0;
for (int i = 0; i <= x2; i++){
       string a;
       getline (file2,a);   
       int dem = 0;
       int count = countString(a);
       for (int j = 0;j < count; j++){
           if (a.substr(j,4)=="pink" || a.substr(j,4)=="Pink") dem++;
       }
       arr2[i] = dem;// i chạy từ 1-> x2*************************
   }
for (int i = 1; i <= x2; i++){
    sum2 += arr2[i];
}
if (sum2==0) return"0999999999";
if (sum2 < 10000) sum2 = pow(sum2,2);
int m = sum2;
int dem2 = 1;   
while (m >= 10){
    m/=10;
    dem2++;
}

sum2 = sum2*pow(10,10-dem2);
for (int i = 0; i < 10 - dem2; i++){
    sum2 +=  9 * pow(10, i);
}
string result2;          
    ostringstream convert;   
    convert << sum2;      
    result2 = convert.str();    
    return result2;
}
else{
return "1111111111";}
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    ////////
ifstream file3;
    file3.open(ntb3);
    int arr3[10][10];
    for (int i = 0; i < 10; i++){
    string x;
    file3 >> x;
    int n = 0;
    int m = 0;
        for(int j = 0 ; j < 10; j++){
          string v;
          m = n;
          while(x[n] != '|' && x[n] != '\0') n++;
          v = x.substr(m,n-m);
          n = n+1;
          int sum3;
          sum3 = changeNumber(v);
          arr3[i][j] = abs(sum3);
        }
    }
    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++){
        while (checkPrimeN(arr3[i][j]) != 1) arr3[i][j]++;
        }
    }
    for (int i = 1; i < 10; i++){
        for (int j = 0; j < i; j++){
         while (checkFibo(arr3[i][j]) != 1){
        arr3[i][j]++;   
        }
    }
    }
    for (int i = 0; i < 10; i++){
        int D = 0;
        if (arr3[i][7] > arr3[i][8]){
            D = arr3[i][7];
            arr3[i][7] = arr3[i][8];
            arr3[i][8] = D;
        }
        if (arr3[i][7] > arr3[i][9]){
            D = arr3[i][7];
            arr3[i][7] = arr3[i][9];
            arr3[i][9] = D;
        }
        if (arr3[i][8] > arr3[i][9]){
            D = arr3[i][8];
            arr3[i][8] = arr3[i][9];
            arr3[i][9] = D;
        }
    }    
        long long sum4 = 0;
    for (int i = 0 ; i < 10 ; i++){
        int flag = 0;
        int max = arr3[i][0];
        for(int j = 1;j < 10; j++){
        if (max <= arr3[i][j]){
        max = arr3[i][j];
        flag = j;
        }
        }
        sum4 += flag*pow(10,9-i);
    }
    ////////
    string result3;          
    ostringstream convert;   
    convert << sum4;      
    result3 = convert.str();    
    while (result3.length() < 10){
        result3.insert(result3.begin() , '0');
    }
    return result3;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string g0,g1,g2,g3,g4,g5,g6,g7,g8,g9;
g0=";";
g1=pwd1;
g2=pwd2;
g3=pwd3;
g4 = Sum2String(g1, g2);
g5 = Sum2String(g1, g3);
g6 = Sum2String(g2, g3);
g7 = Sum2String(g4, g3);
g8 = Sum2String(g1, g6);
g9 = Sum2String(g4, g5);
string a;
a=g1+g0+g2+g0+g3+g0+g4+g0+g5+g0+g6+g0+g7+g0+g8+g0+g9;
return a;
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    string ma,na; // m la outtimes , n la outcatchups
for (int i = 0; i < 100; i++){
    for (int j = 0; j < 100; j++){
        arr[i][j] = -9;
    }
}
arr[0][0]=0;
int m = moves.length();
int index1 = 0;
int index2 = 0;
for (int i =0 ; i < m; i++){
    if (moves[i] == 'R' && index2 < 99){
         index2++;
         arr[index1][index2] = arr[index1][index2-1] + 9;
         }
    if (moves[i] == 'L' && index2 > 0){
         index2--;
         arr[index1][index2] = arr[index1][index2+1] + 9;
        }
    if (moves[i] == 'U' && index1 > 0){
        index1--;
        arr[index1][index2] = arr[index1+1][index2] + 9;
        }
    if (moves[i] == 'D' && index1 < 99){
         index1++;
         arr[index1][index2] = arr[index1-1][index2] + 9;
        }      
}
int mang[100][100];
for (int i = 0; i < 100; i++){
    for (int j = 0; j < 100; j++){
        mang[i][j] = 0;
    }
}
int m1 = points.length();
int x1=0;
int y1=0;
int time=0;
int gap = 0;
for (int i = 0 ; i<m1;i++){
    if (points[i] == '('){
    string a1;
    string a2;
        int a=i+1;
        int dema = 0;
        while (points[a] != ','){
            dema++;
            a++;
        }
        a1=points.substr(i+1,dema);
        int b=a+1;
        int demb=0;
        while (points[b] != ')'){
            demb++;
            b++;
        }
        a2=points.substr(a+1,demb);
        int x,y;
        x=changeNumber(a1);
        y=changeNumber(a2);
        mang[x][y]=time+14*Mahattan(x,y,x1,y1);
        time = mang[x][y];
        x1=x;
        y1=y;
    string result;          
    ostringstream convert;   
    convert << time;      
    result = convert.str();  
    string la = ";"  ;
    string lb = "-";
    string dung="Y";
    string sai="N";
//****************************

if (arr[x][y]!=-9 && arr[x][y] > mang[x][y] && gap==0){
        ma=ma+result+la;
        na=na+dung+la;
        gap=1;
        continue;
    }
    if (gap!=1){
        ma=ma+result+la;
    }
    if (gap==1){
        ma=ma+lb+la;;
        na=na+lb+la;
    }
    if (gap!=1){
        na=na+sai+la;
    }

//****************************

    }
}
    na.pop_back();
    ma.pop_back();
    outTimes=ma;
    outCatchUps=na;
   if (gap==1) return true;
    // Complete this function to gain point
    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream file4;
    file4.open(tag);
    string email1,email2;
    string add1,n;
    file4 >> email1;
    file4 >> email2; // dia chi email
    file4 >> add1;
    file4 >> n; //so
    int m = changeNumber(n);
    string p;
    for (int i = 0; i < m; i++){
        p = p + message;
    }
    string q = ";";
    string f;
    f = email2+q+p;
    return f;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
