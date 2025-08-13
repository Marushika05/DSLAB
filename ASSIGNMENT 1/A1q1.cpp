// dsa assignment 1 ques1
#include <iostream>
using namespace std;
// creating menu
class menu{
    int n,i,num;
    int pos; 
    int arr[100];
    public:

    //create
    void create(){
        cout<<"enter the number of elements in arr:"<<endl;
        cin>>n;
        cout<<"enter the elements: "<<endl;
        for(i=0; i<n; i++){
            cin>>arr[i];
            
        }return;}

    // display
     void display(){
            cout<<"the final array is: "<<endl;
        for(int i=0; i<n; i++){
            cout<<arr[i]<<"\t";
            cout<<endl;
        }
        return;
        }
    
        //insert
    void insert(){
       cout<<"enter the positon to insert: "<<endl;
       cin>>pos;
        cout<<"enter the number to insert: "<<endl;
       cin>>num;
       for(i=n; i>=pos; i--){
        // shifting array to a bigger one and using i=n kyunki size inc krna and 
        //>= taanki current wala element bhi shift hojaye instead of delete 
        arr[i]=arr[i-1];
       }
       arr[pos-1]=num;
        n++;
       
       for(int i=0; i<n; i++){
            cout<<arr[i]<<"\t"<<endl;
        }
        return;
    }  
   // delete

    void deleteElm(){
       cout<<"enter the positon to delete: "<<endl;
       cin>>pos;
       
       for(i=pos-1; i<n-1; i++){
        arr[i]=arr[i+1];
        
       }
       n--;
       for(int i=0; i<n; i++){
            cout<<arr[i]<<"\t"<<endl;
        }
        return;
    }  
        
};
int main() {
    menu m;
   // m.create();
    // m.display();
    // m.insert();
    // m.deleteElm();
    int choice;

    while (true) {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Create Array" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Insert Element" << endl;
        cout << "4. Delete Element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            m.create();
             m.display();
            break;
        case 2:
            m.display();
            break;
        case 3:
            m.insert();
             m.display();
            break;
        case 4:
            m.deleteElm();
            m.display();
            break;
        case 5:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}