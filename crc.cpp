#include <iostream>
#include <string.h>

using namespace std;

int check(char recv[],char poly[],char ip[])
{
    char temp[50];
    strcpy(temp,recv);
    for(int i=0;i<=strlen(ip);i++){
        if(temp[i]=='1'){
            for(int j=0;j<strlen(poly);j++){
                if(temp[i+j]=poly[j])
                    temp[i+j]='0';
                else
                    temp[i+j]='1';
            }
        }
    }
    for (int i = 0; i < strlen(temp); i++)
     if (temp[i] == '1')
          return -1;
return 1;
}
void crc(char ip[],char op[], char poly[])
{
    strcpy(op, ip);
    for (int i = 1; i < strlen(poly); i++)
         strcat(op, "0");
         
    /* Perform XOR on the msg with the selected polynomial */
    for (int i = 0; i < strlen(ip); i++) {
        if (op[i] == '1') {
            for (int j = 0; j < strlen(poly); j++) {
                if (op[i + j] == poly[j])
                    op[i + j] = '0';
                else
                    op[i + j] = '1';
            }
        }
    }
}

int main()
{
    char ip[50], op[50], recv[50];
    char poly[] = "1101";

    cout << "Enter the input message in binary:";
    cin >> ip;
    crc(ip, op, poly);
    cout << "The checksum is: " << ip << op + strlen(ip) << endl;
    cout << "Enter the recevied checksum in binary:";
    cin >> recv;
    if(check(recv,poly,ip)==1)
       cout << "No error in data" << endl;
    else
        cout << "Error in data transmission has occurred" << endl;

    return 0;
}
