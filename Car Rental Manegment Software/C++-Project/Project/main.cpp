#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip>
#include<ios>
#include <cstdio>
using namespace std;
const int x=20;
class renter{
public:
   string id;
   string name;
   string age;
   string gender;
   string license;

};
renter renters[x];
class cars{
public:
    string car_model ,lic_num,owner,renter_name;
    //int m=7 ,n=7;
//string arr[7][6];
};
const int k =30;
cars arr2 [k];


void add_data_renter_array(){
    string filename;
filename = "renter.csv.txt";
 fstream fs;
fs.open(filename);
int new_line =2;
int record_size =54+new_line;
 fs.seekg(0, ios::end);
long nrecord=fs.tellg()/record_size;
int pos ;

    string id , name  , age , gender , license;
cout<<"enter the data you want to add if you want to skip any just click 0 /n"<<endl;
cout<<"enter the id you want to add/n"<<endl;
cin>>id;
cout<<"enter the name you want to add/n"<<endl;
cin>>name;
cout<<"enter the age you want to add/n"<<endl;
cin>>age ;
cout<<"enter the gender you want to add/n"<<endl;
cin>>gender;
cout<<"enter the license name you want to add/n"<<endl;
cin>>license;
renters [nrecord+1].id=id;
    renters [nrecord+1].name=name;
    renters [nrecord+1].age=age;
    renters [nrecord+1].gender=gender;
      renters [nrecord+1].license=license;
fs.seekp(0, ios::end);
 if (fs.is_open()){
fs<<endl<<setw(11)<<id<<setw(12)<<name<<setw(9)<<age<<setw(10)<<gender<<setw(11)<<license;
 fs.close();
}else cout<<"couldnot find file"<<endl;
}

void add_data_cars_array(){
    string filename;
filename = "cars.csv.txt";
 fstream fs;
fs.open(filename);
int new_line =2;
int record_size =56+new_line;
 fs.seekg(0, ios::end);
long nrecord=fs.tellg()/record_size;
int pos ;

    string car_model , lic_num , owner , renter_name;
cout<<"enter the data you want to add if you want to skip any just click 0 /n"<<endl;
cout<<"enter the car model you want to add/n"<<endl;
cin>>car_model;
cout<<"enter the license number you want to add/n"<<endl;
cin>>lic_num;
cout<<"enter the owner you want to add/n"<<endl;
cin>>owner;
cout<<"enter the renter name you want to add/n"<<endl;
cin>>renter_name;
arr2[nrecord+1].car_model=car_model;
    arr2[nrecord+1].lic_num=lic_num;
    arr2[nrecord+1].owner=owner;
    arr2[nrecord+1].renter_name=renter_name ;
fs.seekp(0, ios::end);
 if (fs.is_open()){
fs<<endl<<setw(9)<<car_model<<setw(17)<<lic_num<<setw(16)<<owner<<setw(16)<<renter_name;
 fs.close();
}else cout<<"couldnot find file"<<endl;
}

void export_car_data(){

ofstream inputdata;
inputdata.open("cars.csv.txt");
inputdata.seekp(0, ios::end);
for(int i=1;i<20;i++)
{
 if (inputdata.is_open()){
inputdata<<endl<<setw(11)<<arr2[i].car_model<<setw(21)<<arr2[i].lic_num<<setw(14)<<arr2[i].owner
<<setw(13)<<arr2[i].renter_name;
}
}inputdata.close();}

void remove_data_from_cars(){
     string car_model ;
    string lic_num ;
    string owner ;
    string renter_name ;
     string filename;
       string line;
filename = "cars.csv.txt";
 fstream fs;
fs.open(filename);
int new_line =2;
int record_size =58+new_line;
 fs.seekg(0, ios::end);
long nrecord=fs.tellg()/record_size;
 int z;
cout <<nrecord<<endl;
   cout<<"enter the row of data you want to remove from (0,"<<nrecord-1<<")"<<endl;
cin>>z;
fs.seekg(z*record_size, ios::beg);
cout<<fs.tellg() <<endl;

for (int y=z ; y<nrecord;y++){
while(getline(fs,line)){

    string car_model = line.substr(0, 10);
    string lic_num = line.substr(10,17);
    string owner = line.substr(27,16);
    string renter_name = line.substr(47,14);
    arr2[y].car_model=car_model;
    arr2[y].lic_num=lic_num;
    arr2[y].owner=owner;
    arr2[y].renter_name=renter_name ;

   cout<<endl<<setw(9)<<car_model<<setw(17)<<lic_num<<setw(16)<<owner<<setw(16)<<renter_name;
}}

fs.close();

}


void remove_data_from_renters(){
    string id ,name,age,gender,license;
     string filename;
       string line;
filename = "renter.csv.txt";
 fstream fs;
fs.open(filename);
int new_line =2;
int record_size =52+new_line;
 fs.seekg(0, ios::end);
long nrecord=fs.tellg()/record_size;
 int z;
cout <<nrecord<<endl;
   cout<<"enter the row of data you want to remove from (0,"<<nrecord-1<<")"<<endl;
cin>>z;
fs.seekg(z*record_size, ios::beg);
cout<<fs.tellg() <<endl;
int st=0;
    while(!fs.eof()){
    getline(fs,id,',');
    getline(fs,name,',');
    getline(fs,age,',');
    getline(fs,gender,',');
    getline(fs,license,'\n');

    renters[st].id=id;
    renters[st].name=name;
    renters[st].age=age;
    renters[st].gender=gender;
    renters[st].license=license;
    st++;
    cout<<id<<name<<age<<gender<<license<<endl;
    }



 fs.close();
}

void readcars( ){ ifstream in ;
in.open("cars.csv.txt");
int y=0;
    string line;
     if (in.is_open()){
    while(getline(in,line)){

    string car_model = line.substr(0, 11);
    string lic_num = line.substr(11,21);
    string owner = line.substr(32,14);
    string renter_name = line.substr(46,12);
    arr2[y].car_model=car_model;
    arr2[y].lic_num=lic_num;
    arr2[y].owner=owner;
    arr2[y].renter_name=renter_name ;
    y++;
    cout<<car_model<<lic_num<<owner<<renter_name<<endl;}
  in.close();
}else cout<<"couldn't find file"<<endl;  }


void read_ren_cars( ){ ifstream in ;
in.open("cars.csv.txt");
int y=0;
    string line;
     if (in.is_open()){
    while(getline(in,line)){

    string car_model = line.substr(0, 11);
    string lic_num = line.substr(11,21);
    string owner = line.substr(32,14);
    string renter_name = line.substr(46,12);
    arr2[y].car_model=car_model;
    arr2[y].lic_num=lic_num;
    arr2[y].owner=owner;
    arr2[y].renter_name=renter_name;
    if (arr2[y].renter_name != "  not rented")
    cout<<car_model<<lic_num<<owner<<renter_name<<endl;
    y++;}
  in.close();
}else cout<<"couldn't find file"<<endl;  }



void read_av_cars( ){ ifstream in ;
in.open("cars.csv.txt");
int y=0;
    string line;
     if (in.is_open()){
    while(getline(in,line)){

    string car_model = line.substr(0, 11);
    string lic_num = line.substr(11,21);
    string owner = line.substr(32,14);
    string renter_name = line.substr(46,12);
    arr2[y].car_model=car_model;
    arr2[y].lic_num=lic_num;
    arr2[y].owner=owner;
    arr2[y].renter_name=renter_name;
    if (arr2[y].renter_name == "  not rented")
    cout<<car_model<<lic_num<<owner<<renter_name<<endl;
    y++;}
  in.close();
}else cout<<"couldn't find file"<<endl;  }



void importfile ()
{
    ifstream inputdata;
    inputdata.open("renter.csv.txt");
     if (inputdata.is_open()){
    string id ,name,age,gender,license;
    int st=0;
    while(!inputdata.eof()){
    getline(inputdata,id,',');
    getline(inputdata,name,',');
    getline(inputdata,age,',');
    getline(inputdata,gender,',');
    getline(inputdata,license,'\n');

    renters[st].id=id;
    renters[st].name=name;
    renters[st].age=age;
    renters[st].gender=gender;
    renters[st].license=license;
    st++;
    cout<<id<<name<<age<<gender<<license<<endl;
    }
 inputdata.close();
}else cout<<"couldn't find file"<<endl;
}

void rent_car(){
    string l;
    cout << "Enter the license of the car: "<< endl;
    cin >> l;
    ifstream in ;
in.open("cars.csv.txt");
int y=0;
    string line;
     if (in.is_open()){
    while(getline(in,line)){

    string car_model = line.substr(0, 11);
    string lic_num = line.substr(21,5);
    string owner = line.substr(32,14);
    string renter_name = line.substr(46,12);
    arr2[y].car_model=car_model;
    arr2[y].lic_num=lic_num;
    arr2[y].owner=owner;
    arr2[y].renter_name=renter_name ;
    if(arr2[y].lic_num == l){
     if (arr2[y].renter_name == "  not rented"){
    cout<<car_model<<lic_num<<owner<<renter_name<<endl;
    cout << "Enter the renter name: "<< endl;
    string n;
    cin >> n;
    arr2[y].renter_name = n;}
    else
        {cout << "Car not available right now"<<endl; break;}

    }
    y++;
    }


}}


int main()
{ cout<<"please choose an option"<<endl<<"1-import/export renters data "<<endl<<"2-import/export cars data"<<endl
    <<"3-add/remove car data"<<endl<<"4-add/remove reneter data"<<endl<<"5-list of available cars/list of rented cars"<<endl<<"6-rent a car"<<endl;
    int x;
    cin>>x;
    if(x==1){
        cout<<"to import data choose 1 / to export data choose 2"<<endl;
        int y;
        cin>>y;
        if(y==1){
        importfile ();
        }else if(y==2){
        void export_renter_data(renter renters[20]);
        }
    }

    if(x==2){
        cout<<"to import data choose 1 / to export data choose 2"<<endl;
        int z;
        cin>>z;
        if(z==1){
            readcars( );
        }

}

    if(x==3){
        cout<<"to add data choose 1 / to remove data choose 2"<<endl;
        int l;
         cin>>l;
        if(l==1){
           add_data_cars_array();
        }else if (l==2)
        {
            remove_data_from_cars();
        }


    }

        if(x==4){
        cout<<"to add data choose 1 / to remove data choose 2"<<endl;
        int m;
        cin>>m;
        if(m==1){
           add_data_renter_array();
        }
        if(m==2){
            remove_data_from_renters();
        }
    }

          if(x==5){
        cout<<"to read available cars choose 1 / to read rented cars choose 2"<<endl;
        int n;
        cin>>n;
        if(n==1){
           read_av_cars( );
        }else if (n==2)
        read_ren_cars( );
    }
     if(x==6){
    rent_car();
}
}




