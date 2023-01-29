#include <iostream>
#include <string>
using namespace std;
// a bool variable to check if the item sol d or not in line 193
bool check=false;
//implementation the class item
class Item{
private:
    int id;
    string name ;
    int quantity ;
    double price;
public:
    // static variable to change the id
    static int counter;
    // Empty constructor for initializing values to variables
Item(){
    name="";
    quantity=0;
    price=0;
    counter++;
    id=counter;
}
// parameteraize constructor for set the values to variables
Item(string name,int quantity,double price){
    this->name=name;
    this->quantity=quantity;
    this->price=price;
    counter++;
    id=counter;
}
//Copy constructor to copy a constructor to another
Item(const Item & item) {
        name= item.name;
        id=  item.id;
        quantity=item.quantity;
        price=item.price;

    }
    //Function to set a name to objects

    void setName(string name) {
        this-> name=name;
    }
    //Function to return the name of objects
    string getName() const {
        return name;
    }
    //Function to set rhe quantity to items
    void setQuantity(int quantity) {
        this-> quantity=quantity;
    }
    //Function to return rhe quantity of items
    int getQuantity()const {
        return quantity;
    }
    //Function to set rhe price to items
    void setPrice(double price) {
        this-> price=price;
    }
    //Function to return rhe price of items
    int getPrice()const {
        return price;
    }
    //Function to set rhe id to items
    void setId(int id){
        this->id =id;
    }
    //Function to return rhe id of items
    int getId()const{
        return id;
    }
 // implementation of >> operator to input the values from user
  friend  istream &operator>>( istream & input ,Item & item){
        cout<<"Enter the info in this order"<<endl;
        cout<<" name / Quantity / Price"<<endl;
        cout<<"---------------------------------------------------"<<endl;
        input>>item.name>>item.quantity>>item.price;
        return input;
    }
    // implementation of << operator  to output the values to user
   friend ostream &operator<<(ostream & output, const Item & item){
        output<<"========= Item "<<item.id<<" info ============="<<endl;
        output<<"Name is:  "<<item.name<<endl;
        output<<"Id is:    "<<item.id<<endl;
        output<<"Quantity is:   "<<item.quantity<<endl;
        output<<"Price is:  "<<item.price<<endl;
        output<<"-------------------------------------------------"<<endl;
        return output;
    }
    // implementation of == operator to check if the obj1 equal obj2 or not
    bool Item::operator==(const Item & item) {
        return name==item.name;
    }

// implementation of += operator to add quantity to the item
  int  Item::operator+=(int x){
    quantity+=x;
    return quantity;
}
// implementation of -= operator to Subtract quantity from the item

    int  Item::operator-=(int x){
        quantity-=x;
        return quantity;
    }



};
// implementation of class Seller
class Seller{
private:
    string name ;
    string email ;
    int  maxItems;
    Item *items;
    int  itemCounter=0;
public:

    Seller(){
        name ="";
        email="";
        maxItems=0;
        //create dynamic array of class Item
        items=new Item[maxItems];
    }
    // parametrize constructor to set values to a variables
    Seller(string name ,string email,int maxItems){
        this->name=name;
        this->email=email;
        this->maxItems=maxItems;
        items=new Item[maxItems];
    }
    //Function to set rhe max item can he sell
    void setMaxItem(int maxItems){
        this->maxItems=maxItems;
        items=new Item[maxItems];

    }
    // implementation of >> operator to take the values from user
    friend  istream &operator>>( istream & input ,Seller & seller){
        cout<<"Enter the info in this order"<<endl;
        cout<<" name / email "<<endl;
        cout<<"---------------------------------------------------"<<endl;
        input>>seller.name>>seller.email;


        return input;
    }
    // implementation of << operator  to output the values to user
    friend ostream &operator<<(ostream & output, const Seller & seller){
        output<<"=================================================== "<<endl;

        output<<"The name of the seller  is:  "<<seller.name<<endl;
        output<<"The email of the seller is:   "<<seller.email<<endl;
        output<<"Max items can he sell is:  "<<seller.maxItems<<endl;
        output<<"-------------------------------------------------"<<endl;
        return output;
    }
    // function to add item to the seller
    bool addItem(Item &item){
        // loop to check if the item founded or not
        for (int i = 0; i <= itemCounter; ++i) {
            if(items[i]==item){
               items[i]+=item.getQuantity();

                return true;
            }

        }
// if the item was not found this if statement check if the object have memory to add new item or not
            if(itemCounter>=maxItems){
                return  false;
            }
            else{
                items[itemCounter]=item;
                items[itemCounter].setId(itemCounter+1);
                itemCounter++;
                return true;
            }


    }
    // function to sell an item
    bool sellItem(string name,int quantity){
        // loop to check if the item founded or not
        for (int i = 0; i <= itemCounter; ++i) {
            if (name == items[i].getName()) {
                if (quantity <= items[i].getQuantity()) {
                    items[i] -= quantity;
                    // check true if he sell the item
                    check=true;
                    return true;


                }
                else{
                    cout<<"There is only {"<<items[i].getQuantity()<<"} left for this item"<<endl;

                    return true;

                }
            }
        }
        return false;
    }
    //function to print items in the seller's possession
    void printItems(){
        for (int i = 0; i < itemCounter; ++i) {
            cout<<items[i]<<endl;
        }
    }
    //function to find an item by his id
    Item* searchItem(int id){
        for (int i = 0; i < itemCounter; ++i) {
            if(items[i].getId()==id){
                cout<<items[i]<<endl;
                return &items[i];
            }
        }
        return nullptr;
    }
    // destructor to delete the array

    ~Seller(){
        delete [] items;
    }
};

int Item::counter = 0;
void menu();

int main() {
    //

       Seller s1;
       cin>>s1;
       cout<<"Enter your store capacity: ";
       int capacity;
       cin>>capacity;
       s1.setMaxItem(capacity);



       // bool variable if he true the program will end
    bool b= false;

    int choice;
    while (true) {
        if(b){
            break;
        }
        menu();
        cin>>choice;
        // switch statement to make order of user
        switch (choice) {
            // If he chooses 1, he will print his personal data
            case 1: {
                cout << s1;
                break;
            }
            //If he chooses 2, he will add item to his store
            case 2:
            {
                Item i1;
                cin>>i1;
                // this will take the object and add this if can do this
                if(s1.addItem(i1)){
                cout<<"successful addition of item"<<endl;
                }
                else{

                    cout<<"Capacity Full!! "<<endl;
                }
                break;
            }
                //If he chooses 3, he will sell item from his store
            case 3:
            {

                Item i2;
                string nameItem;

                cout<<"enter the name and the  quantity will you sell: ";
                int quantity;
                cin>>nameItem>>quantity;
                // It will take this name and quantity and sell the item if it is found and has enough quantity
                if(s1.sellItem(nameItem,quantity)){
                    if(check){
                        cout<<"The Item has been sold successfully"<<endl;
                    }

                }
                else{
                    cout<<"Item was not found"<<endl;
                }
                break;
            }
             //If he chooses 4 the program will print his items
            case 4:
            {
                s1.printItems();
                break;
            }
          //If he chooses 5, he will search about item by ID
            case 5:
            {
                int id;
                cout<<"Enter the id"<<endl;
                cin>>id;
                s1.searchItem(id);
                break;
            }
                //If he chooses 6 the program will Exit
            case 6:
            {
                b= true;
                break;
            }

            default:
                b=false;
        }



    }



    return 0;
}
//function to print the menu
void menu(){
    cout<<"1. Print My Info."<<endl
         <<"2. Add An Item."<<endl
         <<"3. Sell An Item."<<endl
         <<"4. Print Items."<<endl
         <<"5. Find an Item by ID"<<endl
         <<"6. Exit"<<endl;
}