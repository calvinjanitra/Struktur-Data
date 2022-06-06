#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cin>>n;

    // vector <int> a;
    list <int> a;

    for(int i=0; i<n; i++){
        string cmd;
        cin>>cmd;

        int x;
        if(cmd == "KeBelakang"){
            cin>>x;
            a.push_back(x);

        }else if(cmd == "TaruhDepan"){
            int x;
            cin>>x;

            if(a.empty()){
                a.push_back(x);
            }else{
                a.emplace(a.begin(),x);
            }

        }else if(cmd == "Putar"){
            a.reverse();

        }else if(cmd == "Urgent"){
            if(a.empty()){
                cout<<"Yah Gabut..."<<endl;
            }else{
                int temp = a.front();
                cout<<temp<<endl;
                a.pop_front();
            }
            
        }else if(cmd == "GakPenting"){
            if(a.empty()){
                cout<<"Yah Gabut..."<<endl;
            }else{
                cout<<a.back()<<endl;
                a.pop_back();
            }
        }
    }
    return 0;
}
