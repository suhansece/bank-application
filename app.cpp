#include <iostream>
#include <stdio.h>
#include <list>
#include <iterator>
using namespace std;

class account{
    public:
    int accountNo;
    int balance;
    char dateOfOpen[12];
    char type;
    account(){
      cout<<"-----------------------"<<endl;
      cout<<"Enter user Account Details"<<endl;
      cout<<"-----------------------\n\n"<<endl;
      cout<<"Create Account No :";
      cin>>accountNo;
      balance=0;
      cout<<"Enter todays date:";
      cin>>dateOfOpen;
      cout<<"Enter account type(S/C):";
      cin>>type;
    }
    void getAccount(){
      cout<<"-----------------------"<<endl;
      cout<<"Account Details"<<endl;
      cout<<"-----------------------\n\n"<<endl;
      cout<<"AccountNo : "<<accountNo<<endl;
      cout<<"Balance : "<<balance<<endl;
      cout<<"Date Of Open : "<<dateOfOpen<<endl; 
    }
    int creditAmmount(){
      int a;
      cout<<"Enter amount"<<endl;
      cin>>a;
      balance+=a;
      cout<<"Amount "<<a<<" Credited"<<endl;
    }
    void debitAmmount(){
      cout<<"-----------------------"<<endl;
      int a;
      cout<<"Enter amount"<<endl;
      cin>>a;
      if(balance<a){
    cout<<"----Insufficient Balance----"<<endl;
      }
      else{
        balance-=a;
        cout<<"Amount "<<a<<" Debited"<<endl;
      }
      
      cout<<"Current Account Balance : "<<balance<<endl;
    }
    void getBalance(){
      cout<<"-----------------------"<<endl;
      cout<<"Current Account Balance : "<<balance<<endl;
    }
    

};
class branch{
  public:
  char ifsc[20];    
  char city[30];
  list <account> accounts;
  public:
  branch(){    
    cout<<"-----------------------"<<endl;
  cout<<"Enter Your Branch   Details\n"; 
    cout<<"-----------------------\n\n"<<endl;
  cout<<"Enter IFSC code : ";        
  cin>>ifsc;        
  cout<<"Enter Branch City : ";        
  cin>>city;   
  }
  void getAllaccount(){
    int j=1;
      cout<<"-----------------------"<<endl;
      for(auto i : accounts){
        cout<<"AccountNo : "<<i.accountNo<<endl;
        cout <<"Balance : "<<i.balance<<endl;
        cout<<"DateOfOpen : "<<i.dateOfOpen<<endl;
      }
  }
void getBranch(){
      cout<<"-----------------------"<<endl;
        cout <<"IFSC : "<<ifsc<<endl;
        cout<<"City : "<<city<<endl;
    } 
void addAccount(){
  account newAccount;
     accounts.push_back(newAccount);
}
};


class bank{  
    public:
    char bankName[30];
    char bankCode[30];    
    list <branch> branches;
    public:
    bank(){      
      cout<<"-----------------------"<<endl;
        cout<<"Create Bank\n";    
      cout<<"-----------------------\n\n"<<endl;
        cout<<"Enter Your Bank Name : ";
        cin>>bankName;        
        cout<<"Enter Bank Code : ";              
        cin>>bankCode;          
    }
   void addBranch(){
     branch newBranch;
     branches.push_back(newBranch);
     
   }
    /* void removeBranch(){
      cout<< "Enter your IFSC To Remove Branch From Bank\n";
      char *ifscc;
      cin>>ifscc; 
      int j=0;
      for(auto i : branches){
        j++;
        if(i.ifsc == ifscc){
          branches.erase(j);
          break;
        }
      }
    } */
    void getAllBranch(){
      int j=1;
      cout<<"-----------------------"<<endl;
      for(auto i : branches){
        cout<<"Branch : "<<j++<<endl;
        cout <<"IFSC : "<<i.ifsc<<endl;
        cout<<"City : "<<i.city<<endl;
      }
    } 


  
};


int main()
{    
  bank b;
  int process=1;
  while(process){
    cout<<"\n\n\n-----------------------"<<endl;
    cout<<"Choose Features\n";
    cout<<"-----------------------"<<endl;
    cout<<"Add Branch Enter 1 \n\nGet Branche Enter 2\n\nGet All Branch Enter 3 \n\nAdd Account Enter 4\n\nGet Account Details Enter 5\n\nget All Account Details Enter 6\n\nDebit amount Enter Enter 7 \n\ncredit Amount Enter 8\n\nGet Balance Enter 9\n\nTo Exit Enter 10\n\n";

    int choise;
    cin>>choise;
    switch(choise){
      case 1:
      b.addBranch();
      break;
      case 2:
      b.branches.front().getBranch();
      break;
      case 3 :
      b.getAllBranch();
      break;
      case 4:
      b.branches.front().addAccount();
      break;
      case 5:
       b.branches.front().accounts.front().getAccount();
      break;
      case 6:
       b.branches.front().getAllaccount();
      break;
      case 7:
      b.branches.front().accounts.front().debitAmmount();
      break;
      case 8:
      b.branches.front().accounts.front().creditAmmount();
      break;
      case 9:
      b.branches.front().accounts.front().getBalance();
      break;
      case 10:
      process=0;
        cout<<"-----------------------"<<endl;
      cout<<"Thank You\n";
        cout<<"-----------------------"<<endl;
      break;
      
    }
  }
  return 0;
  
}
