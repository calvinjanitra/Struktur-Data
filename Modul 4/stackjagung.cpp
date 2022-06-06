#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[]){
    list <int> a,a1;
    list <int> b,b1;

    int n;
    int maxJagung;
    int jA, jB;
    int x;
    int temp;
    int count;

    cin>>n;

    while(n--){
        cin>>maxJagung;
        cin>>jA>>jB;

        for(int i = 0; i < jA; i++){
            cin>>x;
            a.push_back(x);
            a1.push_back(x);
        }
        for(int i = 0; i < jB; i++){
            cin>>x;
            b.push_back(x);
            b1.push_back(x);
        }

        count = 0;
        temp = 0;
        for(int i = 0; i < jA + jB; i++){
            if(a.front() < b.front()){
                if(temp + a.front() <= maxJagung){
                    count++;
                    temp += a.front();
                    a.pop_front();
                }else{
                    break;
                }
            }else if(a.front() > b.front()){
                if(temp + b.front() <= maxJagung){
                    count++;
                    temp += b.front();
                    b.pop_front();
                }else{
                    break;
                }
            }else if(a.front() == b.front()){
                if(temp + a.front() <= maxJagung){
                    count++;
                    temp += a.front();
                    a.pop_front();
                }else{
                    break;
                }
            }
        }
        cout<<count<<" Jahong"<<endl;

        if(count == 0){ //GENAP
            cout<<"Keciaaan :<"<<endl;
        }else if(count % 2 == 0){ //GENAP
            if(a1.empty()){
                cout<<"Gak ada nih!"<<endl;
            }
            while(!a1.empty()){
                if(a1.front() % 2 == 0){
                    cout<<a1.front()<<" ";
                    a1.pop_front();
                }else{
                    a1.pop_front();
                }
            }
            cout<<endl;
        }else if(count % 2 == 1){ //GANJIL
            if(b1.empty()){
                cout<<"Gak ada nih!"<<endl;
            }
            while(!b1.empty()){
                if(b1.front() % 2 == 1){
                    cout<<b1.front()<<" ";
                    b1.pop_front();    
                }else{
                    b1.pop_front();
                }
            }
            cout<<endl;
        }
    }


    // cout<<a.front()<<" "<<b.front();
    return 0;
}
