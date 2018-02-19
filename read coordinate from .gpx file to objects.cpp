#include <iostream>     // cout
#include <sstream>      // stringstream
#include <fstream>      //open file
#include <vector>       //vector

using namespace std;

class Point {     //class for points, stored coordinates and name of point(number)
    private:
    int name_point;
    float x_point, y_point;

    public:

    void enter_x_y(float x, float y, int n){
        x_point = x;
        y_point = y;
        name_point = n;
    }

    void print_x_y(){
        cout<<"Pkt nr: " << name_point <<"  x: " << x_point << " y: " << y_point <<endl;
    }

};


int main()
{
    fstream file;
    file.open("Afternoon_Run.gpx", ios::in); //example file, load for reading
    if(file.good()==false) // if file doesn't exist return -> exit(0);
    {
        cout<<"Plik nie istnieje";
        exit(0);
    }

    string one_line; //one read line from file
    string data[2]; //store for cutting the line
    int how_many_pkt = 0; //how many line with coordinates
    vector <Point> oPkt; //new object for every point
    while(getline(file, one_line)) //read file line, by line
    {
        if (one_line.find("<trkpt") != string::npos) //check, if line have coordinates
        {
            stringstream ss(one_line); //cut line to pieces
            for(int i=0;i<3;i++)
            {
                ss >> data[i]; //save pieces in different places
            }
            oPkt.push_back(Point()); //create new object
            oPkt[how_many_pkt].enter_x_y(stof (data[1].substr(5,10),0), stof (data[2].substr(5,10),0),  how_many_pkt); //data for new object
            how_many_pkt++;
        }

    }
    file.close(); //close file

    for(int i=0; i<int(oPkt.size()); i++)  //print all stored data in objects
    {
        oPkt[i].print_x_y();
    }
    cout << int(oPkt.size()) << endl; //print size of vector
    return 0;
}


