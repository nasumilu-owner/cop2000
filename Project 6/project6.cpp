//Michael Lucas
//COP2000.53
//Project 6 - Rectangle class example

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Simple class that represents a rectangle. 
 */
class Rectangle {

    public:
        /**
         * Constructs a Rectangle with 0.0 length & width
         */
        Rectangle() { this->length = 0.0; this->width = 0.0; }
        
        /**
         * Constructs a Rectangle from the parameters `length` and `width`
         * 
         * @param The length of the Rectangle
         * @param The width of the Rectangle
         */
        Rectangle(double length, double width) { this->length = length; this->width = width; }

        /**
         * This is a very odd class member function. 
         * 
         * The project description did not provide many details, but I think this is the 
         * intention of the lesson, is to teach private, protected, and public
         * members and member functions scope.
         * 
         * It is very odd that the majority of the member function one would think 
         * should be public are private. It really limits this classes overall use. 
         * Again, not a good example of reusable code. 
         */
        void driver(double length = 0.0, double width = 0.0) {
            printf("The rectangle has a length of %0.2f & a width of %0.2f making "
                    "it's perimeter equal to %0.2f and an area of %0.2f.\n", 
                this->length, this->width, this->getPerimeter(), this->getArea());

            this->setLength(length);
            printf("THe length has been set to %0.2f using the private setLength "
                "member function!\n", length);

            this->setWidth(width);
            printf("The width has been set to %0.2f using the private setWidth "
                "member function!\n", width);

             printf("The rectangle now has a length of %0.2f & a width of %0.2f making "
                    "it's perimeter equal to %0.2f and an area of %0.2f.\n", 
                this->length, this->width, this->getPerimeter(), this->getArea());
        }

    private:
        /**
         * Sets the length of the Rectangle
         * 
         * @param The length value
         */
        void setLength(double length) { this->length = length; }

        /**
         * Sets the width of the Rectangle
         * 
         * @param The width value
         */
        void setWidth(double width) { this->width = width; }

        /**
         * Gets the length of the Rectangle
         * 
         * @return The length value
         */
        double getLength() { return this->length; }

        /**
         * Gets the width of the Rectangle
         * 
         * @return The width value
         */
        double getWidth() { return this->width; }

        /**
         * Gets the area of the Rectangle
         * 
         * @return The calculated area as length * width
         */
        double getArea() { return this->width * this->length; }

        /**
         * Gets the perimeter of the Rectangle
         * 
         * @return The perimeter value as (2 * width) + (2 * length)
         */
        double getPerimeter() { return (2 * this->width) + (2 * this->length); }
        
        /**
         * The Rectangle length member
         */
        double length;
        /**
         * The Retangle width member
         */
        double width;

};


int main()
{

    Rectangle r = Rectangle{};

    double length{}, width{};
    cout << "Please enter the rectangles length: ";
    cin >> length;
    cout << "Please enter the rectangles width: ";
    cin >> width;
    
    r.driver(length, width);

    system("PAUSE"); //this is an OS specific command

    //A non-OS specific pause command for non-terminal users.

    //cout << "Enter to exit the program...";
    //cin.ignore().get();

    return 0;

}