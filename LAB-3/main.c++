#include <iostream>
using namespace std;

struct song{
    string title;
    string singer;
    int ratings[3];
    song *next;
    song *prev;
};
song* head = nullptr;
song* tail = nullptr;
song* current = nullptr;

void addsong(string t, string a, int r1, int r2, int r3){
    song* newsong = new song;
    newsong->title = t;
    newsong->singer = a;
    newsong->ratings[0]=r1;
    newsong->ratings[1]=r2;
    newsong->ratings[2]=r3;
    newsong->next = nullptr;
    newsong->prev = nullptr;

    if(head==nullptr){
        head=newsong;
        tail=newsong;
        current=newsong;
    }else{
        tail->next=newsong;
        newsong->prev=tail;
        tail=newsong;
    }
    cout << "Eklendi: " << t << endl;
}
void nextsong(){
    if(current != nullptr && current->next != nullptr){
        current = current->next;
    }
}
void deletecurrent(){
    if(current == nullptr) return;
    song* todelete=current;

    if(todelete->prev != nullptr){
        todelete->prev->next = todelete->next;
    }else{
        head = todelete->next;
    }
    if (todelete->next != nullptr) {
        todelete->next->prev = todelete->prev;
    } else {
        tail = todelete->prev;
    }
    if (todelete->next != nullptr) {
        current = todelete->next;
    } else {
        current = todelete->prev;
    }
    delete todelete;
    cout << "Sarki silindi." << endl;
}
void display(){
    if (head == nullptr) {
        cout << "Playlist is empty!" << endl;
        return;
    }
    cout << "\n--- PLAYLIST ---" << endl;
    song* temp = head;
    while (temp != nullptr) {
        if (temp == current) cout << "-> ";
        else cout << "   ";

        cout << temp->title << " (" << temp->singer << ") [Ratings: ";
        for (int i = 0; i < 3; i++) {
            cout << temp->ratings[i] << (i < 2 ? ", " : "");
        }
        cout << "]" << endl;

        temp = temp->next;
    }
    cout << "----------------\n" << endl;
}

int main() {
    addsong("Hadise", "Dum Tek Tek", 7, 9, 10);
    addsong("Mustafa Sandal", "Tesir Altinda", 8, 6, 9);
    addsong("Murat Boz", "Adini Bilen Yazsin", 9, 8, 10);

    display();

    nextsong();
    display();

    deletecurrent();
    display();

    return 0;
}
