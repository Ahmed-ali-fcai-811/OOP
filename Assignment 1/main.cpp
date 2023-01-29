
/*
    Authors
    1- Ahmed Ali Ali Mahmoud
    2- Mohamed Abdelaal Mahmoud Abdelaal
*/
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
/* function to change a color of output*/
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
class ColoredBox {
private:
    int len;
    int wid;
    int color1 = 15;
    int color2 = 15;
    char boxChar = '#';
    int area;
    char** box;

public:
    static int maxArea;

    void setBox() {
        box = new char* [len];
        for (int i = 0; i < len; ++i) {
            box[i] = new char[wid];
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < wid; ++j) {
                box[i][j] = boxChar;
            }
        }
    }
    /////////////////////////////

    ColoredBox() {
        len = 0;
        wid = 0;
        ///////////////
        color1 = 15;
        color2 = 15;
        //////////////
        boxChar='#';
        ///////////
        area = 0;


    }

    /////////////////////////////////////

    ColoredBox(int len, int wid) {
        this->len = len;
        this->wid = wid;
        ////////////////////////////////////////
        setBox();
    }
    //////////////////////////////////////////////
    void setColor(int color1) {
        this->color1 = color1;
    }
    void setChar(char boxChar) {
        this->boxChar = boxChar;
    }
   int  getColor() {
        return color1;
    }
    char getChar() {
        return boxChar;
    }

    /////////////////////////////////////////
    ColoredBox(int len, int wid, int color1, char boxChar) {
        this->len = len;
        this->wid = wid;
        this->color1 = color1;
        this->boxChar = boxChar;
        /////////////////////////////////////////
        setBox();
    }
    ////////////////////////////////////////////
    void display() {
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < wid; ++j) {
                SetColor(color1);
                cout << box[i][j];
            }
            cout << endl;
        }
        SetColor(15);
    }

    ////////////////////////////////////////
    void  displayTransposed() {
        for (int i = 0; i < wid; ++i) {
            for (int j = 0; j < len; ++j) {
                SetColor(color1);
                cout << box[j][i];
            }
            cout << endl;
        }
        SetColor(15);
    }
    //////////////////////////////////////////////

    void displayWider() {
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < wid; ++j) {
                SetColor(color1);
                cout << box[i][j] << "  ";
            }
            cout << endl;
        }
        SetColor(15);
    }
    ////////////////////////////////////////////////////////
    void displayChess(int color2) {
        this->color2 = color2;

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < wid; ++j) {
                if((j+i)&1) {
                    SetColor(color2);
                }else{
                    SetColor(color1);
                }
                cout << box[i][j];
            }
            cout << endl;
        }
        SetColor(15);

    }
    /////////////////////////////////////////////////
    void setArea() {
        area = wid * len;
       maxArea = max(maxArea,area);
    }
    //////////////////////////////////////////////////////
    int getArea() {
        setArea();
        return area;
    }
    //////////////////////////////////////////////////////
   static  int getMaxArea() {
        return maxArea;
    }
    /////////////////////////////////////////////////////
    ~ColoredBox() {
        delete[]box;
    }

};
/////////////////////////////////
int ColoredBox::maxArea = 0;

////////////////////////////////
int main() {

    int len, wid, col, col2;
    char boxChar;
    cout << "Enter length and width of the box separated by a space: ";
    cin >> len >> wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len, wid);
    cb1->display();
    cout << "Set the box to another color: ";
    cin >> col;
    cb1->setColor(col);
    cout << "Displaying Transposed: " << endl;
    cb1->displayTransposed();
    cout << "Displaying Wider: " << endl;
    cb1->displayWider();
    cout << "Displaying Chess, enter the other color: " << endl;
    cin >> col2;
    cb1->displayChess(col2);
    cout << endl << "Area=" << cb1->getArea();
    cout << endl << "Max Area=" << cb1->getMaxArea() << endl;
    delete cb1;
    cout << "Enter length,width,color,character of the box separated by spaces: ";
    cin >> len >> wid >> col >> boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len, wid, col, boxChar);
    cb2->display();
    cout << "Displaying Transposed: " << endl;
    cb2->displayTransposed();
    cout << "Displaying Wider: " << endl;
    cb2->displayWider();
    cout << "Displaying Chess, enter the other color: " << endl;
    cin >> col2;
    cb2->displayChess(col2);
    cout << "Displaying original again:" << endl;
    cb2->display();
    cout << endl << "Area=" << cb2->getArea();
    cout << endl << "Max Area=" << cb2->getMaxArea();
    delete cb2;
    return 0;


}
