#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Video_lib {
    string name;
    float cost;
    string director;
};

ostream& operator<<(ostream& out, Video_lib& data);

class functor {
    string dir;
    list<Video_lib> ldir;
public:
    functor(string dir) {
        this->dir = dir;
        this->ldir = {};
    }
    void operator()(Video_lib& elem) {
        if (elem.director == dir) {
            ldir.push_back(elem);
            cout << elem;
        }
    }
};

istream& operator>>(istream& in, Video_lib& data) {
    cout << "Введите название, стоимость и режиссера\n";
    in >> data.name >> data.cost >> data.director;
    return in;
}

ostream& operator<<(ostream& out, Video_lib& data) {
    cout << "\nназвание "; out << data.name;
    cout << "\nстоимость "; out << data.cost;
    cout << "\nрежиссер "; out << data.director;
    cout << endl;
    return out;
}

list<Video_lib> v_lib_input(list<Video_lib> vl, int n) {
    cout << "введите фильмы для видеотеки\n";
    Video_lib temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vl.push_back(temp);
    }
    return vl;
}

void v_lib_output(list<Video_lib>& vl) {
    //list<Video_lib>::iterator it = vl.begin();
    for (list<Video_lib>::iterator it = vl.begin(); it != vl.end(); it++)
        cout << *it;
}

void v_lib_get_directors(list<Video_lib>& vl, int random) {
    list<Video_lib>::iterator it = vl.begin();
    advance(it, random);
    string dir = it->director;
    functor is_same_director(dir);
    cout << "все найденные фильмы режиссера " << dir;
    is_same_director = for_each(vl.begin(), vl.end(), is_same_director);
}

int main() {
    setlocale(LC_ALL, "Russian");
    list<Video_lib> vl;
    cout << "введите кол-во фильмов\n";
    int n; cin >> n;
    vl = v_lib_input(vl, n);
    cout << "картотека видеотеки\n";
    //v_lib_output(vl);

    int r = rand() % (n - 1);
    v_lib_get_directors(vl, r);
}