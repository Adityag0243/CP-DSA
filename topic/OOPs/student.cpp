#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)    //for(int i=0;i<n ;i++) ki jagah   l(i,0,n) likhane se kaam ho jayega 



class Student{
    string id;
    string name;
    string department;
    int semester;
    int sem1marks[5];
    int sem2marks[5];

    public:
        Student(){
            id="NA";
            name="NA";
            department="NA";
            semester=0;
            sem1marks[5];
            sem2marks[5];
        }
        void nameinput(string str){
            this->name=str;
        }
        string show_name(){
            return this->name;
        }

        void id_input(string id_number){
            this->id=id_number;
        }
        string show_id(){
            return this->id;
        }

        void set_department(int num){
            if(num>5 || num<1){
                cout<<"Please enter number between 1 to 4 for setting department.\n1.CSE\n2.MNC\n3.Mechanical\n4.Electrical";
                return;
            }else{
                if(num==1) this->department="CSE";
                else if(num==2) this->department="MNC";
                else if(num==3) this->department="Mechanical";
                else this->department="Electrical";
            }
        }
        string show_department(){
            return this->department;
        }

        void set_sem1marks(int arr[5]){
            l(i,0,5){
                this->sem1marks[i]=arr[i];
            }
        }

        void show_sem1marks(){
            l(i,0,5){
                cout<<this->sem1marks[i]<<" ";
            }
            cout<<endl;
        }

};

int main(){
    Student a;
    a.nameinput("Aditya");    // ab yaha tm manually dalane ke bajay ek variable leke cin krke phir variable daal skte the, see for id
    string id_variable;     //ye variable me keyboards se input lunga
    cout<<"Enter id: ";
    cin>>id_variable;
    a.id_input(id_variable);   // ab directly string daalane ke bajay vo variable daal diya
    a.set_department(2);

    int marks[]={35,32,42,28,23};
    a.set_sem1marks(marks);     // giving input as a array of all 5 subjects

    cout<<a.show_name()<<endl;
    cout<<a.show_id()<<endl;
    cout<<a.show_department()<<endl;   // ye return kr rha hai isliye cout krna pad rha hai
    a.show_sem1marks();   // isko call krung to wahi se print kra dega (iske liye return krne wale na krne wale function me ntar pata hona chahiye)


}