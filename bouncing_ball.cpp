/* todo list
- change the ball into slashes
- custom-sized board current size is (22 x 17)
*/

#include <iostream>
#include <windows.h> //goodbye unix user
using namespace std;

struct coords{
    int x, y;
};

void printHorizontalBorder();
void detectBorder(coords location, coords& direction);

int main() {
    coords location;
    location.x = 0;
    location.y = 0;

    coords direction;
    direction.x = 1; //1 means down, -1 means up
    direction.y = 1; //1 means right, -1 means left

    while(true){
        //the upper part
        printHorizontalBorder();

        //if location happens to be near border, the direction will be changed
        detectBorder(location, direction);

        //determine where the object is gonna go next
        location.x += direction.x;
        location.y += direction.y;

        //the square part
        //making the iteration start at 1 so it will correlate nicely with the numbers inside detectBorder
        for (int y = 1; y <= 15; y++){
            cout << "]";
            for (int x = 1; x <= 20; x++){
                if (y == location.y && x == location.x)
                    cout << "O";
                else
                    cout << " ";
            }
            cout << "[\n";
        }

        //the bottom part
        printHorizontalBorder();

        Sleep(20); //delay before the next loop in ms
        system("cls"); //clear the system screen
    }
}

void printHorizontalBorder(){
    for (int i = 1; i <= 11; i++)
        cout << "][";
    cout << endl;
}

void detectBorder(coords location, coords& direction){
    if (location.x == 1)
        direction.x = 1;

    else if (location.x == 20)
        direction.x = -1;

    if (location.y == 1)
        direction.y = 1;

    else if (location.y == 15)
        direction.y = -1;

}
