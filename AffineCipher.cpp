#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main ()
{
    /*****************************   AFFINE CIPHER   *************************************/
    /***************************** y = (ax+b) mod 26 *************************************/
    /***************************** a = 11 and b = 9  *************************************/

    string str;
    cout<<"Please Enter a String : "<<endl;
    getline(cin,str,'\n');


    int i,j,k,l;
    int a=11,b=9,m=26;
    int ainverse = 0;

    for(i=0;i<26;i++)
    {
        j=(a*i)%26;
        if(j==1)
        {
            ainverse=i;
        }
    }
     /*************************** ENCRYPTION ***********************************************/
    string encr="";
    for(i=0;i<str.size();i++)
    {
        if(isspace(str.at(i)))
        {
            encr+=str[i];
            continue;
        }
        j=(int)str.at(i)-65;
        j=((j*a)+b)%m;
        j=j+65;
        encr+=(char)j;
    }
    cout << "Encrypted Message is : " <<encr<<endl;

    /*************************** DECRYPTION ***********************************************/

    string  decr="";
    for(i=0;i<encr.size();i++)
    {
        if(isspace(encr.at(i)))
        {
            decr+=encr.at(i);
            continue;
        }
        j=(int)encr.at(i)+65;
        j=(ainverse*(j-b))%m;
        j=j+65;
        decr+=(char)j;
    }

    cout << "Decrypted Message is : " <<decr<<endl;
    return 0;
}
                    
