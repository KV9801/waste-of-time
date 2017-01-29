#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void donor();
//void NGO();
void Newlogin();

class login
{
public:
void logi ();

};

void login::logi()
{
int choice;
return1:
cout<<"Login as: \n1.Donor\n2.NGO\n3.New login\n";
cin>>choice;
switch(choice)
{
case 1:
donor();
break;
case 2:
//NGO();
break;
case 3:
Newlogin();
break;
default:
cout<<"Error\n";
goto return1;
break;
}
}

void donor()
{
   ifstream infile;
   unsigned int curline=0;
   string line;
   char* search;
    cout<<"Enter the username:";
    cin>>search;
    infile.open("dname.dat");
    if (infile.is_open())
    {
        while(getline(infile,line))
        {
            curline++;
            if(line.find(search,0)!= string::npos)
        {
          cout<<"found"<<search<<"line:"<<curline<<endl;
        }
        }
        infile.close();
    }

    cout << "invalid Username";
}

void Newlogin()
{
int b;
return2:
cout<<"Register as 1.Donor or 2.NGO\n";
cin>>b;
cin.ignore();
switch(b)
{
case 1:
{
    char name[100],pass[100];
    ofstream outfile,outfile1;

    outfile.open("dname.dat", ios::ate|ios::app);
    cout<<"\nName:";
    cin.getline(name,100,'\n');
    outfile<<name<<endl;
    outfile.close();

    outfile1.open("dpass.dat", ios ::ate|ios::app);
    cout<<"\nPassword:";
    cin.getline(pass,100,'\n');
    outfile1<<pass<<endl;
    outfile1.close();

};
break;
case 2:
{
    char name[100],pass[100];
    ofstream outfile,outfile1;

    outfile.open("nname.dat", ios::ate|ios::app);
    cout<<"\nName:";
    cin.getline(name,100,'\n');
    outfile<<name<<endl;
    outfile.close();

    outfile1.open("npass.dat", ios ::ate|ios::app);
    cout<<"\nPassword:";
    cin.getline(pass,100,'\n');
    outfile1<<pass<<endl;
    outfile1.close();

};
break;
default:
cout<<"Error";
goto return2;
break;
}
}

int main ()
{
cout<<"Hello\n";
login m;
m.logi();
return 0;
}



