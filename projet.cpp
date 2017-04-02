#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class functionality
{
protected:
         char name[100],pass[100],name1[100],pass1[100];
         int c;
       //  void encryption();
public:
    void newlogin(string,string);
    void login(string,string);
    int check(string);

};
void functionality::newlogin(string filename,string filepass)
{
     ofstream outfile,outfile1;
    outfile.open(filename.data(), ios::ate|ios::app);
    back:
    cout<<"\nName:";
    cin.getline(name,100,'\n');
    check(name);
    if(c==0) goto back;
    ifstream infile1;
    unsigned int curline1=0;
    string line1;
    infile1.open(filename.data());
    if (infile1.is_open())
    {

        while(getline(infile1,line1))
        {
            curline1++;
            if(line1.find(name,0)!= string::npos)
        {
             if(line1.compare(name) == 0)
           {
          cout<<"Username already exists."<<endl;
          infile1.close();
          goto back;
            }
        }
}
}

        outfile<<name<<endl;
        outfile.close();

        outfile1.open(filepass.data(), ios ::ate|ios::app);
        cout<<"\nPassword:";
        cin.getline(pass,100,'\n');
        outfile1<<pass<<endl;
        outfile1.close();
    }

void functionality::login(string filename,string filepass)
{
        int flag1;
   ifstream infile,infile1;
   unsigned int curline=0;
   string line;
   char search1[100];
   back1:
    cout<<"Enter the username:";
     cin.getline(search1,100,'\n');
     check(search1);
     if (c==0) goto back1;
    infile.open(filename.data());
    if (infile.is_open())
    {
        while(getline(infile,line))
        {
            curline++;
            if(line.find(search1,0)!= string::npos)
        {
             if(line.compare(search1) == 0)
           {
          cout<<"found "<<search1<<"line: "<<curline<<endl;
          char pass1[100];
          cout<<"Enter password:";
         cin.getline(pass1,100,'\n');
          string line1;
          unsigned int curline1=0;
          ifstream infile1;
          infile1.open(filepass.data());
          if(infile1.is_open())
          {
             while(getline(infile1,line1))
             {
                 curline1++;
                 if(curline1==curline)
                 {
                     if(line1.compare(pass1) == 0)
                     {
                         cout<<"Welcome to our World;";
                         flag1=1;
                         goto end1;
                     }

                     else
                        {
                        cout<<"Wrong login";
                     flag1=1;
                    goto end1;
                     }

                 }
             }
          }
           }
        }
else flag1=0;
        }
        infile.close();
    }
    end1:
if (flag1==0)
    cout<<"Wrong username";
}
int functionality::check(string check1)
{
    if (check1.find(' ') != std::string::npos)
{
    cout<<"Enter data without space.\n";
    return c=0;
}
else return c=1;
}
class donor:public functionality
{
protected:
    string filename,filepass;
    public:
    string sendname();
    string sendpass();

};
string donor::sendname()
{
    string filename("dname.dat");
    return(filename);
}
string donor::sendpass()
{
    string filepass("dpass.dat");
    return(filepass);
}
class ngo:public functionality
{
protected:
    string filename1,filepass1;
    public:
    string sendname1();
    string sendpass1();

};
string ngo::sendname1()
{
    string filename1("nname.dat");
    return(filename1);
}
string ngo::sendpass1()
{
    string filepass1("npass.dat");
    return(filepass1);
}
int main()
{
    int choice,n,m;
    donor d;
    ngo ng;
    return1:
cout<<"Login/Register as: \n1.Donor\n2.NGO\n";
cin>>choice;
cin.ignore();
switch(choice)
{
case 1:
{
    cout<<"\n1.Login\n2.Register-\n";
    cin>>n;
    cin.ignore();
    if(n==1)
    {
       d.login(d.sendname(),d.sendpass());

    }
        else if(n==2)
        {
          d.newlogin(d.sendname(),d.sendpass());
        }
        else cout<<"Error";
        break;
    }
break;
case 2:
{
    cout<<"\n1.Login\n2.Register-\n";
    cin>>n;
    cin.ignore();
    if(n==1)
    {
       ng.login(ng.sendname1(),ng.sendpass1());

    }
        else if(n==2)
        {
          ng.newlogin(ng.sendname1(),ng.sendpass1());
        }
        else cout<<"Error";
        break;
    }
break;
default:
cout<<"Error\n";
goto return1;
break;
}
}
