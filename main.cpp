#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

//using namespace std;
const std::vector<std::string> vyrGalunes {"as","is","ys","us"};
const std::vector<std::string> vyrReplace {"ai","i","y","au"};
const std::vector<std::string> sveik_ {"Sveikas, ","Sveika, ","Sveiki, "};
bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
int main()
{
    std::cout<<"Iveskite savo varda: ";
    std::string vardas{};
    std::cin>>vardas;
    system("cls");
    std::ifstream f1("vyr_vardai.txt");
    auto v = false;
    std::string temp{};
    while( !f1.eof() )
    {
        f1>>temp;
        if(temp==vardas)
        {
            v=true;
            break;
        }
    }
    auto m = false;
    if(!v)
    {
        std::ifstream f1("mot_vardai.txt");
        while( !f1.eof() )
        {
            f1>>temp;
            if(temp==vardas)
            {
                m=true;
                break;
            }
            f1.close();
        }
    }
    else
    {
        for(int k=0; k<vyrGalunes.size(); k++)
        {
            if(ends_with(vardas,vyrGalunes[k]))
            {
                v=true;
                vardas.erase(vardas.end()-2,vardas.end());
                vardas.append(vyrReplace[k]);
                break;
            }
        }
    }
    auto n{vardas.length()};
    auto g=8;
    if(v)g++;
    for( int i = 0; i<vardas.length()+g+4; i++)
    {
        std::cout<<"*";
    }
    std::cout<<std::endl;
    for(int j =0; j<3; j++)
    {
        std::cout<<"* ";
        if(j!=1)
        {
            for( int i = 0; i<vardas.length()+g; i++)
            {
                std::cout<<" ";
            }
        }
        else
        {
            if(v)std::cout<<sveik_[0];
            else if(m)std::cout<<sveik_[1];
            else std::cout<<sveik_[2];
            vardas[0] = toupper(vardas[0]);
            std::cout<<vardas;
        }
        std::cout<<" *"<<std::endl;
    }

    for( int i = 0; i<4+vardas.length()+g; i++)
    {
        std::cout<<"*";
    }
    return 0;
}
