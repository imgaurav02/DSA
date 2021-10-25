#include<bits/stdc++.h>

using namespace std;

class MPS{
    private:
        string name;
        long long salary;
        string constituency;
        string veichle;
        string position;
        bool arrest;
    public:
    void setData(string name,long long salary,string constituency,string position,string veichle){
        this->name = name;
        this->salary = salary;
        this->constituency = constituency;
        this->veichle = veichle;
        this->position = position;
        arrest = 0;
    }
    void showData(){
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Constituency: "<<constituency<<endl;
        cout<<"Position: "<<position<<endl;
        cout<<"Veichle Have: "<<veichle<<endl<<endl;
        
    }
    bool spend(int ammount){
        
        salary = salary - ammount;
        if(salary < 0){
            return 0;
        }
        return 1;
        
    }

    void commisnor(MPS PM){
        cout<<endl<<"Hello I am Commisnor You Have Spend more than You salary You may be arrested..."<<endl<<endl;
        if(position != PM.position){
            if(position == "minister"){
                cout<<"Calling PM Please Wait..."<<endl<<endl;
                if(isAllowed()){
                    cout<<"You are arrested..."<<endl<<endl;
                    arrest = 1;
                }
                else{
                    cout<<"PM denied to arrest his spend limit again set 1 lac"<<endl<<endl;
                    salary = 100000;
                }
            }
            else{
                cout<<"You are arrested..."<<endl<<endl;
                arrest = 1;
            }
        }
        else{
            cout<<"I can't do anything He is PM and spend limit again set to 1 cores"<<endl<<endl;
            salary = 10000000;
        }
    }
    bool isAllowed(){
        int otp;
        bool dicision;
        cout<<"Enter the otp PM sir: ";
        cin>>otp;
        if(otp == 12345){
            cout<<"Enter Your Decision PM sir: ";
            cin>>dicision;
            return dicision;
        }
        else
            return 0;
    }
    bool isAllowedToSpend(){
        if(!arrest)
            return 1;
        return 0;
    }

};

int main(){
    int n,i = 0;
    cout<<"How Many Members in Parliament: ";
    fflush(stdin);
    cin>>n;

    int totalMP = n-2;
    MPS PM;
    MPS minister;
    MPS mp[n-2];

   
   
   //always use small case to be on safe side
   




    while(n--)
    {
        fflush(stdin);
        if(i == 0)
            cout<<"Enter the Prime Minister Data: "<<endl<<endl;
        else if(i == 1)
            cout<<"Enter the Ministers Data: "<<endl<<endl;
        else
            cout<<"Enter the MP Data: "<<endl<<endl;
        string name,constituency;
        long long salary;             
        cout<<"Enter Name: "; getline(cin,name);
        fflush(stdin);
        cout<<"Enter Constituency: "; getline(cin,constituency);
        fflush(stdin);
        cout<<"Enter salary: "; cin>>salary;
        if(i == 0)
            PM.setData(name,salary,constituency,"pm","Car Airplane");
        else if(i == 1)
            minister.setData(name,salary,constituency,"minister","Car");
        else
            mp[i-2].setData(name,salary,constituency,"mp","Car");
        i++;
        cout<<"Data Inserted..."<<endl;
    }

       
// this is for my software testing
//    int n =3,totalMP = 1,i;
//    MPS PM;
//    PM.setData("Gaurav Singh",1000,"Kanpur","PM","Car Airplane");
//    MPS minister;
//    minister.setData("Harshit Omar",500,"Kanpur","minister","Car");
//    MPS mp[1];
//    mp[0].setData("Naman Tiwari ",200,"Kanpur","mp","Car");




    i = 1;
    while(i){
    int who;
    fflush(stdin);
    cout<<"Who are you? \n \
        1: if Pm press 1 \n \
        2: if Minister press 2 \n \
        3: if Mp press 3 \n \
        4: if you are none of the above press 4 \n";
    cin>>who;
    int amt;
    bool check;
    switch (who)
    {
    case 1:
        cout<<"Your Details...\n";
        PM.showData();
        cout<<"Enter the money you want spend: ";
        cin>>amt;
        check = PM.spend(amt);
        if(check)
            cout<<"You have Succesfully spended the ammount of Rs." << amt<<" From your Salary: \n";
        else{
            PM.commisnor(PM);
            cout<<"You have Succesfully spended the ammount of Rs." << amt<<" From your Salary: \n";
        }
        break;
    case 2:
        cout<<"Your Details...\n"<<endl;
        minister.showData();
        cout<<"Enter the money you want spend: ";
        cin>>amt;
        if(minister.isAllowedToSpend()){
            check = minister.spend(amt);
            if(check)
                cout<<"You have Succesfully spended the ammount of Rs." << amt<<" From your Salary: \n";
            else{
                minister.commisnor(PM);
            }
        }
        else
            cout<<"You are In Jail... You can't Spend"<<endl<<endl;
        break;

    case 3:
        int id;
        cout<<"Enter You Mp id: "<<endl;
        fflush(stdin);
        cin>>id;
        if(totalMP > id){
            cout<<"Your Details...\n"<<endl;
            mp[id].showData();
            cout<<"Enter the money you want spend: ";
            cin>>amt;
            if(mp[id].isAllowedToSpend()){
                check = mp[id].spend(amt);
                if(check)
                    cout<<"You have Succesfully spended the ammount of Rs." << amt<<" From your Salary: \n";
                else
                    mp[id].commisnor(PM);
            }
            else
                cout<<"You are In Jail... You can't Spend"<<endl<<endl;
        }
        else
            cout<<"You Have Entered Wrong Mp id: "<<endl;
        break;
    case 4:
        i = 0;
        break;
    default:
       break;
    }
    }

    cout<<"Bye Bye Thankyou For Using My Software... \n Devloped By Gaurav Singh";

}