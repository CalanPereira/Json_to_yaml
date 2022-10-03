#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>

using namespace std;

int main()
{
    ifstream file;
    string filename;
    cin>>filename;

    file.open(filename);

    if(file.fail())
    {
        cout<<"File Failed to open."<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"---\n\n";
    string line;
    string space="";
    int squarebracketscount=0,f=1;
    while(!file.eof())
    {
        getline(file,line);
        if(line.size()==0)continue;
        if(line.size()>1 && line[line.size()-1]=='}' || line[line.size()-2]=='}')
        {
            cout<<"\n\n";
            space.pop_back();
            space.pop_back();
        }
        else if(line[0]!='{' && line[0]!='}')
        {
            if(f)
             cout<<space;//<<space.size();
             f=1;
             for(char c:line)
             {
                if(c=='[')
                {
                    squarebracketscount++;
                    space+=" ";
                    cout<<'\n';
                }
                else if(c=='{' && squarebracketscount>0)
                {
                    cout<<"- ";
                    f=0;
                    space+="  ";
                }
                else if(c==']')
                space.pop_back(),squarebracketscount--;
                else if(c==',')
                    cout<<'\n';
                else if(c==':')
                    cout<<": ";
                else if(!isspace(c) && c!='"')
                    cout<<c;
             }
        }
    }

    return 0;
}
