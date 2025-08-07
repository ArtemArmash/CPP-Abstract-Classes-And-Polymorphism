#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(const string& filename) const = 0;
    virtual void Load(const string& filename) = 0;
    virtual ~Shape() {}
};

class Point {
public:
    int x, y;
};

class Square : public Shape {
private:
    int topLeftX, topLeftY;
    int sideLength;
public:
    Square(int x, int y, int side) : topLeftX(x), topLeftY(y), sideLength(side) {}

    virtual void Show() const override {
        cout << "Square: Top left corner coordinates (" << topLeftX << ", " << topLeftY
            << "), Side length: " << sideLength << endl;
    }

    virtual void Save(const string& filename) const override {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open()) {
            outFile << "Square " << topLeftX << " " << topLeftY << " " << sideLength << endl;
            outFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    virtual void Load(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            int x, y, side;
            while (inFile >> x >> y >> side) {
                cout << "Loaded Square: Top left corner coordinates (" << x << ", " << y
                    << "), Side length: " << side << endl;
            }
            inFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }
};

class Rectangle : public Shape {
private:
    int topLeftX, topLeftY;
    int width, height;
public:
    Rectangle(int x, int y, int width, int height) : topLeftX(x), topLeftY(y), width(width), height(height) {}

    virtual void Show() const override {
        cout << "Rectangle: Top left corner coordinates (" << topLeftX << ", " << topLeftY
            << "), Width: " << width << ", Height: " << height << endl;
    }

    virtual void Save(const string& filename) const override {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open()) {
            outFile << "Rectangle " << topLeftX << " " << topLeftY << " " << width << " " << height << endl;
            outFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    virtual void Load(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            int x, y, w, h;
            while (inFile >> x >> y >> w >> h) {
                cout << "Loaded Rectangle: Top left corner coordinates (" << x << ", " << y
                    << "), Width: " << w << ", Height: " << h << endl;
            }
            inFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }


};

class Circle : public Shape {
private:
    int centerX, centerY;
    int radius;
public:
    Circle(int centerX, int centerY, int radius) : centerX(centerX), centerY(centerY), radius(radius) {}

    virtual void Show() const override {
        cout << "Circle: Center coordinates (" << centerX << ", " << centerY
            << "), Radius: " << radius << endl;
    }

    virtual void Save(const string& filename) const override {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open()) {
            outFile << "Circle " << centerX << " " << centerY << " " << radius << endl;
            outFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    virtual void Load(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            int x, y, r;
            while (inFile >> x >> y >> r) {
                cout << "Loaded Circle: Center coordinates (" << x << ", " << y
                    << "), Radius: " << r << endl;
            }
            inFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

};

class Ellipse : public Shape {
private:
    int topLeftX, topLeftY;
    int majorAxis, minorAxis;
public:
    Ellipse(int x, int y, int majorAxis, int minorAxis) : topLeftX(x), topLeftY(y), majorAxis(majorAxis), minorAxis(minorAxis) {}

    virtual void Show() const override {
        cout << "Ellipse: Top left corner coordinates (" << topLeftX << ", " << topLeftY
            << "), Major axis: " << majorAxis << ", Minor axis: " << minorAxis << endl;
    }

    virtual void Save(const string& filename) const override {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open()) {
            outFile << "Ellipse " << topLeftX << " " << topLeftY << " " << majorAxis << " " << minorAxis << endl;
            outFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

    virtual void Load(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            int x, y, major, minor;
            while (inFile >> x >> y >> major >> minor) {
                cout << "Loaded Ellipse: Top left corner coordinates (" << x << ", " << y
                    << "), Major axis: " << major << ", Minor axis: " << minor << endl;
            }
            inFile.close();
        }
        else {
            cerr << "Unable to open file: " << filename << endl;
        }
    }

};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Square(0, 0, 5));

    const string filename = "shapes.txt";

    for (auto shape : shapes) {
        shape->Show();
        shape->Save(filename);
    }

    vector<Shape*> loadedShapes;
    Square square(0, 0, 0); 
    loadedShapes.push_back(&square);

    for (auto loadedShape : loadedShapes) {
        loadedShape->Load(filename);
    }

    for (auto shape : shapes) {
        delete shape;
    }

}
